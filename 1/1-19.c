#include <stdio.h>
#define MAXLINE 1000    // max input line size 

int getl(char line[], int maxline); // lol: getline() is declared in stdio.h
void revs(char to[], char from[]);

// Reverse string
int main()
{
    int len;                // current line length 
    char line[MAXLINE];     // current input line 
    char reversed[MAXLINE];  // reversed line

    while ((len = getl(line, MAXLINE)) > 0){
        revs(reversed, line);
        printf("%s\n", reversed);
    }

    return 0;
}

// getl: read a line into s, return length
int getl(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) // that is nasty
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; // append the null terminator (which K&R haven't explained yet)
    return i;
}

// revs: reverse 'from' into 'to';
void revs(char to[], char from[])
{
    int i = 0; 
    while(from[i] != '\0')
        i++;
    int eol = i;

    int j;
    for(j = 0; j < eol; ){
        i--; 
        to[j] = from[i];
        j++;
    }
    to[j] = '\0';
}
