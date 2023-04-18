#include <stdio.h>
#define PI 3.141593

float circleArea(float radius);

int main()
{
	float radius = 5;
	printf("Area of circle with radius %4.3f is %4.3f\n", radius, circleArea(radius));
	return 0;
}

float circleArea(float radius)
{
	return PI * radius * radius;
}
