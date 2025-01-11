#include <stdio.h>
#include<stdlib.h>
// create a linked list function 
/*Insertion: Add a new node at the beginning or end of the list.
at head at tail printlist
Deletion: Remove a node from the list.
Search: Find a specific node in the list.
Traversal: Iterate through the list to access each node.
Get size: Return the number of nodes in the list.
Get head: Return the first node in the list.
Get tail: Return the last node in the list.*/
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct linkedlist{
    Node* head;
}linkedlist;
linkedlist* createlinkedlist(){
    linkedlist*list=(linkedlist*)calloc(1,sizeof(linkedlist));
    list->head=NULL;
    return list;
}
void insertAtHead(linkedlist*list,int data){
    Node*newnode=(Node*)calloc(1,sizeof(Node));
    newnode->data=data;
    newnode->next=list->head;
    list->head=newnode;
}
void insertAtTail(linkedlist*list,int data){
    Node*newnode=(Node*)calloc(1,sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    if(list->head==NULL){
        list->head=newnode;
    }
    else{
        Node*current=list->head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newnode;
    }
}
int getSize(linkedlist*list){
    int count=0;
    Node*current=list->head;
    while(current->next!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
Node*getHead(linkedlist*list){
    return list->head;
}
Node*getTail(linkedlist*list){
    Node*current=list->head;
    while(current->next!=NULL){
        current=current->next;
    }
    return current;
}
void printlist(linkedlist*list){
    Node*current=list->head;
    while(current->next!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
    printf("\n");
}
void deleteNode(linkedlist*list,int data){
    if(list->head==NULL){
        return;
    }
    if(list->head->data==data){
        Node*temp=list->head;
        list->head=list->head->next;
        free(temp);
        return;
    }
    Node*current=list->head;
    while(current->next!=NULL){
        if(current->next->data==data){
            Node*temp=current->next;
            current->next=current->next->next;
            free(temp);
            return;
        }
        current=current->next;
    }
}
int main(){
    return 0;
}