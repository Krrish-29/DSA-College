#include <stdio.h>
#include <stdlib.h>
typedef struct Polynomial {
    int coefficient;
    int exponent;
    struct Polynomial *next;
} Polynomial;
Polynomial* createNode(int coefficient, int exponent) {
    Polynomial* newNode = (Polynomial*)malloc(sizeof(Polynomial));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}
void printPolynomial(Polynomial* head) {
    Polynomial* current = head;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}
int main() {
    Polynomial *P1 = NULL, *P2 = NULL, *temp = NULL;
    int numTerms, coefficient, exponent;
    for (int i = 0; i < 2; i++) {
        printf("Enter the number of terms for the %s polynomial:\n", i == 0 ? "1st" : "2nd");
        scanf("%d", &numTerms);
        Polynomial** currentList = (i == 0) ? &P1 : &P2;
        for (int j = 0; j < numTerms; j++) {
            printf("Enter coefficient and exponent for term %d:\n", j + 1);
            scanf("%d %d", &coefficient, &exponent);
            Polynomial* newNode = createNode(coefficient, exponent);
            if (*currentList == NULL) {
                *currentList = newNode;
            } else {
                temp = *currentList;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }
    printf("The 1st polynomial is: ");
    printPolynomial(P1);
    printf("The 2nd polynomial is: ");
    printPolynomial(P2);
}
