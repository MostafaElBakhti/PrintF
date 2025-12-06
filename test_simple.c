#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int ret1, ret2;
    
    printf("=== Simple Individual Tests ===\n\n");
    
    // Test 1: Single negative number
    printf("Test 1: Single negative number\n");
    ret1 = ft_printf("ft: %d\n", -42);
    ret2 = printf("pr: %d\n", -42);
    printf("Returns: ft=%d, printf=%d\n\n", ret1, ret2);
    
    // Test 2: Two numbers
    printf("Test 2: Two numbers\n");
    ret1 = ft_printf("ft: %d %d\n", 42, -42);
    ret2 = printf("pr: %d %d\n", 42, -42);
    printf("Returns: ft=%d, printf=%d\n\n", ret1, ret2);
    
    // Test 3: Three numbers
    printf("Test 3: Three numbers\n");
    ret1 = ft_printf("ft: %i %d %i\n", 10, 20, 30);
    ret2 = printf("pr: %i %d %i\n", 10, 20, 30);
    printf("Returns: ft=%d, printf=%d\n\n", ret1, ret2);
    
    // Test 4: Max int
    printf("Test 4: Max int\n");
    ret1 = ft_printf("ft: %d\n", 2147483647);
    ret2 = printf("pr: %d\n", 2147483647);
    printf("Returns: ft=%d, printf=%d\n\n", ret1, ret2);
    
    // Test 5: Min int
    printf("Test 5: Min int\n");
    ret1 = ft_printf("ft: %d\n", (int)-2147483648);
    ret2 = printf("pr: %d\n", (int)-2147483648);
    printf("Returns: ft=%d, printf=%d\n\n", ret1, ret2);
    
    return 0;
}
