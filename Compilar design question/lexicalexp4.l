%option noyywrap
%{
    #include<stdio.h>
    int word_count = 0;
%}

%%
[\t\n ]+        ;          /* Ignore spaces, tabs, newlines */
[^ \t\n]+       { word_count++; }
%%

int main(void)
{
    printf("Enter a line:\n");
    yylex();
    printf("Number of words = %d\n", word_count);
    return 0;
}
