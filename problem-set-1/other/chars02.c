#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() 
{
    int MAX_LEN = 256;
    char c, str[MAX_LEN], sen[MAX_LEN];
    scanf("%c", &c);

    scanf("%s ", str);
    scanf("%[^\n]%*c", sen);

    printf("%c\n%s\n%s", c, str, sen);

        return 0;
}