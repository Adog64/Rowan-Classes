#include <stdio.h>

float average(int a, int b, int c)
{
	return (a + b + c) / 3.0;
}

int main()
{
	printf("%4.3f\n", average(4, 5, 6));
	return 0;
}
