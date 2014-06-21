#define NUMBER '0'
#define ALPHA 26 

double var[ALPHA];
double hist;

int getop(char []);
void push(double);
double pop(void);
double watch(void);
void replace(void);

int getch(void);
void ungetch(int);
