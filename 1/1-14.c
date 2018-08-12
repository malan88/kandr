#include <stdio.h>

#define LIMIT   255 /* length of array */

/* histogram of letter frequency */
main()
{
    int c, state;
    int c_cnt[LIMIT];

    for (int i = 0; i < LIMIT; ++i)
        c_cnt[i] = 0;

    while ((c = getchar()) != EOF)
        c_cnt[c]++;
    
    for (int i = 0; i < LIMIT; ++i)
        if (c_cnt[i] > 0){
            printf("%c: ", i);
            for (int j = 0; j < c_cnt[i]; j++)
                putchar('%');
            putchar('\n');
        }
}
