 /*Enqueue: Adds an element to the end of the queue.
Dequeue: Removes and returns the front element from the queue.
Front/Peek: Returns the front element without removing it.
IsEmpty: Checks if the queue is empty.
Size: Returns the number of elements in the queue.*/
#include <stdio.h>
#include <stdlib.h>
// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
// Head pointer
Node* head = NULL;
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Function to insert a node at the head
void insertAtHead(int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}
// Function to insert a node at the end
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}
// Function to insert a node at a specific index
void insertAtIndex(int data, int index) {
    if (index == 0) {
        insertAtHead(data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 0; i < index - 1 && temp->next != head; ++i) {
        temp = temp->next;
    }
    if (temp->next == head) {
        insertAtEnd(data);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}
// Function to delete a node from the head
void deleteAtHead() {
    if (!head) return;
    Node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        Node* tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    free(temp);
}
// Function to delete a node from the end
void deleteAtEnd() {
    if (!head) return;
    Node* tail = head->prev;
    if (head->next == head) {
        head = NULL;
    } else {
        tail->prev->next = head;
        head->prev = tail->prev;
    }
    free(tail);
}
// Function to delete a node at a specific index
void deleteAtIndex(int index) {
    if (index == 0) {
        deleteAtHead();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index && temp->next != head; ++i) {
        temp = temp->next;
    }
    if (temp->next == head) {
        deleteAtEnd();
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}
// Function to traverse the list
void traverse() {
    if (!head) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
// Main function to test the circular doubly linked list
int main() {
    insertAtHead(10);
    insertAtHead(5);
    insertAtEnd(20);
    insertAtIndex(15, 2);
    traverse();  // Expected output: 5 10 15 20
    deleteAtHead();
    traverse();  // Expected output: 10 15 20
    deleteAtEnd();
    traverse();  // Expected output: 10 15
    deleteAtIndex(1);
    traverse();  // Expected output: 10
    return 0;
}
