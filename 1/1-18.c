#include <stdio.h>
#define MAXLINE 1000    // max input line size 

int getl(char line[], int maxline); // lol: getline() is declared in stdio.h
void copy(char to[], char from[]);
int triml(char s[], int len);
int isbl(char c);

// trim trailing blanks
int main()
{
    int len;                // current line length 
    char line[MAXLINE];     // current input line 

    while ((len = getl(line, MAXLINE)) > 0){
        len = triml(line, len);
        printf("%s", line);
    }
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
    int j;

int triml(char s[], int len)
{

    for(; isbl(s[len]); --len){
        s[len] = '\0';
    }

    len++;
    s[len] = '\n';
    s[++len] = '\0';

    return len;

}

int isbl(char c){
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0' | c == '\r'){
        return 1;
        }else
        return 0;
}
