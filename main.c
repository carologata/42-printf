
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char ch = 'A';
	char *str;
	int i;
	i = 456;
	float percentage;
	int percentage2;
    int count;

    count = 0;

	str = malloc(6);
	str[0] = 'C';
	str[1] = 'a',
	str[2] = 'r';
	str[3] = 'o';
	str[4] = 'l';
	str[5] = '\0';


	percentage = 1.58;
	percentage2 = 5;

    count = ft_printf("p: %p\n", str);
	printf("p: %p\n", str);
	printf("count = %d\n\n", count);
	//p: 0xa8c2a0n		12

    count = ft_printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
	printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
    printf("count = %d\n\n", count);
	//Oi, tudo bem Carol? Sua sala e 7A. Agora sao 456h 456h.n		56

    count = ft_printf("unsigned: %u\n", i);
	printf("unsigned: %u\n", i);
	printf("count = %d\n\n", count);
	//unsigned: 456n		14

	count = ft_printf("hex: %x\n", i);
	ft_printf("hex: %x\n", i);
	printf("count = %d\n\n", count);
	//hex: 1c8n		9

	count = ft_printf("percentage %%\n");
	printf("percentage %%\n");
	printf("count = %d\n\n", count);
	//percentage %n		13

	//compile with -w
    count = ft_printf("f%jk\n", i);
	printf("f%jk\n", i);
	printf("count = %d\n\n", count);
	//f%k	4

	printf(" NULL %s NULL\n", NULL);
	ft_printf(" NULL %s NULL\n\n", NULL);

	printf(" %p %p \n", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p \n\n", LONG_MIN, LONG_MAX);
	
	printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %p %p \n\n", ULONG_MAX, -ULONG_MAX);

	printf(" %p %p \n", 0, 0);
	ft_printf(" %p %p \n\n", 0, 0);
}