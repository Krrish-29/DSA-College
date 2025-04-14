/*
// Static array implementation
// Enqueue: Adds an element to the end of the queue.
// Dequeue: Removes and returns the front element from the queue.
// Front/Peek: Returns the front element without removing it.
// IsEmpty: Checks if the queue is empty.
// Size: Returns the number of elements in the queue.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000
typedef struct queue{
    int front;
    int rear;
    int *arr;
}Queue;
Queue* initialize_queue(){
    Queue*queue=(Queue*)calloc(1,sizeof(Queue));
    queue->front=-1;
    queue->rear=-1;
    queue->arr=(int*)calloc(MAX,sizeof(int));
    return queue;
}
bool isEmpty(Queue*queue){
    return queue->rear==-1;  
}
bool isFull(Queue*queue){
    return (queue->rear+1)%MAX==queue->front;
}
void enqueue(Queue*queue,int data){
    if(isFull(queue)){
        printf("OverFlow\n");
        return ;
    }
    if(isEmpty(queue)){
        queue->front=queue->rear=0;
    }
    else{
        queue->rear=(queue->rear+1)%MAX;
    }
    printf("%d is enqueued into the queue\n",data);
    queue->arr[queue->rear]=data;
}
int peek(Queue*queue){
    if(isEmpty(queue)){
        printf("UnderFlow ");
        return -1;
    }
    return queue->arr[queue->front];
}
int dequeue(Queue*queue){
    if(isEmpty(queue)){
        printf("UnderFlow\n");
        return -1;
    }
    int return_value=queue->arr[queue->front];
    if(queue->front==queue->rear){
        queue->front=queue->rear=-1;
    }
    else{
        queue->front=(queue->front+1)%MAX;
    }
    printf("%d is dequeued from the queue\n",return_value);
    return return_value;
}
int getSize(Queue*queue){
    if(isEmpty(queue)){
        return 0;
    }
    else if(queue->rear>=queue->front){
        return queue->rear-queue->front+1;
    }
    else{
        return MAX-(queue->front-queue->rear)-1;
    }
}
Queue* clear(Queue*queue){
    free(queue);
    Queue* queue1=initialize_queue();
    return queue1;
} 
void print(Queue*queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return ;
        }
    for(int i=0;i<getSize(queue);i++){
        printf("%d ",queue->arr[(queue->front+i)%MAX]);
    }
    printf("\n");
}
int main(){
    Queue*queue=initialize_queue();
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    enqueue(queue,10);
    enqueue(queue,7);
    enqueue(queue,5);
    enqueue(queue,1);
    enqueue(queue,6);
    dequeue(queue);
    printf("%d\n",peek(queue));
    print(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    clear(queue);
    dequeue(queue);
    printf("%d\n",peek(queue));
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
}
*/
/*
//Dynamic array implementation
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct queue{
    int front;
    int rear;
    int *arr;
    int capacity;
}Queue;
Queue* initialize_queue(){
    Queue*queue=(Queue*)calloc(1,sizeof(Queue));
    queue->front=-1;
    queue->rear=-1;
    queue->arr=(int*)calloc(1,sizeof(int));
    queue->capacity=1;
    return queue;
}
bool isEmpty(Queue*queue){
    return queue->rear==-1;  
}
bool isFull(Queue*queue){
    return (queue->rear+1)%queue->capacity==queue->front;
}
int getSize(Queue*queue){
    if(isEmpty(queue)){
        return 0;
    }
    else if(queue->rear>=queue->front){
        return queue->rear-queue->front+1;
    }
    else{
        return queue->capacity-(queue->front-queue->rear)-1;
    }
}
void enqueue(Queue*queue,int data){
    if(isFull(queue)){
        queue->capacity*=2;
        int * new_array=(int*)calloc(queue->capacity,sizeof(int));
        int size=getSize(queue);
        for(int i=0;i<size;i++){
            new_array[i]=queue->arr[(queue->front+i)%queue->capacity];
        }
        free(queue->arr);
        queue->arr=new_array;
        queue->front=0;
        queue->rear=size-1;
    }
    if(isEmpty(queue)){
        queue->front=queue->rear=0;
    }
    else{
        queue->rear=(queue->rear+1)%queue->capacity;
    }
    printf("%d is enqueued into the queue\n",data);
    queue->arr[queue->rear]=data;
}
int peek(Queue*queue){
    if(isEmpty(queue)){
        printf("UnderFlow ");
        return -1;
    }
    return queue->arr[queue->front];
}
int dequeue(Queue*queue){
    if(isEmpty(queue)){
        printf("UnderFlow\n");
        return -1;
    }
    int return_value=queue->arr[queue->front];
    if(queue->front==queue->rear){
        queue->front=queue->rear=-1;
    }
    else{
        queue->front=(queue->front+1)%queue->capacity;
    }
    printf("%d is dequeued from the queue\n",return_value);
    return return_value;
}
Queue* clear(Queue*queue){
    free(queue);
    Queue* queue1=initialize_queue();
    return queue1;
} 
void print(Queue*queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return ;
    }
    for(int i=0;i<getSize(queue);i++){
        printf("%d ",queue->arr[(queue->front+i)%queue->capacity]);
    }
    printf("\n");
}
int main(){
    Queue*queue=initialize_queue();
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    enqueue(queue,10);
    enqueue(queue,7);
    enqueue(queue,5);
    enqueue(queue,1);
    enqueue(queue,6);
    dequeue(queue);
    printf("%d\n",peek(queue));
    print(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    clear(queue);
    dequeue(queue);
    printf("%d\n",peek(queue));
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
}
*/
/*
// Single Linked list Implementaion
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct queue{
    Node* head;
}Queue;
Queue* initialize_queue(){
    Queue *queue=(Queue*)calloc(1,sizeof(Queue));
    queue->head=NULL;
    return queue;
}
void enqueue(Queue*queue,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(queue->head==NULL){
        queue->head=newNode;
    }
    else{
        Node*current=queue->head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
    }
    printf("%d is enqueued into the queue\n",data);
}
void print(Queue*queue){
    Node*current=queue->head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
int dequeue(Queue*queue){
    if(queue->head==NULL){
        printf("UnderFlow\n");
        return -1;
    }
    Node*temp=queue->head;
    int return_value=temp->data;
    queue->head=queue->head->next;
    free(temp);
    printf("%d is dequeued from the queue\n",return_value);
    return return_value;
}
int peek(Queue*queue){
    if(queue->head==NULL){
        printf("UnderFlow ");
        return -1;
    }
    return queue->head->data;
}
bool isEmpty(Queue*queue){
    return queue->head==NULL;
}
int getSize(Queue*queue){
    Node*current=queue->head;
    int count=0;
    if(queue->head==NULL) return count;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
} 
void clear(Queue*queue){
    Node*current=queue->head;
    while(current!=NULL){
        Node*temp=current;
        current=current->next;
        free(temp);
    }
    queue->head=NULL;
}
int main(){
    Queue*queue=initialize_queue();
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    enqueue(queue,10);
    enqueue(queue,7);
    enqueue(queue,5);
    enqueue(queue,1);
    enqueue(queue,6);
    dequeue(queue);
    printf("%d\n",peek(queue));
    print(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    clear(queue);
    dequeue(queue);
    printf("%d\n",peek(queue));
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
}
*/
/*
//Double linkedlist implementation

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
}Node;
typedef struct queue{
    Node* head;
    Node* tail;
}Queue;
Queue* initialize_queue(){
    Queue*queue=(Queue*)calloc(1,sizeof(Queue));
    queue->head=NULL;
    queue->tail=NULL;
    return queue;
}
void enqueue(Queue*queue,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=queue->tail;
    if(queue->head==NULL){
        queue->head=newNode;
    }
    else{
        queue->tail->next=newNode;
    }
    queue->tail=newNode;
    printf("%d is enqueued into the queue\n",data);
}
void print(Queue*queue){
    Node*current=queue->head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
int dequeue(Queue*queue){
    if(queue->head==NULL){
        printf("UnderFlow\n");
        return -1;
    }
    else{
        int return_value=queue->head->data;
        Node *temp=queue->head;
        queue->head=queue->head->next;
        if(queue->head!=NULL){
            queue->head->prev=NULL;
        }
        else{
            queue->tail=NULL;
        }
        printf("%d is dequeued from the queue\n",return_value);
        free(temp);
        return return_value;
    }
}
int peek(Queue*queue){
    if(queue->head==NULL){
        printf("UnderFlow ");
        return -1;
    }
    return queue->head->data;
}
int getSize(Queue*queue){
    int count=0;
    if (queue->head==NULL) return count;
    Node*current=queue->head;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
void clear(Queue*queue){
    Node*current=queue->head;
    while(current!=NULL){
        Node*temp=current;
        current=current->next;  
        free(temp);
    }
    queue->head=NULL;
    queue->tail=NULL;
}
bool isEmpty(Queue*queue){
    return queue->head==NULL;
}
int main(){
    Queue*queue=initialize_queue();
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    enqueue(queue,10);
    enqueue(queue,7);
    enqueue(queue,5);
    enqueue(queue,1);
    enqueue(queue,6);
    dequeue(queue);
    printf("%d\n",peek(queue));
    print(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    clear(queue);
    dequeue(queue);
    printf("%d\n",peek(queue));
    printf("%d\n",getSize(queue));
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
}
*/