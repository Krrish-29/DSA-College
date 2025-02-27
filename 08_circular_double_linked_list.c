#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node*prev;
}Node;
typedef struct linkedlist{
    Node* head;
    Node* tail;
}linkedlist;
linkedlist* createlinkedlist(){
    linkedlist*list=(linkedlist*)calloc(1,sizeof(linkedlist));
    list->head=NULL;
    list->tail=NULL;
    return list;
}
void printlist(linkedlist*list){
    if(list->head==NULL){
        printf("The list is empty\n");
        return ;
    } 
    Node*current=list->head;
    printf("The list is:\n");
    while(current->next!=list->head){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("%d->",current->data);
    current=current->next;
    printf("%d\n",current->data);
}
int getSize(linkedlist*list){
    if(list->head==NULL) return 0;
    int count=0;
    Node*current=list->head;
    while(current!=list->tail){
        count++;
        current=current->next;
    }
    return ++count;
}
int getHead(linkedlist*list){
    if(list->head==NULL) return -1;
    return list->head->data;
}
int getTail(linkedlist*list){
    if(list->head==NULL) return -1;
    return list->tail->data;
}
bool isEmpty(linkedlist*list){
    return list->head==NULL;
}
int getNode(linkedlist*list,int index){
    Node*current=list->head;
    int indice=0;
    if((getSize(list)>=index+1&&index>=0)&&list->head!=NULL){
        while(current!=list->tail&&indice<index){
            current=current->next;
            indice++;
        }
        return current->data;
    }
    printf("Invaild Index ");
    return -1;
}
int search(linkedlist*list,int data){
    Node*current=list->head;
    if(list->head==NULL) return -1;
    int index=0;
    while(current!=list->tail){
        if(current->data==data) return index;
        current=current->next;
        index++;
    }
    if(current->data==data) return index;
    return -1;
}
void insertAtHead(linkedlist*list,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=list->head;
    newNode->prev=list->tail;
    if (list->head==NULL){
        newNode->next=newNode;
        list->tail=newNode;
    }
    else{
        Node*current=list->head;
        while(current->next!=list->head){
            current=current->next;
        }
        current->next=newNode;
    }
    list->head=newNode;
}
void insertAtTail(linkedlist*list,int data){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->next=list->head;
    newNode->prev=list->tail;
    if(list->head==NULL){
        list->head=newNode;
        newNode->next=newNode;
    }
    else{
        Node*current=list->head;
        while(current!=list->tail){
            current=current->next;
        }
        current->next=newNode;
    }
    list->tail=newNode;
}
void insertAt(linkedlist*list,int index,int data){
    if(getSize(list)>=index&&index>=0){
        if(index==0){
            insertAtHead(list,data);
        }
        else if(getSize(list)==index){
            insertAtTail(list,data);
        }
        else{
            Node*newNode=(Node*)calloc(1,sizeof(Node));
            newNode->data=data;
            Node*current=list->head;
            while(--index>0){
                current=current->next;
            }
            newNode->prev=current;
            newNode->next=current->next;
            current->next=newNode;
            current->next->prev=newNode;
        }
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
        if(list->head==list->tail){
            list->head=NULL;
            list->tail=NULL;
        }
        else{
            list->tail->next=list->head->next;
            list->head->next->prev=list->tail;
            list->head=list->head->next;
        }
        free(temp);
        return;
    }
    Node*current=list->head;
    while(current->next!=list->head&&current->next->data!=data){
        current=current->next;
    }
    if(current->next->data!=data){
        printf("Invaild Data\n");
        return;
    }
    Node*temp=current->next;
    if(temp==list->tail){
        list->tail=temp->prev;
        list->tail->next=list->head;
    }
    else{
        current->next=temp->next;
        temp->next->prev=current;      
    }
    free(temp);
}
void deleteNodeAt(linkedlist*list,int index){
    if(getSize(list)>index&&index>=0){
        if(list->head==NULL){
            return;
        }
        if(index==0){
            Node*temp=list->head;
            if(list->head==list->tail){
                list->head=NULL;
                list->tail=NULL;
            }
            else{
                list->tail->next=list->head->next;
                list->head->next->prev=list->tail;
                list->head=list->head->next;
            }
            free(temp);
            return;
        }
        Node*current=list->head;
        while(current->next!=list->head&&--index>0){
            current=current->next;
        }
        Node*temp=current->next;
        if(temp==list->tail){
            list->tail=temp->prev;
            list->tail->next=list->head;
        }
        else{
            current->next=temp->next;
            temp->next->prev=current;      
        }
        free(temp);
    }
    printf("Invaild Index\n");
}
int main(){
    void *list=createlinkedlist();
    printf("%d\n",isEmpty(list));
    insertAtTail(list,5);
    insertAtHead(list,2);
    insertAtTail(list,7);
    insertAtHead(list,4);
    insertAtTail(list,9);
    printlist(list);
    insertAt(list,5,6);
    printlist(list);
    deleteNode(list,5);
    deleteNode(list,6);
    printlist(list);
    deleteNodeAt(list,2);
    printlist(list);
    printf("%d\n",getHead(list));
    printf("%d\n",getTail(list));
    printf("%d\n",getSize(list));
    printf("%d\n",isEmpty(list));
    printf("%d\n",search(list,9));
    printf("%d\n",getNode(list,0));
}