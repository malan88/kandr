#include <stdio.h>
#define MAXLINE 1000    // max input line size 

int getl(char line[], int maxline); // lol: getline() is declared in stdio.h

// only pint if greater than 80 cols
int main()
{
    int len;                // current line length 
    char line[MAXLINE];     // current input line 

    while ((len = getl(line, MAXLINE)) > 0)
        if (len > 80)
            printf("%d: %s", len, line);
    return 0;
}

// getl: read a line into s, return len
int getl(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) // that is nasty
        s[i] = c;

    if (c == '\n') {            // terminated on \n
        s[i] = c;
        ++i;
        s[i] = '\0'; 

    }else if (i >= lim-1){      // terminated on i == lim-1

        // i++ til EOF or \n, don't cp into s[]
        for( ; (c=getchar())!=EOF && c!='\n'; ++i)
            ;
        s[lim-1] = '\0';
    }

    return i;
}
