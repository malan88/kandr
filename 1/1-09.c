#include <stdio.h>

/* count lines in input */
main()
{
    int c, prev;
    prev = 'A';

    while ((c = getchar()) != EOF)
        if (c != ' ' || prev != ' '){
            putchar(c);
            prev = c;
        }
    
}
