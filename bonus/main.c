#include "ft_printf_bonus.h"
#include <stdio.h>

// space: Print a space before a positive value not printed with the + flag.

// #: Prefix 0 to the output value when used with the octal conversion character o.
// Prefix 0x to the output value when used with the hexadecimal conversion character x

//+: Display a plus sign preceding positive values and a minus sign preceding negative values.

int main(void)
{
    // char *str = "Hello";
    // int positive = 5;
    // int negative = -5;

    // int hex = 456;
    // char c = 'a';

/*     //space
    printf("->% s\n", str);
    
    printf("->% x\n", hex);
    printf("->% X\n", hex);

    printf("->% d\n", positive);
    printf("->% d\n", negative);

    printf("->% i\n", positive);
    printf("->% i\n", negative); */

/*     //#
    printf("->%#s\n", str);
    
    printf("->%#x\n", hex);
    printf("->%#X\n", hex);

    printf("->%#d\n", positive);
    printf("->%#d\n", negative);

    printf("->%#i\n", positive);
    printf("->%#i\n", negative); */

/*     //+
    printf("->%+s\n", str);
    
    printf("->%+x\n", hex);
    printf("->%+X\n", hex);

    printf("->%+d\n", positive);
    printf("->%+d\n", negative);

    printf("->%+i\n", positive);
    printf("->%+i\n", negative);  */ 

    //Tests
    //printf("->%#4i\n");
    //printf("->%# 4i\n");

    // ft_printf("->%#x\n", 456);
    // printf("->%#x\n", 456);

    ft_printf("->% d\n", 456);
    printf("->% d\n", 456);

    ft_printf("->% d\n", -456);
    printf("->% d\n", -456);


    ft_printf("->%+d\n", 456);
    printf("->%+d\n", 456);

    ft_printf("->%+d\n", -456);
    printf("->%+d\n", -456);
}