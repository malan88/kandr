#include <stdio.h>
#include <stdlib.h>

/********************************************
 * Reports how many extra braces, brackets, * 
 * parentheses, or quotes there are.        *
 ********************************************/

int main()
{
    int braces, brackets, parens, comment, sq, dq, sqcount, dqcount;
    sqcount = dqcount = braces = brackets = parens = comment = sq = dq = 0;
    char c, prevc;

    prevc = getchar();
    c = getchar();

    do{
        if (c == '*' && prevc == '/' && !sq && !dq)
            comment = 1;
        else if (c == '/' && prevc == '*' && !sq && !dq)
            comment = 0;
        else if (c == '"' && !sq){
            dq = !dq;
            dqcount++;
        }else if (c == '\'' && !dq){
            sq = !sq;
            sqcount++;
        }else if (c == '{' && !comment)
            braces++;
        else if (c == '}' && !comment)
            braces--;
        else if (c == '[' && !comment)
            brackets++;
        else if (c == ']' && !comment)
            brackets--;
        else if (c == '(' && !comment)
            parens++;
        else if (c == ')' && !comment)
            parens--;
            
        prevc = c;
    } while ((c=getchar())!=EOF);


    if (braces > 0)
        printf("%d extra left braces.\n", braces);
    if (braces < 0)
        printf("%d extra right braces.\n", abs(braces));
    if (brackets > 0)
        printf("%d extra left brackets.\n", brackets);
    if (brackets < 0)
        printf("%d extra right brackets.\n", abs(brackets));
    if (parens > 0)
        printf("%d extra left parentheses.\n", parens);
    if (parens < 0)
        printf("%d extra right parentheses.\n", abs(parens));
    if (sqcount % 2 != 0)
        printf("Unclosed single quotes");
    if (dqcount % 2 != 0)
        printf("Unclosed double quotes");


    return 0;

}
