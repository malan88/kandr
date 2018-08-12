#include <stdio.h>

#define TABSTOP 9

int main(){

    int c;

    for(int i = 1; (c = getchar()) != EOF; i++)
        if (c == '\t')
            while(i % TABSTOP != 0){
                i++;
                putchar(' ');
            }
        else
            putchar(c);

    return 0;
}
