#include <stdio.h>

#define     WRAP    81      // hardwrap at col 80
#define     TAB     8       // tab size

int getl(char s[], int lim);
int f_last_bl(char s[], int end);
int isbl(char c);
void printl(char s[], int last);
int rebase(char s[], int pos);

// hardwrap lines at WRAP
int main()
{
    int len;                // current line length 
    char line[BUFSIZ];      // current input line 

    while ((len = getl(line, BUFSIZ)) > 0)
        if (len <= WRAP)
            printf("%s", line);
        else{
            do{
                int bl = f_last_bl(line, WRAP);
                if (bl > 0){
                    printl(line, bl);
                    len = rebase(line, bl+1);
                }else{
                    printf("%s", line);
                    len = WRAP;
                }
            } while(len > WRAP);
            if (len > 0)
                printf("%s", line);
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

int f_last_bl(char s[], int end)
{
    int i = end;
    while (!isbl(s[i]) && i >= 0)
        i--;
    if (i > 0)
        return i;
    else
        return end;
}

// Return null if a char is any kind of blank
int isbl(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

// print the array up til last (exclusive)
void printl(char s[], int last)
{
    for (int i = 0; i < last; i++)
        putchar(s[i]);
    putchar('\n');
}

int rebase(char s[], int pos)
{
    int i, j;

    if (pos <= 0)
        return -1;
    else{
        i = 0;
        for(int j = pos; j < BUFSIZ && s[j] != '\0'; j++, i++)
            s[i] = s[j];
        s[i+1] = '\0';
        return i;
    }
}


