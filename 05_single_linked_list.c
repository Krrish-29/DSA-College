#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* create a linked list function 
Insertion: Add a new node at the beginning or end of the list.
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
    int count=1;
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
    printf("The list is:\n");
    while(current->next!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
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
bool isEmpty(linkedlist*list){
    if(list->head==NULL){
        return true;
    }
    return false;
}
Node *getNode(linkedlist*list,int index){
    Node*current=list->head;
    int indice=0;
    if(getSize(list)>=index+1){
        while(current->next!=NULL&&indice<=index){
            current=current->next;
            indice++;
        }
        return current;
    }
    printf("Invaild Index");
    return current;
}
int search(linkedlist*list,int data){
    Node*current=list->head;
    int index=0;
    while(current!=NULL&&current->data!=data){
        current=current->next;
        index++;
    }
    if(current==NULL) return -1;
    return index;
}
void InsertAt(linkedlist*list,int index,int data){
    if(getSize(list)>=index+1&&index>=0){
        Node*newNode=(Node*)calloc(1,sizeof(Node));
        newNode->data=data;
        Node*current=list->head;
        for(int indice=index-1;indice>0;indice--){
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
        return;
    }
    printf("Invalid Index");
}
void deleteNodeAt(linkedlist*list,int index){
    if(list->head==NULL){
        return;
    }
    Node*current=list->head;
    if(getSize(list)>=index+1&&index>=0){
        for(int indice=index-1;indice>0;indice--){
            current=current->next;
        }
        Node*temp=current->next;
        current->next=current->next->next;
        free(temp);
        return;
    }
}
int main(){
    void *x=createlinkedlist();
    printf("%d\n\n",isEmpty(x));
    insertAtHead(x,2);
    insertAtTail(x,5);
    insertAtTail(x,7);
    insertAtHead(x,4);
    insertAtTail(x,9);
    printlist(x);
    InsertAt(x,3,6);
    printlist(x);
    deleteNode(x,8);
    deleteNode(x,5);
    printlist(x);
    deleteNodeAt(x,4);
    printlist(x);
    Node*y=getHead(x);
    printf("%d\n",y->data);
    Node*z=getTail(x);
    printf("%d\n",z->data);
    printf("%d\n",getSize(x));
    printf("%d\n",isEmpty(x));
    printf("%d\n",search(x,7));
}