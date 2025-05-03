#include <stdio.h>
#include <stdlib.h>
typedef struct Polynomial {
    int coefficient;
    int exponent;
    struct Polynomial *next;
} Polynomial;
    Polynomial *polynomial_addition_or_subtraction(Polynomial*P1,Polynomial*P2,int sign){
        if(P1==NULL) return P2;
        if(P2==NULL) return P1;
        Polynomial it;
        Polynomial *answer=&it;
        while(P1!=NULL&&P2!=NULL){
            if(P1->exponent==P2->exponent){
                P1->coefficient+=(sign*P2->coefficient);
                answer->next=P1;
                P1=P1->next;
                P2=P2->next;
            }
            else if(P1->exponent>P2->exponent){
                answer->next=P1;
                P1=P1->next;
            }
            else{
                P2->coefficient*=sign;
                answer->next=P2;
                P2=P2->next;
            }
            answer=answer->next;
        }
        while(P1!=NULL){
            answer->next=P1;
            answer=answer->next;
            P1=P1->next;
        }
        while(P2!=NULL){
            P2->coefficient*=sign;
            answer->next=P2;
            answer=answer->next;
            P2=P2->next;
        }
        return it.next;
    }
Polynomial* polynomial_multiplication(Polynomial*P1,Polynomial*P2){
    if(P1==NULL||P2==NULL) return NULL;
    Polynomial *answer=NULL;
    while(P1!=NULL){
        Polynomial *p2=P2;
        while(p2!=NULL){
            int expo=(P1->exponent)+(p2->exponent),found=0;
            Polynomial *current=answer;
            while(current!=NULL){
                if(expo==current->exponent){
                    current->coefficient+=((P1->coefficient)*(p2->coefficient));
                    found=1;
                    break;
                }
                current=current->next;
            }
            if(!found){
                Polynomial * temp=(Polynomial*)calloc(1,sizeof(Polynomial));
                temp->coefficient=(P1->coefficient)*(p2->coefficient);
                temp->exponent=expo;
                temp->next=answer;
                answer=temp;
            }
            p2=p2->next; 
        }
        P1=P1->next; 
    }
    return answer;
}
void printpolynomial(Polynomial* P){
    printf("%dx^%d",P->coefficient,P->exponent);
    P=P->next;
    while(P!=NULL){
        printf(" %s%dx^%d",P->coefficient>=0?"+":"",P->coefficient,P->exponent);
        P=P->next;
    }
}
int main() {
    Polynomial *P1 = NULL, *P2 = NULL, *temp = NULL;
    int numTerms, coefficient,sign;
    printf("Which action u want to perform\nEnter 1 for Addition\nEnter 2 for Subtraction\nEnter 3 for Multiplication\n");
    scanf("%d",&sign);
    for (int i = 0; i < 2; i++) {
        printf("Enter the Maximum exponent of %s polynomial:\n", i == 0 ? "1st" : "2nd");
        scanf("%d", &numTerms);
        Polynomial** currentList = (i == 0) ? &P1 : &P2;
        for (int j = 0; j < numTerms; j++) {
            printf("Enter coefficient for term x^%d:\n", numTerms-j-1);
            scanf("%d", &coefficient);
            Polynomial* newNode = (Polynomial*)calloc(1,sizeof(Polynomial));
            newNode->coefficient = coefficient;
            newNode->exponent = numTerms-j-1;
            newNode->next = NULL;
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
    if(sign!=3){
        sign = (sign==1?1:-1);
        printpolynomial(polynomial_addition_or_subtraction(P1,P2,sign));
    }
    else{
        printpolynomial(polynomial_multiplication(P1,P2));
    }
}
