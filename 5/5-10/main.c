#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char *);
void push(double);
double pop(void);

main(int argc, char *argv[])
{
	int type;
	double op2;
	int i;

	if(argc < 2){
		printf("Usage: expr [number]... [operator]...\n");
		return 0;
	}

	while(--argc > 0)
		switch(type=getop(*++argv)){
			case NUMBER:
				push(atof(*argv));
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
			default:
				printf("error: unknown command %s\n", *argv);
				break;
		}
		printf("\t%.8g\n",pop());
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

#include <ctype.h>

int getop(char *arg)
{
	if(*arg == '-'){
		if(!isdigit(*(arg+1))){
			return *arg;
		}else{
			*arg++;
		}
	}else if(!isdigit(*arg) && *arg != '.')
		return *arg;
	if(isdigit(*arg))
		while(isdigit(*++arg))
			;
	if(*arg == '.')
		while(isdigit(*++arg))
			;
	return NUMBER;
}
