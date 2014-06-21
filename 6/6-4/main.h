#define MAXWORD 100
#define MAXNODE 10000

struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};
