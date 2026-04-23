#include<stdio.h>
#include<string.h>

int main()
{
    int n, i;
    char stmt[20];

    printf("Enter number of statements: ");
    scanf("%d", &n);

    printf("Enter statements:\n");

    for(i=0;i<n;i++)
    {
        scanf("%s", stmt);

        char result = stmt[0];
        char arg1   = stmt[2];
        char op     = stmt[3];
        char arg2   = stmt[4];

        switch(op)
        {
            case '+':
                printf("\nMOV R0, %c", arg1);
                printf("\nADD R0, %c", arg2);
                printf("\nMOV %c, R0\n", result);
                break;

            case '-':
                printf("\nMOV R0, %c", arg1);
                printf("\nSUB R0, %c", arg2);
                printf("\nMOV %c, R0\n", result);
                break;

            case '*':
                printf("\nMOV R0, %c", arg1);
                printf("\nMUL R0, %c", arg2);
                printf("\nMOV %c, R0\n", result);
                break;

            case '/':
                printf("\nMOV R0, %c", arg1);
                printf("\nDIV R0, %c", arg2);
                printf("\nMOV %c, R0\n", result);
                break;

            default:
                printf("\nInvalid operator\n");
        }
    }

    return 0;
}