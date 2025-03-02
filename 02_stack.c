/*
//Static array implementation
// Push: Adds an element to the top of the stack.
// Pop: Removes and returns the top element from the stack.
// Peek/Top: Returns the top element without removing it.
// IsEmpty: Checks if the stack is empty.
// Size:Returns the number of elements in the stack.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max 1000
typedef struct Stack{
    int top;
    int *arr;
}Stack;
Stack* initialize_stack(){
    Stack*stack=(Stack*)calloc(1,sizeof(Stack));
    stack->top=-1;  
    stack->arr=(int*)calloc(MAX,sizeof(int));
    return stack;
}
void print(Stack*stack){
    for(int i=0;i<=stack->top;i++){
        printf("%d ",stack->arr[i]);
    }
    printf("\n");
}
bool isFull(Stack*stack){
    return (stack->top==Max-1);
}
bool isEmpty(Stack*stack){
    return (stack->top==-1);
}
int getSize(Stack*stack){
    return (stack->top)+1;
}
void push(Stack*stack,int data){
    if(!isFull(stack)){
        printf("%d is pushed into the stack\n",data);
        stack->arr[++stack->top]=data;
        return;
    }
    printf("OVERFLOW\n");
}
int pop(Stack*stack){
    if(!isEmpty(stack)){
        printf("%d is poped from the stack\n",stack->arr[stack->top]);
        return stack->arr[stack->top--];
    }
    printf("UNDERFLOW\n");
    return 0;
}
int peek(Stack*stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top];
    }
    return 0;
}
Stack*clear(Stack*stack){
    free(stack);
    Stack*stack1=initialize_stack();
    return stack1;
}
int main(){
    Stack *stack=initialize_stack();
    push(stack,4);
    push(stack,1);
    push(stack,6);
    push(stack,2);
    push(stack,3);
    print(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    printf("Is the Stack empty ? %s\n",isEmpty(stack)?"Yes":"No");
    printf("Is the Stack full ? %s\n",isFull(stack)?"Yes":"No");
    printf("%d\n",peek(stack));
    push(stack,4);
    push(stack,1);
    push(stack,6);
    push(stack,2);
    print(stack);
    printf("%d\n",peek(stack));
    printf("%d\n",getSize(stack));
    stack=clear(stack);
    push(stack,2);
    printf("%d\n",getSize(stack));
}
*/
/*
//Dynamic array implementation
// Initialize Stack: Set up the initial size and allocate memory for the array.
// X Resize: Adjust the size of the array dynamically (usually doubling its size when the stack is full).
// Push: Add an element to the stack, resizing the array if necessary.
// Pop: Remove and return the top element from the stack.
// Peek/Top: Return the top element without removing it.
// isEmpty: Check if the stack is empty.
// isFull:
// free
// clear: Return the number of elements in the stack.

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct stack{
    int top;// same as len in dynamic array 
    int *arr;
    int capacity;
}Stack;
Stack* initialize_stack(){
    Stack*stack=(Stack*)calloc(1,sizeof(Stack));
    stack->top=-1;
    stack->capacity=1;
    stack->arr=(int*)calloc(1,sizeof(int));
    return stack;
}
void print(Stack*stack){
    for(int i=0;i<=stack->top;i++){
        printf("%d ",stack->arr[i]);
    }
    printf("\n");
}
bool isEmpty(Stack*stack){
    return (stack->top==-1);
}
bool isFull(Stack*stack){
    return (stack->top+1==stack->capacity);
}
int getSize(Stack*stack){
    return (stack->top)+1;
}
void push(Stack*stack,int data){
    if(stack->capacity<=++(stack->top)){
        if(((stack->capacity)/2>=stack->top)&&((stack->capacity)/2>0)){
            stack->capacity/=2;
        }
        else{
            stack->capacity*=2;
        }
        stack->arr=realloc(stack->arr,(stack->capacity)*sizeof(int));
    }
    stack->arr[stack->top]=data;
    printf("%d is pushed into the stack\n",data);
}
int pop(Stack*stack){
    if(!isEmpty(stack)){
        printf("%d is poped from the stack\n",stack->arr[stack->top]);
        return stack->arr[stack->top--];
    }
    printf("UNDERFLOW\n");
    return 0;
}
int peek(Stack*stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top];
    }
    printf("UnderFlow ");
    return -1;
}
Stack* clear(Stack*stack){
    free(stack->arr);
    Stack*stack1 =initialize_stack();
    return stack1;
}
int main(){
    Stack *stack=initialize_stack();
    push(stack,4);
    push(stack,1);
    push(stack,6);
    push(stack,2);
    push(stack,3);
    print(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    printf("Is the Stack empty ? %s\n",isEmpty(stack)?"Yes":"No");
    printf("Is the Stack full ? %s\n",isFull(stack)?"Yes":"No");
    printf("%d\n",peek(stack));
    push(stack,4);
    push(stack,1);
    push(stack,6);
    push(stack,2);
    print(stack);
    printf("%d\n",peek(stack));
    printf("%d\n",getSize(stack));
    stack=clear(stack);
    push(stack,2);
    printf("%d\n",getSize(stack));
}
*/
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