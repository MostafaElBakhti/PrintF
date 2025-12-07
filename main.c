#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

void print_test_header(const char *test_name)
{
    printf("\n" YELLOW "=== %s ===" RESET "\n", test_name);
}

void compare_results(int ft_ret, int printf_ret, const char *description)
{
    if (ft_ret == printf_ret)
        printf(GREEN "✓ PASS" RESET " - %s (returned: %d)\n", description, ft_ret);
    else
        printf(RED "✗ FAIL" RESET " - %s (ft_printf: %d, printf: %d)\n", 
               description, ft_ret, printf_ret);
}

int main(void)
{
    int ft_ret;
    int printf_ret;
    
    printf(YELLOW "╔════════════════════════════════════════╗\n");
    printf("║     FT_PRINTF COMPREHENSIVE TESTS     ║\n");
    printf("╚════════════════════════════════════════╝" RESET "\n");

    // ========== CHARACTER TESTS (%c) ==========
    print_test_header("CHARACTER TESTS (%c)");
    
    printf("\nft_printf: ");
    ft_ret = ft_printf("Char: %c\n", 'A');
    printf("printf:    ");
    printf_ret = printf("Char: %c\n", 'A');
    compare_results(ft_ret, printf_ret, "Simple character");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Multiple: %c %c %c\n", 'X', 'Y', 'Z');
    printf("printf:    ");
    printf_ret = printf("Multiple: %c %c %c\n", 'X', 'Y', 'Z');
    compare_results(ft_ret, printf_ret, "Multiple characters");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Null char: %c\n", '\0');
    printf("printf:    ");
    printf_ret = printf("Null char: %c\n", '\0');
    compare_results(ft_ret, printf_ret, "Null character");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Special: %c %c %c\n", '\n', '\t', ' ');
    printf("printf:    ");
    printf_ret = printf("Special: %c %c %c\n", '\n', '\t', ' ');
    compare_results(ft_ret, printf_ret, "Special characters");

    // ========== STRING TESTS (%s) ==========
    print_test_header("STRING TESTS (%s)");

    printf("\nft_printf: ");
    ft_ret = ft_printf("String: %s\n", "Hello, World!");
    printf("printf:    ");
    printf_ret = printf("String: %s\n", "Hello, World!");
    compare_results(ft_ret, printf_ret, "Simple string");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Empty: %s\n", "");
    printf("printf:    ");
    printf_ret = printf("Empty: %s\n", "");
    compare_results(ft_ret, printf_ret, "Empty string");

    printf("\nft_printf: ");
    ft_ret = ft_printf("NULL: %s\n", NULL);
    printf("printf:    ");
    printf_ret = printf("NULL: %s\n", (char *)NULL);
    compare_results(ft_ret, printf_ret, "NULL string");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Multiple: %s %s %s\n", "one", "two", "three");
    printf("printf:    ");
    printf_ret = printf("Multiple: %s %s %s\n", "one", "two", "three");
    compare_results(ft_ret, printf_ret, "Multiple strings");

    printf("\nft_printf: ");
    ft_ret = ft_printf("%s\n", "Very long string with many characters to test buffer handling and memory management");
    printf("printf:    ");
    printf_ret = printf("%s\n", "Very long string with many characters to test buffer handling and memory management");
    compare_results(ft_ret, printf_ret, "Long string");

    // ========== DECIMAL/INTEGER TESTS (%d, %i) ==========
    print_test_header("DECIMAL/INTEGER TESTS (%d, %i)");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Zero: %d\n", 0);
    printf("printf:    ");
    printf_ret = printf("Zero: %d\n", 0);
    compare_results(ft_ret, printf_ret, "Zero");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Positive: %d\n", 42);
    printf("printf:    ");
    printf_ret = printf("Positive: %d\n", 42);
    compare_results(ft_ret, printf_ret, "Positive number");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Negative: %d\n", -42);
    printf("printf:    ");
    printf_ret = printf("Negative: %d\n", -42);
    compare_results(ft_ret, printf_ret, "Negative number");

    printf("\nft_printf: ");
    ft_ret = ft_printf("INT_MAX: %d\n", INT_MAX);
    printf("printf:    ");
    printf_ret = printf("INT_MAX: %d\n", INT_MAX);
    compare_results(ft_ret, printf_ret, "INT_MAX");

    printf("\nft_printf: ");
    ft_ret = ft_printf("INT_MIN: %d\n", INT_MIN);
    printf("printf:    ");
    printf_ret = printf("INT_MIN: %d\n", INT_MIN);
    compare_results(ft_ret, printf_ret, "INT_MIN");

    printf("\nft_printf: ");
    ft_ret = ft_printf("%%i format: %i\n", (int)-2147483648);
    printf("printf:    ");
    printf_ret = printf("%%i format: %i\n", (int)-2147483648);
    compare_results(ft_ret, printf_ret, "%i format");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Multiple: %d %d %d\n", 1, -2, 3);
    printf("printf:    ");
    printf_ret = printf("Multiple: %d %d %d\n", 1, -2, 3);
    compare_results(ft_ret, printf_ret, "Multiple integers");

    // ========== UNSIGNED TESTS (%u) ==========
    print_test_header("UNSIGNED TESTS (%u)");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Zero: %u\n", 0);
    printf("printf:    ");
    printf_ret = printf("Zero: %u\n", 0);
    compare_results(ft_ret, printf_ret, "Unsigned zero");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Positive: %u\n", 42);
    printf("printf:    ");
    printf_ret = printf("Positive: %u\n", 42);
    compare_results(ft_ret, printf_ret, "Unsigned positive");

    printf("\nft_printf: ");
    ft_ret = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    printf("printf:    ");
    printf_ret = printf("UINT_MAX: %u\n", UINT_MAX);
    compare_results(ft_ret, printf_ret, "UINT_MAX");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Negative as unsigned: %u\n", -1);
    printf("printf:    ");
    printf_ret = printf("Negative as unsigned: %u\n", -1);
    compare_results(ft_ret, printf_ret, "Negative as unsigned");

    // ========== HEXADECIMAL TESTS (%x, %X) ==========
    print_test_header("HEXADECIMAL TESTS (%x, %X)");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Hex lower zero: %x\n", 0);
    printf("printf:    ");
    printf_ret = printf("Hex lower zero: %x\n", 0);
    compare_results(ft_ret, printf_ret, "Hex lowercase zero");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Hex lower: %x\n", 255);
    printf("printf:    ");
    printf_ret = printf("Hex lower: %x\n", 255);
    compare_results(ft_ret, printf_ret, "Hex lowercase 255");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Hex upper: %X\n", 255);
    printf("printf:    ");
    printf_ret = printf("Hex upper: %X\n", 255);
    compare_results(ft_ret, printf_ret, "Hex uppercase 255");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Hex lower: %x\n", 2147483647);
    printf("printf:    ");
    printf_ret = printf("Hex lower: %x\n", 2147483647);
    compare_results(ft_ret, printf_ret, "Hex lowercase large");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Hex upper: %X\n", 2147483647);
    printf("printf:    ");
    printf_ret = printf("Hex upper: %X\n", 2147483647);
    compare_results(ft_ret, printf_ret, "Hex uppercase large");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Hex negative: %x\n", -1);
    printf("printf:    ");
    printf_ret = printf("Hex negative: %x\n", -1);
    compare_results(ft_ret, printf_ret, "Hex negative");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Mixed: %x %X\n", 42, 42);
    printf("printf:    ");
    printf_ret = printf("Mixed: %x %X\n", 42, 42);
    compare_results(ft_ret, printf_ret, "Mixed hex cases");

    // ========== POINTER TESTS (%p) ==========
    print_test_header("POINTER TESTS (%p)");

    int var = 42;
    char *str = "test";

    printf("\nft_printf: ");
    ft_ret = ft_printf("Pointer: %p\n", &var);
    printf("printf:    ");
    printf_ret = printf("Pointer: %p\n", &var);
    compare_results(ft_ret, printf_ret, "Variable pointer");

    printf("\nft_printf: ");
    ft_ret = ft_printf("String pointer: %p\n", str);
    printf("printf:    ");
    printf_ret = printf("String pointer: %p\n", str);
    compare_results(ft_ret, printf_ret, "String pointer");

    printf("\nft_printf: ");
    ft_ret = ft_printf("NULL pointer: %p\n", NULL);
    printf("printf:    ");
    printf_ret = printf("NULL pointer: %p\n", (void *)NULL);
    compare_results(ft_ret, printf_ret, "NULL pointer");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Multiple: %p %p\n", &var, str);
    printf("printf:    ");
    printf_ret = printf("Multiple: %p %p\n", &var, str);
    compare_results(ft_ret, printf_ret, "Multiple pointers");

    // ========== PERCENT TESTS (%%) ==========
    print_test_header("PERCENT TESTS (%%)");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Percent: %%\n");
    printf("printf:    ");
    printf_ret = printf("Percent: %%\n");
    compare_results(ft_ret, printf_ret, "Single percent");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Multiple: %%%% %%\n");
    printf("printf:    ");
    printf_ret = printf("Multiple: %%%% %%\n");
    compare_results(ft_ret, printf_ret, "Multiple percents");

    printf("\nft_printf: ");
    ft_ret = ft_printf("100%% complete\n");
    printf("printf:    ");
    printf_ret = printf("100%% complete\n");
    compare_results(ft_ret, printf_ret, "Percent in text");

    // ========== MIXED TESTS ==========
    print_test_header("MIXED TESTS");

    printf("\nft_printf: ");
    ft_ret = ft_printf("All types: %c %s %d %i %u %x %X %p %%\n", 
                        'A', "test", 42, -42, 100, 255, 255, &var);
    printf("printf:    ");
    printf_ret = printf("All types: %c %s %d %i %u %x %X %p %%\n", 
                         'A', "test", 42, -42, 100, 255, 255, &var);
    compare_results(ft_ret, printf_ret, "All format types");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Complex: %d + %d = %d, hex: %x, ptr: %p\n", 
                        10, 20, 30, 30, &var);
    printf("printf:    ");
    printf_ret = printf("Complex: %d + %d = %d, hex: %x, ptr: %p\n", 
                         10, 20, 30, 30, &var);
    compare_results(ft_ret, printf_ret, "Complex mixed");

    printf("\nft_printf: ");
    ft_ret = ft_printf("No format\n");
    printf("printf:    ");
    printf_ret = printf("No format\n");
    compare_results(ft_ret, printf_ret, "No format specifiers");

    printf("\nft_printf: ");
    ft_ret = ft_printf("");
    printf("printf:    ");
    printf_ret = printf("");
    compare_results(ft_ret, printf_ret, "Empty string");

    printf("\nft_printf: ");
    ft_ret = ft_printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
    printf("printf:    ");
    printf_ret = printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
    compare_results(ft_ret, printf_ret, "Many consecutive formats");

    // ========== EDGE CASES ==========
    print_test_header("EDGE CASES");

    printf("\nft_printf: ");
    ft_ret = ft_printf("Trailing percent at end");
    printf("\nprintf:    ");
    printf_ret = printf("Trailing percent at end");
    printf("\n");
    compare_results(ft_ret, printf_ret, "No trailing percent (safe test)");

    printf("\nft_printf: ");
    ft_ret = ft_printf("%%%c%%%s%%%d%%\n", 'X', "test", 42);
    printf("printf:    ");
    printf_ret = printf("%%%c%%%s%%%d%%\n", 'X', "test", 42);
    compare_results(ft_ret, printf_ret, "Percents with formats");

    printf("\nft_printf: ");
    ft_ret = ft_printf("%d %d %d %d %d %d %d %d %d %d\n", 
                        1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("printf:    ");
    printf_ret = printf("%d %d %d %d %d %d %d %d %d %d\n", 
                         1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    compare_results(ft_ret, printf_ret, "Many arguments");

    printf("\n" YELLOW "╔════════════════════════════════════════╗\n");
    printf("║          TESTS COMPLETED!                ║\n");
    printf("╚════════════════════════════════════════╝" RESET "\n\n");

    return (0);
}