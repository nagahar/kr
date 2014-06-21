#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

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
				type=lower(getop(s));
				if(type >= 'a' && type <= 'z')
					var[type-'a']=pop();
				break;
			case '$':
				type=lower(getop(s));
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
	return 0;
}

