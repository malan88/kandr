#include <stdio.h>

#define TABSTOP 8

int main()
{

    int c;

    for (int i = 0, pos = 0; (c = getchar()) != EOF; ){
        if (c == '\t'){
            if (i > TABSTOP && i % TABSTOP != 0){
                pos = i + (i % TABSTOP);
            }else if (i % TABSTOP == 0){
                pos += TABSTOP;
            }else{
                pos += TABSTOP - i;
            }
        }else if (c == ' '){
            pos++;
        }else{
            while (pos - i > 0){
                if (pos % TABSTOP == 0 || pos - i == TABSTOP){
                    putchar('\t');
                    i += TABSTOP - (i % TABSTOP);
//                    printf("(%d,%d)", i, pos);
                }else{
                    putchar(' ');
                    i++;
//                    printf("(%d,%d)", i, pos);
                }
            }
            putchar(c);
            i++;
            pos++;
//            printf("(%d,%d)", i, pos);
        }
    }
    return 0;
}
