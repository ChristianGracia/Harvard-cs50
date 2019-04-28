//program checks if inputted credit card value is valid
#include <stdio.h>
#include <cs50.h>

int main(void){
    long credit = get_long("Enter Credit Card Number: ");
    printf("\n%li", credit);
    
}