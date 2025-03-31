#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Node{ int data; struct Node* next; }Node;
typedef struct queue{ Node* head; }Queue;
Queue* initialize_queue(){
    Queue *queue=(Queue*)calloc(1,sizeof(Queue));
    queue->head=NULL;
    return queue;}
void enqueue(Queue*queue,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(queue->head==NULL){ queue->head=newNode; }
    else{
        Node*current=queue->head;
        while(current->next!=NULL)
            current=current->next;
        current->next=newNode;
    }
    printf("%d is enqueued into the queue\n",data); }
void print(Queue*queue){
    Node*current=queue->head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n"); }
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
    return return_value; }
int peek(Queue*queue){
    if(queue->head==NULL){
        printf("UnderFlow ");
        return -1;
    }
    return queue->head->data;}
bool isEmpty(Queue*queue){ return queue->head==NULL; }
int getSize(Queue*queue){
    Node*current=queue->head;
    int count=0;
    if(queue->head==NULL) return count;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;} 
void clear(Queue*queue){
    Node*current=queue->head;
    while(current!=NULL){
        Node*temp=current;
        current=current->next;
        free(temp);
    }
    queue->head=NULL; }
int main(){
    Queue*queue=initialize_queue();
    printf("Is the Queue empty ? %s\n",isEmpty(queue)?"Yes":"No");
    enqueue(queue,4);
    enqueue(queue,3);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("Is the Queue empty ?%s\n",isEmpty(queue)?"Yes":"No");
    enqueue(queue,6);
    printf("The top element of the Queue is:%d\n",peek(queue));
    printf("The size of the Queue is %d\n",getSize(queue));
    clear(queue);
    printf("Is the Queue empty ?%s\n",isEmpty(queue)?"Yes":"No");
}