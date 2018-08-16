#include <stdio.h>



int main()
{
    int comment, sq, dq;
    comment = sq = dq = 0;
    char c, prevc;

    prevc = getchar();
    c = getchar();

    do{
        if (c == '*' && prevc == '/' && !sq && !dq)
            comment = 1;
        else if (c == '/' && prevc == '*' && !sq && !dq){
            comment = 0;
            if ((prevc = getchar())==EOF)
                break;
            if ((c = getchar())==EOF)
                break;
            putchar(prevc);
            prevc = c;
            continue;
        }else if (c == '"' && !sq)
            dq = !dq;
        else if (c == '\'' && !dq)
            sq = !sq;

        if (!comment)
            putchar(prevc);

        prevc = c;
    } while ((c=getchar())!=EOF);

    if (!comment)
        putchar(prevc);

    return 0;

}
