#include <stdio.h>
#define MAXLINE 1000    // max input line size 
#define WRAP    80      // hardwrap at col 80

int getl(char line[], int maxline); // lol: getline() is declared in stdio.h
int isbl(char c);

// hardwrap lines at WRAP
int main()
{
    int len;                // current line length 
    char c;
    char line[MAXLINE];     // current input line 

    for (int i = 0; (c=getchar())!=EOF; i++){
        line[i] = c;

        if (i >= 80){
            int j = i;
            for (; j >= 0; j--)
                if (isbl(line[j]))
                    break;
                
            if (j > 0){
                line[j] = '\0';
                printf("%s\n", line);
                i = 0;
            }
        }
    }
}

int isbl(char c){
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0' | c == '\r'){
        return 1;
        }else
        return 0;
}
