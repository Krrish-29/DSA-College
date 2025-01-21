/* 
//Static array implementation
// Push: Adds an element to the top of the stack.
// Pop: Removes and returns the top element from the stack.
// Peek/Top: Returns the top element without removing it.
// IsEmpty: Checks if the stack is empty.
// Size:Returns the number of elements in the stack.
#include<stdio.h>
#include<stdbool.h>
#define Max 1000
typedef struct Stack{
    int top;
    int arr[Max];
}Stack;
void initialize_stack(Stack*stack){
    stack->top=-1;  
}
bool isFull(Stack*stack){
    return (stack->top==Max-1);
}
bool isEmpty(Stack*stack){
    return (stack->top==-1);
}
void Push(Stack*stack,int data){
    if(!isFull(stack)){
        printf("%d is pushed into the stack\n",data);
        stack->arr[++stack->top]=data;
        return;
    }
    printf("OVERFLOW\n");
}
int Pop(Stack*stack){
    if(!isEmpty(stack)){
        printf("%d is poped from the stack\n",stack->arr[stack->top]);
        return stack->arr[stack->top--];
    }
    printf("UNDERFLOW\n");
    return 0;
}
int Peek(Stack*stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top];
    }
    return 0;
}
int getSize(Stack*stack){
    return stack->top;
}
int main(){
    Stack stack;
    initialize_stack(&stack);
    Push(&stack,4);
    Push(&stack,1);
    Push(&stack,6);
    Push(&stack,2);
    Push(&stack,3);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    printf("%d\n",isEmpty(&stack));
    printf("%d\n",isFull(&stack));
    printf("%d\n",Peek(&stack));
    Push(&stack,4);
    Push(&stack,1);
    Push(&stack,6);
    Push(&stack,2);

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
void initialize_stack(Stack*stack){
    stack->top=-1;
    stack->capacity=1;
    stack->arr=(int*)calloc(1,sizeof(int));
}
void resize(Stack*stack){
    if(((stack->capacity)/2>=stack->top)&&((stack->capacity)/2>0)){
        stack->capacity/=2;
    }
    else{
        stack->capacity*=2;
    }
    stack->arr=realloc(stack->arr,(stack->capacity)*sizeof(int));
}
void Push(Stack*stack,int data){
    if(stack->capacity<=++(stack->top)){
        resize(stack);
    }
    stack->arr[stack->top]=data;
    printf("%d is pushed into the stack\n",data);
}
bool isEmpty(Stack*stack){
    return (stack->top==-1);
}
bool isFull(Stack*stack){
    return (stack->top+1==stack->capacity);
}
int Pop(Stack*stack){
    if(!isEmpty(stack)){
        printf("%d is poped from the stack\n",stack->arr[stack->top]);
        return stack->arr[stack->top--];
    }
    printf("UNDERFLOW\n");
    return 0;
}
int Peek(Stack*stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top];
    }
    return 0;
}
int getSize(Stack*stack){
    return (stack->top+1);
}
void clear(Stack*stack){
    free(stack->arr);
    initialize_stack(stack);
}
int main(){
    Stack stack;
    initialize_stack(&stack);
    Push(&stack,4);
    Push(&stack,1);
    Push(&stack,6);
    Push(&stack,2);
    Push(&stack,3);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    printf("%d\n",isEmpty(&stack));
    printf("%d\n",isFull(&stack));
    Push(&stack,4);
    Push(&stack,1);
    Push(&stack,6);
    printf("%d\n",Peek(&stack));
    printf("%d\n",getSize(&stack));
    clear(&stack);
    Push(&stack,2);
    printf("%d\n",getSize(&stack));
}
*/
/*

*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct linkedlist{
    Node* head;
}linkedlist;