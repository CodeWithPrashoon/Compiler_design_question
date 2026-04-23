#include<stdio.h>
#include<string.h>

#define MAX 10

struct Quad
{
    char op, arg1, arg2, result;
}q[MAX];

struct Triple
{
    char op, arg1, arg2;
}t[MAX];

int n;

// Function to parse statements
void parse(char stmt[], int i)
{
    q[i].result = stmt[0];
    q[i].arg1   = stmt[2];
    q[i].op     = stmt[3];
    q[i].arg2   = stmt[4];

    t[i].op   = q[i].op;
    t[i].arg1 = q[i].arg1;
    t[i].arg2 = q[i].arg2;
}

// Function to display Quadruple
void displayQuad()
{
    printf("\n--- Quadruple Representation ---\n");
    printf("Op\tArg1\tArg2\tResult\n");

    for(int i=0;i<n;i++)
    {
        printf("%c\t%c\t%c\t%c\n",
        q[i].op, q[i].arg1, q[i].arg2, q[i].result);
    }
}

// Function to display Triple
void displayTriple()
{
    printf("\n--- Triple Representation ---\n");
    printf("Index\tOp\tArg1\tArg2\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%c\t%c\t%c\n",
        i, t[i].op, t[i].arg1, t[i].arg2);
    }
}

// Function to display Indirect Triple
void displayIndirect()
{
    printf("\n--- Indirect Triple Representation ---\n");
    printf("Pointer\tIndex\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\n", i, i);
    }
}

int main()
{
    char stmt[10];

    printf("Enter number of statements: ");
    scanf("%d", &n);

    printf("Enter the statements:\n");

    for(int i=0;i<n;i++)
    {
        scanf("%s", stmt);
        parse(stmt, i);
    }

    displayQuad();
    displayTriple();
    displayIndirect();

    return 0;
}