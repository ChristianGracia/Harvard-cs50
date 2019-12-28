#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float c, d;

	scanf("%d", &a);
    scanf("%d", &b);

    printf("%d", a + b);
    printf(" %d\n", a - b);

    scanf("%f", &c);
    scanf("%f", &d);

    printf("%.1f", c+d);
    printf(" %.1f", c-d);

    
    return 0;
}