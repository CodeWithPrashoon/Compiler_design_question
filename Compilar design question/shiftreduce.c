#include <stdio.h>
#include <string.h>

#define MAX 50

char stack[MAX];
char input[MAX];
int top = -1;

// Push function
void push(char symbol) {
    stack[++top] = symbol;
    stack[top + 1] = '\0';
}

// Pop function
void pop(int n) {
    top -= n;
    stack[top + 1] = '\0';
}

// Display current status
void display(char action[]) {
    printf("\nStack: %-10s Input: %-10s Action: %s", stack, input, action);
}

// Check for reductions
void reduce() {
    // Rule: E -> E+E
    if (strlen(stack) >= 3) {
        if (stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
            pop(3);
            push('E');
            display("Reduce E->E+E");
        }
    }

    // Rule: E -> E*E
    if (strlen(stack) >= 3) {
        if (stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
            pop(3);
            push('E');
            display("Reduce E->E*E");
        }
    }

    // Rule: E -> id (i)
    if (stack[top] == 'i') {
        pop(1);
        push('E');
        display("Reduce E->i");
    }
}

int main() {
    int i = 0;
    char ch;

    printf("Enter input string\n: ");
    scanf("%s", input);

    printf("\nParsing Steps:");
    printf("\n");

    while (input[i] != '\0') {
        ch = input[i];

        // Shift
        push(ch);

        // Remove first char from input
        memmove(input, input + 1, strlen(input));

        display("Shift");

        // Try reduction after every shift
        reduce();

        i = 0; // always reset because input shifts
    }

    // Final reduction check
    reduce();

    if (strcmp(stack, "E") == 0) {
        printf("\n\nString Accepted!\n");
    } else {
        printf("\n\nString Rejected!\n");
    }

    return 0;
}