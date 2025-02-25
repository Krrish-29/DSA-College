#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct linkedlist{
    Node *head;
    Node *tail;
} linkedlist;
linkedlist *createLinkedList(){
    linkedlist *list = (linkedlist *)calloc(1,sizeof(linkedlist));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
int getSize(linkedlist *list){
    int count = 0;
    Node *current = list->head;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}
int getHead(linkedlist *list){
    return list->head->data;
}
int getTail(linkedlist *list){
    return list->tail->data;
}
Node *getNode(){

}
void printList(linkedlist *list){
    Node *current = list->head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
bool isEmpty(linkedlist*list){
    return list->head==NULL;
}
int search(){

}
void insertAtHead(linkedlist *list, int data){
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
void insertAtTail(linkedlist *list, int data){
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
void insertAt(){

}
void deleteNode(linkedlist *list, int data){
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
void deleteNodeAt(){

}
int main(){
    linkedlist *list=createlinkedlist();
    printf("Is the list empty? %s\n", isEmpty(list) ? "Yes" : "No");
    insertAtHead(list,2);
    insertAtTail(list,5);
    insertAtTail(list,7);
    insertAtHead(list,4);
    insertAtTail(list,9);
    printlist(list);
    InsertAt(list,5,6);
    printlist(list);
    deleteNode(list,8);
    deleteNode(list,6);
    printlist(list);
    deleteNodeAt(list,4);
    printlist(list);
    printf("%d\n",getHead(list));
    printf("%d\n",getTail(list));
    printf("%d\n",getSize(list));
    printf("Is the list empty? %s\n", isEmpty(list) ? "Yes" : "No");
    printf("%d\n",search(list,7));
    Node*x=getNode(list,1);
    printf("%d\n",x->data);
}