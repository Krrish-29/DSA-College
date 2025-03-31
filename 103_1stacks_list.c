
// Single Linked list Implementaion

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
    printf("%d is pushed into the stack\n",data);}
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
    return return_value;}
int peek(Stack*stack){
    if(stack->head==NULL){
        printf("UnderFlow\n");
        return 0;
    }
    return stack->head->data;}
bool isEmpty(Stack*stack){
    return stack->head!=NULL; }
int getSize(Stack*stack){
    Node*current=stack->head;
    int count=0;
    while(current!=NULL){
        current=current->next;
        count++;
    }
    return count;} 
void clear(Stack*stack){
    Node*current=stack->head;
    while(current!=NULL){
        Node*temp=current;
        current=current->next;
        free(temp);
    }
    stack->head=NULL;}
int main(){
    Stack stack;
    initialize_stack(&stack);
    push(&stack,4);
    push(&stack,3);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    printf("Is the Stack is Empty?%s\n",isEmpty(&stack)?"Yes":"No");
    push(&stack,6);
    printf("The top element of the Stack is:%d\n",peek(&stack));
    printf("The size of the Stack is %d\n",getSize(&stack));
    clear(&stack);
    printf("Is the Stack is Empty?%s\n",isEmpty(&stack)?"Yes":"No");
}