#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[50], input[50];
int top = -1;

// push
void push(char c)
{
    stack[++top] = c;
}

// pop
void pop()
{
    top--;
}

int main()
{
    int i = 0;
    
    // Example grammar (LL(1))
    // E → iE'
    // E' → +iE' | e
    
    char table[5][5][10] = {
        {"", "iE'", "", "", ""},   // E
        {"", "", "+iE'", "e", "e"} // E'
    };

    char nonTerm[] = {'E','R'}; // R = E'
    char term[] = {'i','+','$'};

    printf("Enter input string: ");
    scanf("%s", input);

    strcat(input, "$");

    push('$');
    push('E'); // start symbol

    printf("\nStack\tInput\n");

    while(top != -1)
    {
        printf("%s\t%s\n", stack, input+i);

        if(stack[top] == input[i])
        {
            pop();
            i++;
        }
        else if(isupper(stack[top]))
        {
            int row=-1, col=-1;

            // find row
            for(int k=0;k<2;k++)
                if(nonTerm[k]==stack[top]) row=k;

            // find column
            for(int k=0;k<3;k++)
                if(term[k]==input[i]) col=k;

            if(row==-1 || col==-1 || strlen(table[row][col])==0)
            {
                printf("\nString Rejected\n");
                return 0;
            }

            pop();

            // push production in reverse
            char prod[10];
            strcpy(prod, table[row][col]);

            if(prod[0] != 'e')
            {
                for(int k=strlen(prod)-1;k>=0;k--)
                    push(prod[k]);
            }
        }
        else
        {
            printf("\nString Rejected\n");
            return 0;
        }
    }

    if(input[i]=='\0')
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}