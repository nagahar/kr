#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

int getline(char*, int);
void push(double);
double pop(void);
double watch(void);
void replace(void);

int main()
{
	char type;
	double op1,op2;
	double dval;
	char line[MAXLINE],*p;

	while(getline(line,sizeof(line))>0){
		p=line;
		while(*p!='\0'){
			if(sscanf(p,"%lf",&dval)==1){
				push(dval);
				while(!isspace(*++p))
					;
			}else if(sscanf(p,"%1s",&type)==1){
				switch (type) {
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
					default:
						printf("error: unknown command %s\n", line);
						return -1;
				}
				while(!isspace(*++p))
					;
				if(*p++=='\n')
					printf("\t%.8g\n",pop());
			}else
				p++;
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
		printf("pop error: stack empty\n");
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
		printf("watch error: stack empty\n");
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

