#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct Node{int data;struct Node *next;struct Node *prev;} Node;
typedef struct linkedlist{Node *head;Node *tail;} linkedlist;
linkedlist *createlinkedlist(){
    linkedlist *list = (linkedlist *)calloc(1,sizeof(linkedlist));
    list->head = NULL;list->tail = NULL;return list;}
int getSize(linkedlist *list){int count = 0;
    Node *current = list->head;
    while (current != NULL){count++;current = current->next;}
    return count;}
int getHead(linkedlist *list){return list->head->data;}
int getTail(linkedlist *list){return list->tail->data;}
int getNode(linkedlist*list,int index){Node*current=list->head;
    if(getSize(list)>index&&index>=0){
        while(current!=NULL&&index){current=current->next;index--;}
        return current->data;}printf("Invalid Index");return -1;}
void printlist(linkedlist *list){
    if(list->head==NULL){
        printf("The list is empty\n");
        return ;}
    Node*current=list->head;
    printf("The list is:\n");
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->next;}
    printf("\n");}
bool isEmpty(linkedlist*list){return list->head==NULL;}
int search(linkedlist*list,int data){
    if(list->head->data==data) return 0;
    Node *current=list->head;int counter=1;
    while(current->next!=NULL){
        if(current->next->data==data) return counter;
        current=current->next;counter++;}
    if(current->data==data) return ++counter;
    return -1;}
void insertAtHead(linkedlist *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;newNode->next = list->head;
    newNode->prev = NULL;
    if(list->head!=NULL) list->head->prev=newNode;
    else list->tail=newNode;
    list->head=newNode;}
void insertAtTail(linkedlist *list, int data){
    Node *newNode = (Node *)calloc(1,sizeof(Node));
    newNode->data = data;newNode->next = NULL;
    newNode->prev=list->tail;
    if (list->tail != NULL) list->tail->next=newNode;
    else list->head=newNode;
    list->tail=newNode;}
void insertAt(linkedlist*list,int index,int data){
    if(getSize(list)>=index&&index>=0){
        if(index==0)insertAtHead(list,data);
        else if(getSize(list)==index)insertAtTail(list,data);
        else{Node*current=list->head;
            while(--index>0)current=current->next;
            Node*newNode=(Node*)calloc(1,sizeof(Node));
            newNode->data=data;
            newNode->prev=current;
            newNode->next=current->next;
            current->next->prev=newNode;
            current->next=newNode;
        }return;}
    printf("Invalid Index");}
void deleteNode(linkedlist *list, int data){
    if (list->head == NULL) return;
    Node *current = list->head;
    while (current!= NULL&&current->data!=data) current= current->next;
    if(current==NULL){printf("Invalid Data\n");return;}
    if(current->prev!=NULL)current->prev->next=current->next;
    else list->head=current->next;
    if(current->next!=NULL)current->next->prev=current->prev;
    else list->tail=current->prev;
    free(current);
}
void deleteNodeAt(linkedlist*list,int index){
    if(list->head==NULL) return ;
    if(getSize(list)>index&&index>=0){
        Node *current = list->head;
        while (--index>=0)current= current->next;
        if(current->prev!=NULL)current->prev->next=current->next;
        else list->head=current->next;
        if(current->next!=NULL)current->next->prev=current->prev;
        else list->tail=current->prev;
        free(current);return;}   
    printf("Inavlid Index\n");}
    int main(){
        void *list=createlinkedlist();
        printf("Is the list empty? %s\n", isEmpty(list) ? "Yes" : "No");
        insertAtTail(list,5);
        insertAtHead(list,2);
        printlist(list);
        insertAt(list,0,6);
        printlist(list);
        deleteNode(list,8);
        deleteNode(list,6);
        printlist(list);
        deleteNodeAt(list,5);
        printlist(list);
        printf("The head of the list is:%d\n",getHead(list));
        printf("The tail of the list is:%d\n",getTail(list));
        printf("The size of the list is %d\n",getSize(list));
        printf("Is the list empty? %s\n", isEmpty(list) ? "Yes" : "No");
        printf("Index of element 9:%d\n",search(list,9));
        printf("Getting Node at index 0:%d\n",getNode(list,0));
}