#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double watch(void);
void replace(void);

main()
{
	int type;
	double op1,op2;
	char s[MAXOP];
	
	while((type=getop(s)) != EOF){
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
				printf("\t%.8g\n",watch());
				break;
			case 'd':
				push(watch());
				break;
			case 'r':
				replace();
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
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
int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c, tmp;
	i=0;
	while((s[0]=c=getch())==' ' || c=='\t')
		;
	s[1]='\0';
	if(c == '-') {
		if(isdigit(tmp=getch())){
			/* negative number */
			s[++i]=c=tmp;
		}else{
			/* negative operator */
			ungetch(tmp);
			return c;
		}
	}else{
		if(!isdigit(c) && c != '.'){
			/* operator */
			return c;
		}
	}
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()))
			;
	if(c == '.')
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}
