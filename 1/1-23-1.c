#include <stdio.h>

/* * * * * * * * * * * * * * * * * * * * * * *
 * Strips sl_st_cmts of the form slash star  *
 * from code. It works over multiple lines.  *
 * It will be interesting, though, to see if *
 * I can do it through slash slash forms     *
 * * * * * * * * * * * * * * * * * * * * * * */

int main()
{
    int sl_st_cmt;                          // slash star comments
    int sl_sl_cmt;                          // slash slash comments
    int sq, dq;                             // single and double quotes
    sl_sl_cmt = sl_st_cmt = sq = dq = 0;    // Initialize everything as false
    char c, prevc;                          // The letter controllers

    // prime the pump
    prevc = getchar();
    c = getchar();

    do{
        if (c == '*' && prevc == '/' && !sq && !dq && !sl_sl_cmt)
            sl_st_cmt = 1;
        else if (c == '/' && prevc == '*' && !sq && !dq && !sl_sl_cmt){
            // This is surprisingly complicated
            sl_st_cmt = 0;
            if ((prevc = getchar())==EOF)
                break;
            if ((c = getchar())==EOF)
                break;
            putchar(prevc);
            prevc = c;
            continue;
        }else if (c == '/' && prevc == '/' && !sl_st_cmt)
            sl_sl_cmt = 1;
        else if (sl_sl_cmt && c == '\n'){
            sl_sl_cmt = 0;
            if ((c = getchar())==EOF)
                break;
            putchar(prevc);
            prevc = c;
            continue;
        }else if (c == '"' && !sq)
            dq = !dq;
        else if (c == '\'' && !dq)
            sq = !sq;

        if (!sl_st_cmt && !sl_sl_cmt)
            putchar(prevc);

        prevc = c;
    } while ((c=getchar())!=EOF);

    if (!sl_st_cmt)
        putchar(prevc);

    return 0;

}
