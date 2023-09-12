#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    //////// BONUS //////////
	int count;

	count = 0;

	printf("Test1 BONUS\n");
	count = printf("%x\n\n", 456);
	printf("count: %d", count);
	count = ft_printf("%x\n\n", 456);
	printf("%d", count);

    printf("Test2 BONUS\n");
	count = printf("% d\n", 23);
	printf("count: %d\n", count);
	count = ft_printf("% d\n", 23);
	printf("count: %d\n", count);

    printf("Test3 BONUS\n");
	count = printf("%+d\n", 23);
	printf("count: %d\n", count);
	count = ft_printf("%+d\n", 23);
	printf("count: %d\n", count);
}