#include <stdio.h>

#define    TRUE    1

main()
{
    int a;

    while(TRUE){
        a = getchar() != EOF;
        printf("%d\n", a);
    }
}
