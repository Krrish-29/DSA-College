#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* createLinkedList();

void insertAtHead(LinkedList* list, int data);

void insertAtTail(LinkedList* list, int data);

void deleteNode(LinkedList* list, int data);

void printList(LinkedList* list);

int getSize(LinkedList* list);

Node* getHead(LinkedList* list);

Node* getTail(LinkedList* list);

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    // list->tail=NULL;
    return list;
}
void insertAtHead(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // newNode->next = list->head;
    list->head = newNode;
}
void insertAtTail(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void deleteNode(LinkedList* list, int data) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    Node* current = list->head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int getSize(LinkedList* list) {
    int count = 0;
    Node* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
Node* getHead(LinkedList* list) {
    return list->head;
}
Node* getTail(LinkedList* list) {
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}









// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;
// typedef struct LinkedList {
//     Node* head;
// } LinkedList;
// LinkedList* createLinkedList();
// void insertAtHead(LinkedList* list, int data);
// void insertAtTail(LinkedList* list, int data);
// void deleteNode(LinkedList* list, int data);
// void printList(LinkedList* list);
// int getSize(LinkedList* list);
// Node* getHead(LinkedList* list);
// Node* getTail(LinkedList* list);
// LinkedList* createLinkedList() {
//     LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
//     list->head = NULL;
//     return list;
// }
// void insertAtHead(LinkedList* list, int data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = list->head;
//     list->head = newNode;
// }
// void insertAtTail(LinkedList* list, int data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     if (list->head == NULL) {
//         list->head = newNode;
//     } else {
//         Node* current = list->head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
// }
// void deleteNode(LinkedList* list, int data) {
//     if (list->head == NULL) {
//         return;
//     }
//     if (list->head->data == data) {
//         Node* temp = list->head;
//         list->head = list->head->next;
//         free(temp);
//         return;
//     }
//     Node* current = list->head;
//     while (current->next != NULL) {
//         if (current->next->data == data) {
//             Node* temp = current->next;
//             current->next = current->next->next;
//             free(temp);
//             return;
//         }
//         current = current->next;
//     }
// }
// void printList(LinkedList* list) {
//     Node* current = list->head;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }
// int getSize(LinkedList* list) {
//     int count = 0;
//     Node* current = list->head;
//     while (current != NULL) {
//         count++;
//         current = current->next;
//     }
//     return count;
// }
// Node* getHead(LinkedList* list) {
//     return list->head;
// }
// Node* getTail(LinkedList* list) {
//     Node* current = list->head;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     return current;
// }