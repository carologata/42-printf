#include "ft_printf_bonus.h"
#include <stdio.h>

int main(void)
{
    int count;
    //#
/*     ft_printf("1 ft_printf: %#x \n", 0);
    printf("1 printf: %#x \n", 0);

    ft_printf("2 ft_printf: %#x \n", 5);
    printf("2 printf: %#x \n", 5);

    ft_printf("3 ft_printf: %#x \n", -5);
    printf("3 printf: %#x \n", -5);

    ft_printf("4 ft_printf: %#X \n", 0);
    printf("4 printf: %#X \n", 0);

    ft_printf("5 ft_printf: %#X \n", 5);
    printf("5 printf: %#X \n", 5);

    ft_printf("6 ft_printf: %#X \n", -5);
    printf("6 printf: %#X \n", -5); */


    //Space
	printf("1 % s\n", "");
    ft_printf("1 % s\n", "");
    
	count = printf("2 % 1s\n", "");
    printf("count: %d\n", count);
	count = ft_printf("2 % 1s\n", "");
    printf("count: %d\n\n", count);

	count = printf("2 % 1s \n", "");
    printf("count: %d\n", count);
	count = ft_printf("2 % 1s \n", "");
    printf("count: %d\n\n", count);

	printf("4 % s \n", "");
	ft_printf("4 % s \n", "");

	printf("5 % s \n","-");
	ft_printf("5 % s \n", "-");

	printf("6 % s % s \n", "", "-");
	ft_printf("6 % s % s \n", "", "-");

	printf("7 % s % s \n", " - ", "");
	ft_printf("7 % s % s \n", " - ", "");

	printf("8 % s % s % s % s \n", " - ", "", "4", "");
	ft_printf("8 % s % s % s % s \n", " - ", "", "4", "");

	printf("9 % s % s % s % s % s \n", " - ", "", "4", "", "2 ");
	ft_printf("9 % s % s % s % s % s \n", " - ", "", "4", "", "2 ");

	count = printf("10 % 1s \n", "a");
    printf("count: %d\n", count);
	count = ft_printf("10 % 1s \n", "a");
    printf("count: %d\n\n", count);

    count = printf("11% s\n", "a");
    printf("count: %d\n", count);
	count = ft_printf("11% s\n", "a");
    printf("count: %d\n\n", count);

    printf("12 % d \n", 0);
    ft_printf("12 % d \n", 0);

    //Test 13: %j - an invalid argument
	//compile with -w
	printf("\nTest13\n");
    count = ft_printf("f%jk\n", 5);
	printf("ft_printf count = %d\n\n", count);
	count = printf("f%jk\n", 5);
	printf("printf count = %d\n\n\n", count);

    count = ft_printf("14 %    d\n", 0);
    printf("ft_printf count = %d\n\n", count);
    count = printf("14 %    d\n", 0);
    printf("ft_printf count = %d\n\n", count);

    count = ft_printf("14 %    +d\n", 0);
    printf("ft_printf count = %d\n\n", count);
    count = printf("14 %    +d\n", 0);
    printf("ft_printf count = %d\n\n", count);
}