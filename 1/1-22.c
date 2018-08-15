#include <stdio.h>
#define MAXLINE 1000    // max input line size 
#define MAXNL   12      // max number of lines in MAXLINE
#define WRAP    80      // hardwrap at col 80

int isbl(char c);

// hardwrap lines at WRAP
int main()
{
    int len;                // current line length 
    char c;
    char line[MAXLINE];     // current input line 
    char out[MAXNL][WRAP];  // Array to store line after processed

    while ((len = getl(line, MAXLINE)) > 0){
        int i;

        for (i = len, int j = 0; i >= 0; i--, j++)
            if (isbl(line[j]))
                break;
            
        if (i > 0){
            line[j] = '\0';
            printf("%s\n", line);
            i = 0;
        }
    }
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

int isbl(char c){
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0' | c == '\r'){
        return 1;
        }else
        return 0;
}

// copy: copy 'from' into 'to'; assumte to is big enough *yikes!*
void copy(char to[], char from[], int start, int stop)
{
    int i = start; // K&R initialize this a line below; why?

    while ((to[i] = from[i]) != '\0' && i < stop)
        ++i;
}
