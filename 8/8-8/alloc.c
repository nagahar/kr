#include <stdio.h>
#define NALLOC 1024

typedef long Align;

union header{
	struct {
		union header *ptr;
		unsigned size;
	}s;
	Align x;
};

typedef union header Header;

static Header base;
static Header *freep=NULL;

void *malloc(unsigned);
void *calloc(unsigned,unsigned);
void free(void *);
static Header *morecore(unsigned);

void *malloc(unsigned nbytes)
{
	Header *p, *prevp;
	Header *morecore(unsigned);
	unsigned nunits;

	if(!nbytes)
		return NULL;

	nunits=(nbytes+sizeof(Header)-1)/sizeof(Header)+1;
	if((prevp=freep)==NULL){
		base.s.ptr=freep=prevp=&base;
		base.s.size=0;
	}
	for(p=prevp->s.ptr; ;prevp=p,p=p->s.ptr){
		if(p->s.size >= nunits){
			if(p->s.size==nunits)
				prevp->s.ptr=p->s.ptr;
			else{
				p->s.size-=nunits;
				p+=p->s.size;
				p->s.size=nunits;
			}
			freep=prevp;
			return (void *)(p+1);
		}
		if(p==freep)
			if((p=morecore(nunits))==NULL)
				return NULL;
	}
}

void *calloc(unsigned n, unsigned nbytes)
{
	void *p;
	char *cp;
	int i;
	void *malloc(unsigned);

	if((p=malloc(nbytes*n))==NULL)
		return NULL;

	for(cp=(char *)p,i=0; i<nbytes*n ;i++,cp++)
		*cp=0;

	return (void *)p;
}

static Header *morecore(unsigned nu)
{
	char *cp,*sbrk(int);
	Header *up;

	if(nu<NALLOC)
		nu=NALLOC;
	cp=sbrk(nu*sizeof(Header));
	if(cp==(char *)-1)
		return NULL;
	up=(Header *)cp;
	up->s.size=nu;
	free((void *)(up+1));
	return freep;
}

void free(void *ap)
{
	Header *bp,*p;

	bp=(Header *)ap-1;

	if(!bp->s.size)
		return;

	for(p=freep; !(bp>p && bp < p->s.ptr);p=p->s.ptr)
		if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;

	if(bp+bp->s.size==p->s.ptr){
		bp->s.size+=p->s.ptr->s.size;
		bp->s.ptr=p->s.ptr->s.ptr;
	}else
		bp->s.ptr=p->s.ptr;

	if(p+p->s.size==bp){
		p->s.size+=bp->s.size;
		p->s.ptr=bp->s.ptr;
	}else
		p->s.ptr=bp;

	freep=p;
}

void bfree(void *p,unsigned nbytes)
{
	Header *bp;
	unsigned nunits;

	nunits=(nbytes+sizeof(Header)-1)/sizeof(Header)+1;
	printf("Header %d:nunits %d\n",sizeof(Header),nunits);

	bp=(Header*)p;
	bp->s.size=nunits;
	free((void*)(bp+1));
}
