#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

void test_case(const char *desc, const char *format, ...)
{
	va_list args1, args2;
	int ret1, ret2;
	
	va_start(args1, format);
	va_start(args2, format);
	
	printf("\n[TEST: %s]\n", desc);
	printf("printf:    ");
	ret1 = vprintf(format, args1);
	printf(" [ret=%d]\n", ret1);
	
	printf("ft_printf: ");
	ret2 = vprintf(format, args2);
	printf(" [ret=%d]\n", ret2);
	
	va_end(args1);
	va_end(args2);
	
	if (ret1 == ret2)
		printf("✓ PASS\n");
	else
		printf("✗ FAIL (printf=%d, ft_printf=%d)\n", ret1, ret2);
}

void run_actual_test(const char *desc, const char *format, ...)
{
	va_list args1, args2;
	int ret1, ret2;
	
	va_start(args1, format);
	va_start(args2, format);
	
	printf("\n[TEST: %s]\n", desc);
	printf("printf:    ");
	ret1 = vprintf(format, args1);
	printf(" [ret=%d]\n", ret1);
	
	printf("ft_printf: ");
	ret2 = ft_printf(format);
	printf(" [ret=%d]\n", ret2);
	
	va_end(args1);
	va_end(args2);
	
	if (ret1 == ret2)
		printf("✓ PASS\n");
	else
		printf("✗ FAIL (printf=%d, ft_printf=%d)\n", ret1, ret2);
}

int main()
{
	printf("========================================\n");
	printf("       ft_printf Test Suite\n");
	printf("========================================\n");
	
	// Character tests
	int ret_std, ret_ft;
	
	printf("\n[TEST: Character %%c]\n");
	printf("printf:    ");
	ret_std = printf("Char: %c", 'A');
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Char: %c", 'A');
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// String tests
	printf("\n[TEST: String %%s]\n");
	printf("printf:    ");
	ret_std = printf("String: %s", "Hello");
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("String: %s", "Hello");
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// NULL string
	printf("\n[TEST: NULL String]\n");
	printf("printf:    ");
	ret_std = printf("NULL: %s", (char *)NULL);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("NULL: %s", (char *)NULL);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// Integer tests
	printf("\n[TEST: Integer %%d]\n");
	printf("printf:    ");
	ret_std = printf("Int: %d", 42);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Int: %d", 42);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	printf("\n[TEST: Negative int]\n");
	printf("printf:    ");
	ret_std = printf("Neg: %d", -42);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Neg: %d", -42);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	printf("\n[TEST: INT_MIN]\n");
	printf("printf:    ");
	ret_std = printf("Min: %d", INT_MIN);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Min: %d", INT_MIN);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	printf("\n[TEST: INT_MAX]\n");
	printf("printf:    ");
	ret_std = printf("Max: %d", INT_MAX);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Max: %d", INT_MAX);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// Unsigned tests
	printf("\n[TEST: Unsigned %%u]\n");
	printf("printf:    ");
	ret_std = printf("Unsigned: %u", 42U);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Unsigned: %u", 42U);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	printf("\n[TEST: UINT_MAX]\n");
	printf("printf:    ");
	ret_std = printf("UMax: %u", UINT_MAX);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("UMax: %u", UINT_MAX);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// Hex tests
	printf("\n[TEST: Hex lowercase %%x]\n");
	printf("printf:    ");
	ret_std = printf("Hex: %x", 255);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Hex: %x", 255);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	printf("\n[TEST: Hex uppercase %%X]\n");
	printf("printf:    ");
	ret_std = printf("HEX: %X", 255);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("HEX: %X", 255);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// Pointer tests
	printf("\n[TEST: Pointer %%p]\n");
	int x = 42;
	printf("printf:    ");
	ret_std = printf("Ptr: %p", (void *)&x);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Ptr: %p", (void *)&x);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	printf("\n[TEST: NULL Pointer]\n");
	printf("printf:    ");
	ret_std = printf("NullPtr: %p", (void *)NULL);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("NullPtr: %p", (void *)NULL);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// Percent test
	printf("\n[TEST: Percent %%%%]\n");
	printf("printf:    ");
	ret_std = printf("Percent: %%");
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Percent: %%");
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// Invalid specifier test
	printf("\n[TEST: Invalid specifier %%v]\n");
	printf("printf:    ");
	ret_std = printf("Invalid: %v", 42);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Invalid: %v", 42);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	// Mixed test
	printf("\n[TEST: Mixed formats]\n");
	printf("printf:    ");
	ret_std = printf("Mix: %c %s %d %u %x %p %%", 'A', "test", -42, 100U, 255, (void *)&x);
	printf(" [ret=%d]\n", ret_std);
	printf("ft_printf: ");
	ret_ft = ft_printf("Mix: %c %s %d %u %x %p %%", 'A', "test", -42, 100U, 255, (void *)&x);
	printf(" [ret=%d]\n", ret_ft);
	printf("%s\n", (ret_std == ret_ft) ? "✓ PASS" : "✗ FAIL");
	
	printf("\n========================================\n");
	printf("       Test Suite Complete\n");
	printf("========================================\n");
	
	return (0);
}
