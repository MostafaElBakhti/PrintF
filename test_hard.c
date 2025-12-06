#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    int ret1, ret2;
    
    printf("\n========== COMPREHENSIVE FT_PRINTF TESTS ==========\n\n");
    
    // ==================== CHARACTER TESTS ====================
    printf("===== CHARACTER TESTS (%%c) =====\n");
    ret1 = ft_printf("ft: [%c] [%c] [%c]\n", 'A', 'B', 'C');
    ret2 = printf("pr: [%c] [%c] [%c]\n", 'A', 'B', 'C');
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: [%c]\n", 0);
    ret2 = printf("pr: [%c]\n", 0);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    // ==================== STRING TESTS ====================
    printf("===== STRING TESTS (%%s) =====\n");
    ret1 = ft_printf("ft: [%s] [%s] [%s]\n", "Hello", "World", "!");
    ret2 = printf("pr: [%s] [%s] [%s]\n", "Hello", "World", "!");
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: [%s]\n", "");
    ret2 = printf("pr: [%s]\n", "");
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    // ==================== INTEGER TESTS ====================
    printf("===== INTEGER TESTS (%%d / %%i) =====\n");
    ret1 = ft_printf("ft: %d %d %d %d %d\n", 0, 1, -1, 42, -42);
    ret2 = printf("pr: %d %d %d %d %d\n", 0, 1, -1, 42, -42);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %i %i %i\n", 123, -456, 789);
    ret2 = printf("pr: %i %i %i\n", 123, -456, 789);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %d\n", INT_MAX);
    ret2 = printf("pr: %d\n", INT_MAX);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %d\n", INT_MIN);
    ret2 = printf("pr: %d\n", INT_MIN);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    // ==================== UNSIGNED TESTS ====================
    printf("===== UNSIGNED TESTS (%%u) =====\n");
    ret1 = ft_printf("ft: %u %u %u %u\n", 0, 1, 42, UINT_MAX);
    ret2 = printf("pr: %u %u %u %u\n", 0, 1, 42, UINT_MAX);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %u %u\n", 123456789, 987654321);
    ret2 = printf("pr: %u %u\n", 123456789, 987654321);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    // ==================== HEXADECIMAL TESTS ====================
    printf("===== HEXADECIMAL TESTS (%%x / %%X) =====\n");
    ret1 = ft_printf("ft: %x %x %x %x\n", 0, 1, 15, 16);
    ret2 = printf("pr: %x %x %x %x\n", 0, 1, 15, 16);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %x %X %x %X\n", 255, 255, 4096, 4096);
    ret2 = printf("pr: %x %X %x %X\n", 255, 255, 4096, 4096);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %x %X\n", INT_MAX, UINT_MAX);
    ret2 = printf("pr: %x %X\n", INT_MAX, UINT_MAX);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    // ==================== POINTER TESTS ====================
    printf("===== POINTER TESTS (%%p) =====\n");
    int a = 42;
    int b = 100;
    ret1 = ft_printf("ft: %p %p\n", &a, &b);
    ret2 = printf("pr: %p %p\n", &a, &b);
    printf("Returns: ft=%d, pr=%d\n\n", ret1, ret2);
    
    ret1 = ft_printf("ft: %p\n", (void *)0);
    ret2 = printf("pr: %p\n", (void *)0);
    printf("Returns: ft=%d, pr=%d\n\n", ret1, ret2);
    
    ret1 = ft_printf("ft: %p %p %p\n", (void *)1, (void *)0xFFFF, (void *)0xDEADBEEF);
    ret2 = printf("pr: %p %p %p\n", (void *)1, (void *)0xFFFF, (void *)0xDEADBEEF);
    printf("Returns: ft=%d, pr=%d\n\n", ret1, ret2);
    
    // ==================== PERCENT TESTS ====================
    printf("===== PERCENT TESTS (%%%%) =====\n");
    ret1 = ft_printf("ft: %% %% %%\n");
    ret2 = printf("pr: %% %% %%\n");
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: 100%%\n");
    ret2 = printf("pr: 100%%\n");
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    // ==================== MIXED FORMAT TESTS ====================
    printf("===== MIXED FORMAT TESTS =====\n");
    ret1 = ft_printf("ft: %c %s %d %i %u %x %X %%\n", 'Z', "test", 42, -10, 100, 15, 15);
    ret2 = printf("pr: %c %s %d %i %u %x %X %%\n", 'Z', "test", 42, -10, 100, 15, 15);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    ret2 = printf("pr: %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    // ==================== EDGE CASES ====================
    printf("===== EDGE CASES =====\n");
    ret1 = ft_printf("ft: No format specifiers\n");
    ret2 = printf("pr: No format specifiers\n");
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft:\n");
    ret2 = printf("pr:\n");
    printf("Single newline - Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    ret1 = ft_printf("ft: %d%d%d\n", 1, 2, 3);
    ret2 = printf("pr: %d%d%d\n", 1, 2, 3);
    printf("Match: %s | Returns: ft=%d, pr=%d\n\n", ret1 == ret2 ? "✓" : "✗", ret1, ret2);
    
    printf("\n========== TESTS COMPLETE ==========\n");
    
    return 0;
}
