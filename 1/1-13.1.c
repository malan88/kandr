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
            wl[nw]++;
            ++nw;
        }else
            wl[nw]++;
    }
    
    int i;
    int cont = 0;

    /* start at 1 b/c there is an initial char bug from the input loop */
    for(i = 1; i < 1000; i++){
        for (nw = 0; nw < 1000; ++nw){
            if (wl[nw] == 0)
                break;
            if(wl[nw] > i){
                printf("%% ");
                cont = 1;    
            }else
                printf("  ");
        }
        printf("\n");
        if (!cont)
            break;
        else
            cont = 0;
    }
}
