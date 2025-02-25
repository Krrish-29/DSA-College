/*
Single Linked list Implementaion

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct stack{
    Node* head;
}Stack;
void initialize_stack(Stack*stack){
    stack->head=NULL;
}
void push(Stack*stack,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=stack->head;
    stack->head=newNode;
    printf("%d is pushed into the stack\n",data);
}
int pop(Stack*stack){
    if(stack->head==NULL){
        printf("UnderFlow\n");
        return 0;
    }
    Node*temp=stack->head;
    int return_value=temp->data;
    stack->head=stack->head->next;
    free(temp);
    printf("%d is poped from the stack\n",return_value);
    return return_value;
}
int peek(Stack*stack){
    if(stack->head==NULL){
        printf("UnderFlow\n");
        return 0;
    }
    return stack->head->data;
}
bool isEmpty(Stack*stack){
    if(stack->head!=NULL){
        return false;
    }
    else{
        return true;
    }
}
int getSize(Stack*stack){
    Node*current=stack->head;
    int count=0;
    while(current!=NULL){
        current=current->next;
        count++;
    }
    return count;
} 
void clear(Stack*stack){
    Node*current=stack->head;
    while(current!=NULL){
        Node*temp=current;
        current=current->next;
        free(temp);
    }
    stack->head=NULL;
}
int main(){
    Stack stack;
    initialize_stack(&stack);
    printf("%d\n",isEmpty(&stack));
    push(&stack,10);
    push(&stack,7);
    push(&stack,5);
    push(&stack,1);
    push(&stack,6);
    printf("%d\n",peek(&stack));
    push(&stack,9);
    pop(&stack);
    printf("%d\n",peek(&stack));
    pop(&stack);
    pop(&stack);
    printf("%d\n",peek(&stack));
    printf("%d\n",getSize(&stack));
    printf("%d\n",isEmpty(&stack));
    clear(&stack);
    pop(&stack);
    printf("%d\n",peek(&stack));
    printf("%d\n",getSize(&stack));
    printf("%d\n",isEmpty(&stack));
}
*/