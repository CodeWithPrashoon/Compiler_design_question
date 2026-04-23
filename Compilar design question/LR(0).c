#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

struct Production {
    char lhs;
    char rhs[10];
};

struct Production p[MAX];
int n;

void printItem(char lhs, char rhs[], int dot) {
    printf("%c -> ", lhs);
    for (int i = 0; i < strlen(rhs); i++) {
        if (i == dot) printf(".");
        printf("%c", rhs[i]);
    }
    if (dot == strlen(rhs)) printf(".");
    printf("\n");
}

// Check non-terminal
int isNonTerminal(char c) {
    return isupper(c);
}

// Closure function (I0)
void closure(char lhs, char rhs[], int dot) {
    printItem(lhs, rhs, dot);

    if (dot < strlen(rhs)) {
        char symbol = rhs[dot];

        if (isNonTerminal(symbol)) {
            for (int i = 0; i < n; i++) {
                if (p[i].lhs == symbol) {
                    printItem(p[i].lhs, p[i].rhs, 0);
                }
            }
        }
    }
}

// GOTO function
void gotoFunc(char symbol) {
    printf("\nGOTO on '%c'\n", symbol);
    printf("\n");

    for (int i = 0; i < n; i++) {
        char rhs[10];
        strcpy(rhs, p[i].rhs);

        // If production starts with symbol
        if (rhs[0] == symbol) {
            printItem(p[i].lhs, rhs, 1); // shift dot
        }
    }
}

int main() {
    char start;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %s", &p[i].lhs, p[i].rhs);
    }

    start = p[0].lhs;

    // Augmented grammar
    printf("\nAugmented Grammar:\n");
    printf("\n");
    printf("Z -> %c\n", start);

    for (int i = 0; i < n; i++) {
        printf("%c -> %s\n", p[i].lhs, p[i].rhs);
    }

    // I0
    printf("\nI0 (Initial Closure):\n");
    printf("\n");

    char augmented_rhs[10];
    sprintf(augmented_rhs, "%c", start);

    closure('Z', augmented_rhs, 0);

    // GOTO examples
    printf("\nGOTO Transitions:\n");
    printf("\n");

    for (int i = 0; i < n; i++) {
        gotoFunc(p[i].lhs);
    }

    return 0;
}