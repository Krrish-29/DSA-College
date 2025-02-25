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
int getSize(linkedlist*list){
    int count=0;
    Node*current=list->head;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
int getHead(linkedlist*list){
    if(list->head==NULL) return -1;
    return list->head->data;
}
int getTail(linkedlist*list){
    if(list->head==NULL) return -1;
    Node*current=list->head;
    while(current->next!=NULL){
        current=current->next;
    }
    return current->data;
}
Node *getNode(linkedlist*list,int index){
    Node*current=list->head;
    int indice=0;
    if(getSize(list)>=index+1&&index>=0){
        while(current!=NULL&&indice<index){
            current=current->next;
            indice++;
        }
        return current;
    }
    printf("Invaild Index\nThe head of the list is:");
    return current;
}
void printlist(linkedlist*list){
    if(list->head==NULL){
        printf("The list is empty\n");
        return ;
    }
    Node*current=list->head;
    printf("The list is:\n");
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
    printf("\n");
}
bool isEmpty(linkedlist*list){
    if (list->head==NULL){
        return true;
    }else{
        return false;
    }
}
int search(linkedlist*list,int data){
    Node*current=list->head;
    int index=0;
    while(current!=NULL){
        if(current->data==data) return index;
        current=current->next;
        index++;
    }
    return -1;
}
void insertAtHead(linkedlist*list,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=list->head;
    list->head=newNode;
}
void insertAtTail(linkedlist*list,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(list->head==NULL){
        list->head=newNode;
    }
    else{
        Node*current=list->head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
    }
}
void InsertAt(linkedlist*list,int index,int data){
    if(getSize(list)>=index&&index>=0){
        Node*newNode=(Node*)calloc(1,sizeof(Node));
        if(index==0){
            newNode->data=data;
            newNode->next=list->head;
            list->head=newNode;
            return;
        }
        newNode->data=data;
        Node*current=list->head;
        for(int indice=index-1;indice>0;indice--){
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
        return;
    }
    printf("Invalid Index\n");    
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
    printf("Invaild Data\n");
}
void deleteNodeAt(linkedlist*list,int index){
    if(getSize(list)>index&&index>=0){
        if(list->head==NULL){
            printf("The list is empty\n");
            return;
        }
        if (index==0){
            Node*temp=list->head;
            list->head=list->head->next;
            free(temp);
            return;
        }
        Node*current=list->head;
        for(int indice=index-1;indice>0;indice--){
            current=current->next;
        }
        Node*temp=current->next;
        current->next=current->next->next;
        free(temp);
        return;
    }
    printf("Invaild Index\n");
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