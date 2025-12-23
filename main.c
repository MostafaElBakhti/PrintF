#include "ft_printf.h"
#include <stdio.h>

int main(void) {
    char c = 'A', *s = "Test";
    void *p = (void*)0x1234abcd;
    int d = -42, i = 42, x = 0x2a, X = 0x2A;
    unsigned int u = 3000000000U;

    ft_printf("c:[%c] s:[%s] p:[%p] d:[%d] i:[%i] u:[%u] x:[%x] X:[%X] %%:[%%]\n", c, s, p, d, i, u, x, X);
    printf   ("c:[%c] s:[%s] p:[%p] d:[%d] i:[%i] u:[%u] x:[%x] X:[%X] %%:[%%]\n", c, s, p, d, i, u, x, X);

    return 0;
}