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
    return queue;}
bool isEmpty(Queue*queue){ return queue->rear==-1;}
bool isFull(Queue*queue){ return (queue->rear+1)%queue->capacity==queue->front;}
int getSize(Queue*queue){
    if(isEmpty(queue)) return 0;
    else if(queue->rear>=queue->front) return queue->rear-queue->front+1;
    else return queue->capacity-(queue->front-queue->rear)-1;}
void enqueue(Queue*queue,int data){
    if(isFull(queue)){
        queue->capacity*=2;
        int * new_array=(int*)calloc(queue->capacity,sizeof(int));
        int size=getSize(queue);
        for(int i=0;i<size;i++)
            new_array[i]=queue->arr[(queue->front+i)%queue->capacity];
        free(queue->arr);
        queue->arr=new_array;
        queue->front=0;
        queue->rear=size-1;
    }
    if(isEmpty(queue)) queue->front=queue->rear=0;
    else queue->rear=(queue->rear+1)%queue->capacity;
    printf("%d is enqueued into the queue\n",data);
    queue->arr[queue->rear]=data;}
int Peek(Queue*queue){
    if(isEmpty(queue)){
        printf("UnderFlow ");
        return -1;
    }
    return queue->arr[queue->front];}
int dequeue(Queue*queue){
    if(isEmpty(queue)){
        printf("UnderFlow\n");
        return -1;
    }
    int return_value=queue->arr[queue->front];
    if(queue->front==queue->rear) queue->front=queue->rear=-1;
    else queue->front=(queue->front+1)%queue->capacity;
    printf("%d is dequeued from the queue\n",return_value);
    return return_value;}
Queue* clear(Queue*queue){
    free(queue);
    Queue* queue1=initialize_queue();
    return queue1;} 
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
    printf("The top element of the Queue is:%d\n",Peek(queue));
    printf("The size of the Queue is %d\n",getSize(queue));
    clear(queue);
    printf("Is the Queue empty ?%s\n",isEmpty(queue)?"Yes":"No");
}