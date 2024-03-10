#include <stdio.h>
int foo();
int foo(a, b, c)
int a;
int b;
float c;
{
	printf("k&r c\n");
	printf("sizeof(a): %lu\n", sizeof(a));
	printf("sizeof(c): %lu\n", sizeof(c));
	return 0;
}
int main() {
	printf("\"%c\"\n", 2);
	printf("char to int\n");
	float cc = 1;
	(void) foo('a', '1', cc);
	double c = 1;
	(void) foo('a', '1', c);
/*
	printf("%d\n", '1');
	printf("%d\n", 'A');
	printf("%d\n", 'a');
*/
	printf("%lu\n", sizeof ('1' + 'A'));
	printf("%lu\n", sizeof ('a' - 'A'));
	printf("\nfloat to double\n");
	float f1=1.0, f2 = 2.0;
	double d = 10;
	printf("%lu\n", sizeof(f1*f2));
	printf("%lu\n", sizeof(f1*d));
	printf("%lu\n", sizeof(0.5*0.1f));
	printf("%lu\n", sizeof(double));

	printf("%0x\n", 3);
	printf("%0x\n", (float)3);
	printf("%0x\n", (float)3.0);
}
