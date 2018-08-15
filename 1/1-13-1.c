#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

/* Histogram of word length */
main()
{
    int c, nw, state;
    int wl[1000];

    for (int i = 0; i < 1000; ++i)
        wl[i] = 0;

    state = OUT;
    nw = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
            wl[nw]++;
        }else
            wl[nw]++;
    }
    
    for (nw = 0; nw < 1000; ++nw)
        if (wl[nw] > 0){
            printf("%3d: ", nw);
            for (int i = 0; i < wl[nw]; i++)
                putchar('%');
            putchar('\n');
        }
}
