#include <stdio.h>
#include <math.h>

int main()
{
    char a = 0;
    short b = 0;
    int c = 0;
    long d = 0;
    size_t e = 0;

    printf("A char is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(a), pow(2,8*sizeof(a))-1);
    printf("A short is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(b), pow(2,8*sizeof(b))-1);
    printf("A int is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(c), pow(2,8*sizeof(c))-1);
    printf("A long is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(d), pow(2,8*sizeof(d))-1);
    printf("A size_t is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(e), pow(2,8*sizeof(e))-1);

    unsigned char f = 0;
    unsigned short g = 0;
    unsigned int h = 0;
    unsigned long i = 0;
    size_t j = 0;

    printf("A unisigned char is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(f), pow(2,8*sizeof(f))-1);
    printf("A unisigned short is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(g), pow(2,8*sizeof(g))-1);
    printf("A unisigned int is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(h), pow(2,8*sizeof(h))-1);
    printf("A unisigned long is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(i), pow(2,8*sizeof(i))-1);
    printf("A size_t is %zu bytes and can hold a maimum value of %0.0f\n", sizeof(j), pow(2,8*sizeof(j))-1);

    return 0;
}
