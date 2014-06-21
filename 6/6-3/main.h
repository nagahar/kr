#define MAXWORD 100
struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
	struct rowlist *begin;
	struct rowlist *last;
};

struct rowlist{
	int row;
	struct rowlist *next;
};
