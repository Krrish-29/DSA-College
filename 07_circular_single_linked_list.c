#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
    if (list->head==NULL){
        newnode->next=newnode;
    }
    else{
        Node*current=list->head;
        while(current->next!=list->head){
            current=current->next;
        }
        current->next=newnode;
    }
    list->head=newnode;
}
void insertAtTail(linkedlist*list,int data){
    Node*newnode=(Node*)calloc(1,sizeof(Node));
    newnode->data=data;
    newnode->next=list->head;
    if(list->head==NULL){
        list->head=newnode;
        newnode->next=newnode;
    }
    else{
        Node*current=list->head;
        while(current->next!=list->head){
            current=current->next;
        }
        current->next=newnode;
    }
}
void printlist(linkedlist*list){
    if(list->head==NULL){
        printf("The list is empty\n");
        return ;
    } 
    Node*current=list->head;
    printf("The list is:\n");
    while(current->next!=list->head){
        printf("%d\n",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
    printf("\n");
}
int getSize(linkedlist*list){
    if(list->head==NULL) return 0;
    int count=1;
    Node*current=list->head;
    while(current->next!=list->head){
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
    while(current->next!=list->head){
        current=current->next;
    }
    return current->data;
}
bool isEmpty(linkedlist*list){
    return list->head==NULL;
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
int search(linkedlist*list,int data){
    Node*current=list->head;
    if(list->head->data==data) return 0;
    int index=1;
    while(current->next!=list->head){
        if(current->data==data) return index;
        current=current->next;
        index++;
    }
    return -1;
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
    // InsertAt(list,3,6);
    // printlist(list);
    // deleteNode(list,8);
    // deleteNode(list,5);
    // printlist(list);
    // deleteNodeAt(list,4);
    // printlist(list);
    printf("%d\n",getHead(list));
    printf("%d\n",getTail(list));
    printf("%d\n",getSize(list));
    printf("%d\n",isEmpty(list));
    printf("%d\n",search(list,4));
    Node*x=getNode(list,0);
    printf("%d\n",x->data);
}
// void InsertAt(linkedlist*list,int index,int data){
//     if(getSize(list)>index&&index>=0){
//         Node*newNode=(Node*)calloc(1,sizeof(Node));
//         if(index==0){
//             newNode->data=data;
//             newNode->next=list->head;
//             list->head=newNode;
//             return;
//         }
//         newNode->data=data;
//         Node*current=list->head;
//         for(int indice=index-1;indice>0;indice--){
//             current=current->next;
//         }
//         newNode->next=current->next;
//         current->next=newNode;
//         return;
//     }
//     printf("Invalid Index\n");
    
    
// }
// void deleteNode(linkedlist*list,int data){
//     if(list->head==NULL){
//         return;
//     }
//     if(list->head->data==data){
//         Node*temp=list->head;
//         list->head=list->head->next;
//         free(temp);
//         return;
//     }
//     Node*current=list->head;
//     while(current->next!=NULL){
//         if(current->next->data==data){
//             Node*temp=current->next;
//             current->next=current->next->next;
//             free(temp);
//             return;
//         }
//         current=current->next;
//     }
//     printf("Invaild Data\n");
// }
// void deleteNodeAt(linkedlist*list,int index){
//     if(getSize(list)>index&&index>=0){
//         if(list->head==NULL){
//             printf("The list is empty\n");
//             return;
//         }
//         if (index==0){
//             Node*temp=list->head;
//             list->head=list->head->next;
//             free(temp);
//             return;
//         }
//         Node*current=list->head;
//         for(int indice=index-1;indice>0;indice--){
//             current=current->next;
//         }
//         Node*temp=current->next;
//         current->next=current->next->next;
//         free(temp);
//         return;
//     }
//     printf("Invaild Index\n");
// }