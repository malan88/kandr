#include <stdio.h>
#define MAXLINE 1000    // max input line size 

int getl(char line[], int maxline); // lol: getline() is declared in stdio.h
void copy(char to[], char from[]);

// print longest input line 
int main()
{
    int len;                // current line length 
    int max;                // maximum length seen so far 
    char line[MAXLINE];     // current input line 
    char longest[MAXLINE];  // longest line saved here 

    max = 0;
    while ((len = getl(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    // there was a line 
        printf("%d: %s", max, longest); 
    return 0;
}

// getl: read a line into s, return len
int getl(char s[], int lim)
{
    int c, i;

    // initial copy
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

// copy: copy 'from' into 'to'; assumte to is big enough *yikes!*
void copy(char to[], char from[])
{
    int i = 0; // K&R initialize this a line below; why?

    while ((to[i] = from[i]) != '\0')
        ++i;
}
