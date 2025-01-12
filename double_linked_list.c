#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct LinkedList{
    Node *head;
    Node *tail;
} LinkedList;
LinkedList *createLinkedList();
void insertAtHead(LinkedList *list, int data);
void insertAtTail(LinkedList *list, int data);
void deleteNode(LinkedList *list, int data);
void printList(LinkedList *list);
int getSize(LinkedList *list);
Node *getHead(LinkedList *list);
Node *getTail(LinkedList *list);
LinkedList *createLinkedList(){
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
void insertAtHead(LinkedList *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;
    if(list->head!=NULL){
        list->head->prev=newNode;
    }
    else{
        list->tail=newNode;
    }
    list->head=newNode;
}
void insertAtTail(LinkedList *list, int data){
    Node *newNode = (Node *)calloc(1,sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev=list->tail;
    if (list->tail != NULL){
        list->tail->next=newNode;
    }
    else{
        list->head=newNode;
    }
    list->tail=newNode;
}
void deleteNode(LinkedList *list, int data){
    if (list->head == NULL){
        return;
    }
    Node *current = list->head;
    while (current->next != NULL&&current->next->data!=data){
        current= current->next;
    }
    if(current==NULL){
        return;
    }
    if(current->prev!=NULL){
        current->prev->next=current->next;
    }
    else{
        list->head=current->next;
    }
    if(current->next!=NULL){
        current->next->prev=current->prev;
    }
    else{
        list->tail=current->prev;
    }
    free(current);
}
void printList(LinkedList *list){
    Node *current = list->head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int getSize(LinkedList *list){
    int count = 0;
    Node *current = list->head;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}
Node *getHead(LinkedList *list){
    return list->head;
}
Node *getTail(LinkedList *list){
    return list->tail;
}