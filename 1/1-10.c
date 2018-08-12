#include <stdio.h>

/* count lines in input */
main()
{
    int c, prev;

    while ((c = getchar()) != EOF)
        if (c == '\t'){
            printf("\\t");
        }else if (c == '\b'){
            // Have they even shown me multi-level branches yet?
            printf("\\b");
        }else if (c == '\\'){
            printf("\\");
        }else {
            putchar(c);
        }

    
}
