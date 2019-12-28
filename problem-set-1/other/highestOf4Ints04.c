#include <stdio.h>

int max_of_four(int a, int b, int c, int d) 
{
    int highest = a;
    if( highest < b )
    {
        highest = b;
    }
    if ( highest < c)
    {
        highest = c;
    }
    if (highest < d)
    {
        highest = d;
    }
    return highest;

}   

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
