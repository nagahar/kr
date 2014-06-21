#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define ALPHA 26 
#define MAXLINE 100

double var[ALPHA];
double hist;

int getop(char [], char []);
void push(double);
double pop(void);
double watch(void);
void replace(void);
int getline(char [], int);

main()
{
	int type;
	double op1,op2;
	char s[MAXOP];
	char buf[MAXLINE];

	while(getline(buf,MAXLINE)>0){
		while((type=getop(buf,s)) > 0){
			switch (type) {
				case NUMBER:
					push(atof(s));
					break;
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					op2 = pop();
					if(op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: zero divisor\n");
					break;
				case '%':
					op2 = pop();
					if(op2 != 0.0)
						push((int)pop() % (int)op2);
					else
						printf("error: zero divisor\n");
					break;
				case 'w':
					hist=watch();
					printf("\t%.8g\n",hist);
					break;
				case 'd':
					push(watch());
					break;
				case 'r':
					replace();
					break;
				case 's':
					push(sin(pop()));
					break;
				case 'e':
					push(exp(pop()));
					break;
				case 'p':
					op1 = pop();
					op2 = pop();
					if(op2==0 && op1<=0) 
						printf("error: over field\n");
					else if(op2<0){
						op1=(int)op1;
						push(pow(op2,op1));
					}else 
						push(pow(op2,op1));
					break;
				case 'v':
					type=lower(getop(buf,s));
					if(type >= 'a' && type <= 'z')
						var[type-'a']=pop();
					break;
				case '$':
					type=lower(getop(buf,s));
					if(type=='@')
						push(hist);
					else if(type >= 'a' && type <= 'z')
						push(var[type-'a']);
					else
						printf("error: no variable name\n");
					break;
				case '\n':
					printf("\t%.8g\n",pop());
					break;
				default:
					printf("error: unknown command %s\n", s);
					break;
			}
		}
	}
	return 0;
}

#define MAXVAL 100

int sp=0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++]=f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}

}

double watch(void)
{
	double d;
	if(sp > 0){
		d=val[sp-1];
		return d;
	}else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void replace()
{
	double a,b;
	a=pop();
	b=pop();
	push(a);
	push(b);
}

#include <ctype.h>
int index;

int getop(char buf[], char s[])
{
	int i,j, c, tmp;
	fprintf(stderr,"getopstart\n",s);
	i=0;
	if((j=index)>=strlen(buf)){
		index=0;
		return 0;
	}
	while((s[0]=c=buf[j++])==' ' || c=='\t')
		;
	s[1]='\0';
	fprintf(stderr,"s:%s\n",s);
	if(c == '-') {
		if(isdigit(tmp=buf[j+1])){
			/* negative number */
			s[++i]=c=tmp;
		}else{
			/* negative operator */
			index=j;
			return c;
		}
	}else{
		if(!isdigit(c) && c != '.'){
			/* operator */
			printf("c:%d\n",c);
			index=j;
			return c;
		}
	}
	if(isdigit(c))
		while(isdigit(s[++i]=c=buf[j++]))
			;
	if(c == '.')
		while(isdigit(s[++i]=c=buf[j++]))
			;
	s[i]='\0';
	index=j;
	return NUMBER;
}
