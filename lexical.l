%{
#include<stdio.h>
#include<string.h>

FILE *yyin;

int isKeyword(char *word)
{
    char *keywords[] = {"int", "main", "return", "if", "else", "while", "for"};
    int n = 7;
    for(int i=0;i<n;i++)
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* {
    if(isKeyword(yytext))
        printf("A keyword: %s\n", yytext);
    else
        printf("An identifier: %s\n", yytext);
}

[0-9]+ {
    printf("An integer: %s (%d)\n", yytext, atoi(yytext));
}

[+*/-] {
    printf("An operator: %s\n", yytext);
}

[,;] {
    printf("special symbols: %s\n", yytext);
}

[ \t\n]+   ;   /* Ignore whitespace */

. {
    printf("Unrecognized character: %s\n", yytext);
}
%%

int main()
{
    char filename[50];
    printf("Enter the filename:\n");
    scanf("%s", filename);

    yyin = fopen(filename, "r");
    if(!yyin)
    {
        printf("File not found\n");
        return 0;
    }

    yylex();
    fclose(yyin);
    return 0;
}

int yywrap()
{
    return 1;
}