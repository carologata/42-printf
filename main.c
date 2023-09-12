
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char ch = 'A';
	char *str = "Caroline";
	int i = 456;
	int j = -5;
	unsigned int u = 5;
    int count;

    count = 0;

	//Test 1: c, s, d, i
	printf("Test1\n");
	count = ft_printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
	printf("ft_printf count = %d\n\n", count);
	count = printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
    printf("printf count = %d\n\n\n", count);

	//Test 2: p
	printf("Test2\n");
    count = ft_printf("p: %p\n", str);
	printf("ft_printf count = %d\n\n", count);  
	count = printf("p: %p\n", str);
	printf("printf count = %d\n\n\n", count);  

	//Test 3: u
	printf("Test3\n");
    count = ft_printf("unsigned: %u\n", u);
	printf("ft_printf count = %d\n\n", count);
	count = printf("unsigned: %u\n", u);
	printf("printf count = %d\n\n\n", count);

	//Test 4: u but sending negative int
	printf("Test4\n");
    count = ft_printf("unsigned: %u\n", j);
	printf("ft_printf count = %d\n\n", count);
	count = printf("unsigned: %u\n", j);
	printf("printf count = %d\n\n\n", count);

	//Test 5: x
	printf("Test5\n");
	count = ft_printf("hex: %x\n", i);
	printf("ft_printf count = %d\n\n", count);
	ft_printf("hex: %x\n", i);
	printf("printf count = %d\n\n\n", count);

	//Test 6: X
	printf("Test6\n");
	count = ft_printf("hex: %X\n", i);
	printf("ft_printf count = %d\n\n", count);
	ft_printf("hex: %X\n", i);
	printf("printf count = %d\n\n\n", count);

	//Test 7: %%
	printf("Test7\n");
	count = ft_printf("percentage %%\n");
	printf("ft_printf count = %d\n\n", count);
	count = printf("percentage %%\n");
	printf("printf count = %d\n\n\n", count);

	//Test 8: %j - an invalid argument
	//compile with -w
	printf("Test8\n");
    count = ft_printf("f%jk\n", i);
	printf("ft_printf count = %d\n\n", count);
	count = printf("f%jk\n", i);
	printf("printf count = %d\n\n\n", count);

	//Test 9: s (null)
	//compile with -w
	//(null)
	//NULL is used to represent a null pointer,
	//a pointer that doesn't point to a valid memory address.
	//(void*)0)
	printf("Test9\n");
	count = ft_printf(" NULL %s NULL\n", NULL);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" NULL %s NULL\n", NULL);
	printf("printf count = %d\n\n\n", count);

	//Test 10: s (sending 0)
	//compile with -w
	printf("Test10\n");
	count = ft_printf(" NULL %s NULL\n", 0);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" NULL %s NULL\n", 0);
	printf("printf count = %d\n\n\n", count);
	
	//Test 11: p (long address)
	//compile with -w
	//(long) LONG_MAX: 2147483647  LONG_MIN: -2147483648 
	printf("Test11\n");
	count = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf("printf count = %d\n\n\n", count);
	
	//Test 12: p (unsigned long address)
	//compile with -w
	//(unsigned long) 4294967295
	printf("Test12\n");
	count = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("printf count = %d\n\n\n", count);

	//Test 13: p (nil) (sending 0)
	//compile with -w
	//(nil) why not (null)????
	//In Objective-C (another language), nil is a pointer to a non-existent object
	//The use of (nil) to represent a null pointer is more common in languages like Objective-C, 
	//where (nil) is a literal to represent a null reference to an object.
	printf("Test13\n");
	count = ft_printf(" %p %p \n", 0, 0);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %p %p \n", 0, 0);
	printf("printf count = %d\n\n\n", count);

	//Test 14: hex (sending 0)
	printf("Test14\n");
	count = ft_printf(" %x %x \n", 0, 0);
	printf("ft_printf count = %d\n\n", count);
	count = printf(" %x %x \n", 0, 0);
	printf("printf count = %d\n\n\n", count);

	//Test 15: with no arguments
	//compile with -w
	//undefined behavior because printf will attempt to access arguments 
	//that do not exist or do not match the format specifiers.
	printf("Test15\n");
	count = ft_printf("Oi %d Olá\n");
	printf("ft_printf count = %d\n\n", count);
	count = printf("Oi %d Olá\n");
	printf("printf count = %d\n\n\n", count);

	//Test 16
	//undefined behavior, it can lead to seg fault, crash, depending the compiler
	printf("Test16\n");
	count = printf(NULL);
	printf("printf count = %d\n\n", count);
	count = ft_printf(NULL);
	printf("ft_printf count = %d\n\n\n", count);

	//Test 17
	printf("Test17\n");
	count = printf("%s\n", "");
	printf("printf count = %d\n\n", count);
	count = ft_printf("%s\n", "");
	printf("ft_printf count = %d\n\n\n", count);

}