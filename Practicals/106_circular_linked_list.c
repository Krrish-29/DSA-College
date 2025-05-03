#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{int data;struct Node* next;}Node;
typedef struct linkedlist{Node* head;}linkedlist;
linkedlist* createlinkedlist(){
    linkedlist*list=(linkedlist*)calloc(1,sizeof(linkedlist));
    list->head=NULL;return list;}
void insertAtHead(linkedlist*list,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=list->head;
    if (list->head==NULL) newNode->next=newNode;
    else{
        Node*current=list->head;
        while(current->next!=list->head) current=current->next;
        current->next=newNode;}
    list->head=newNode;}
void insertAtTail(linkedlist*list,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=list->head;
    if(list->head==NULL){list->head=newNode;newNode->next=newNode;}
    else{Node*current=list->head;while(current->next!=list->head){current=current->next;}current->next=newNode;}}
void printlist(linkedlist*list){
    if(list->head==NULL){printf("The list is empty\n");return ;} 
    Node*current=list->head;printf("The list is:\n");
    while(current->next!=list->head){
        printf("%d->",current->data);
        current=current->next;}
    printf("%d->",current->data);
    current=current->next;
    printf("%d\n",current->data);}
int getSize(linkedlist*list){
    if(list->head==NULL) return 0;
    int count=1;Node*current=list->head;
    while(current->next!=list->head){
        count++;
        current=current->next;}
    return count;}
int getHead(linkedlist*list){return list->head==NULL?-1:list->head->data;}
int getTail(linkedlist*list){
    if(list->head==NULL) return -1;
    Node*current=list->head;
    while(current->next!=list->head)current=current->next;
    return current->data;}
bool isEmpty(linkedlist*list){return list->head==NULL;}
int getNode(linkedlist*list,int index){
    Node*current=list->head;int indice=0;
    if(getSize(list)>=index+1&&index>=0){
        while(current!=NULL&&indice<index){
            current=current->next;
            indice++;}
        return current->data;}
    printf("Invaild Index ");return -1;}
int search(linkedlist*list,int data){
    Node*current=list->head;
    if(list->head->data==data) return 0;
    int index=0;
    while(current->next!=list->head){
        if(current->data==data) return index;
        current=current->next;
        index++;}
    if(current->data==data) return index;return -1;}
void insertAt(linkedlist*list,int index,int data){
    if(getSize(list)>=index&&index>=0){
        Node*newNode=(Node*)calloc(1,sizeof(Node));
        if(index==0){
            newNode->data=data;
            newNode->next=list->head;
            Node*current=list->head;
            while(current->next!=list->head)current=current->next;
            current->next=newNode;
            list->head=newNode;
            return;}
        newNode->data=data;
        Node*current=list->head;
        for(int indice=index-1;indice>0;indice--)current=current->next;
        newNode->next=current->next;
        current->next=newNode;
        return;}printf("Invalid Index\n");}
void deleteNode(linkedlist*list,int data){
    if(list->head==NULL)return;
    if(list->head->data==data){
        Node*temp=list->head;
        Node*current=list->head;
        while(current->next!=list->head)current=current->next;
        current->next=list->head->next;
        list->head=list->head->next;
        free(temp);
        return;}
    Node*current=list->head;
    while(current->next!=list->head){
        if(current->next->data==data){
            Node*temp=current->next;
            current->next=current->next->next;
            free(temp);
            return;}
        current=current->next;}
    printf("Invaild Data\n");}
void deleteNodeAt(linkedlist*list,int index){
    if(getSize(list)>index&&index>=0){
        if(list->head==NULL){
            printf("The list is empty\n");
            return;}
        if(index==0){
            Node*temp=list->head;
            Node*current=list->head;
            while(current->next!=list->head)current=current->next;
            current->next=list->head->next;
            list->head=list->head->next;
            free(temp);
            return;}
        Node*current=list->head;
        for(int indice=index-1;indice>0;indice--)current=current->next;
        Node*temp=current->next;
        current->next=current->next->next;
        free(temp);
        return;
    }printf("Invaild Index\n");}
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