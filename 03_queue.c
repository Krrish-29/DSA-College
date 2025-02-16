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
/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Define the order of the B-Tree
#define ORDER 3
// Structure for the node present in a B-Tree
typedef struct BTreeNode {
    int keys[ORDER - 1]; // Array of keys
    struct BTreeNode* children[ORDER]; // Array of child pointers
    int n; // Current number of keys
    bool leaf; // True if leaf node, false otherwise
} BTreeNode;
// Function to create a new B-Tree node
BTreeNode* createNode(bool isLeaf) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->n = 0;
    newNode->leaf = isLeaf;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}
// Function to split a full child node
void splitChild(BTreeNode* x, int i) {
    BTreeNode* y = x->children[i];
    BTreeNode* z = createNode(y->leaf);
    z->n = ORDER / 2 - 1;
    for (int j = 0; j < ORDER / 2 - 1; j++) {
        z->keys[j] = y->keys[j + ORDER / 2];
    }
    if (!y->leaf) {
        for (int j = 0; j < ORDER / 2; j++) {
            z->children[j] = y->children[j + ORDER / 2];
        }
    }
    y->n = ORDER / 2 - 1;
    for (int j = x->n; j >= i + 1; j--) {
        x->children[j + 1] = x->children[j];
    }
    x->children[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }
    x->keys[i] = y->keys[ORDER / 2 - 1];
    x->n = x->n + 1;
}
// Function to insert a key in a non-full node
void insertNonFull(BTreeNode* x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && k < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n = x->n + 1;
    } else {
        while (i >= 0 && k < x->keys[i]) {
            i--;
        }
        i++;
        if (x->children[i]->n == ORDER - 1) {
            splitChild(x, i);
            if (k > x->keys[i]) {
                i++;
            }
        }
        insertNonFull(x->children[i], k);
    }
}
// Function to traverse the tree
void traverse(BTreeNode* x) {
    int i;
    for (i = 0; i < x->n; i++) {
        if (!x->leaf) {
            traverse(x->children[i]);
        }
        printf(" %d", x->keys[i]);
    }
    if (!x->leaf) {
        traverse(x->children[i]);
    }
}
// Function to search a key in the tree
BTreeNode* search(BTreeNode* x, int k) {
    int i = 0;
    while (i < x->n && k > x->keys[i]) {
        i++;
    }
    if (i < x->n && k == x->keys[i]) {
        return x;
    }
    if (x->leaf) {
        return NULL;
    }
    return search(x->children[i], k);
}
// Function to find the predecessor
int getPredecessor(BTreeNode* node, int idx) {
    BTreeNode* current = node->children[idx];
    while (!current->leaf) {
        current = current->children[current->n];
    }
    return current->keys[current->n - 1];
}
// Function to find the successor
int getSuccessor(BTreeNode* node, int idx) {
    BTreeNode* current = node->children[idx + 1];
    while (!current->leaf) {
        current = current->children[0];
    }
    return current->keys[0];
}
// Function to fill child node
void fill(BTreeNode* node, int idx) {
    if (idx != 0 && node->children[idx - 1]->n >= ORDER / 2) {
        borrowFromPrev(node, idx);
    } else if (idx != node->n && node->children[idx + 1]->n >= ORDER / 2) {
        borrowFromNext(node, idx);
    } else {
        if (idx != node->n) {
            merge(node, idx);
        } else {
            merge(node, idx - 1);
        }
    }
}
// Function to borrow from previous sibling
void borrowFromPrev(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx - 1];
    for (int i = child->n - 1; i >= 0; --i) {
        child->keys[i + 1] = child->keys[i];
    }
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i) {
            child->children[i + 1] = child->children[i];
        }
    }
    child->keys[0] = node->keys[idx - 1];
    if (!child->leaf) {
        child->children[0] = sibling->children[sibling->n];
    }
    node->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n += 1;
    sibling->n -= 1;
}
// Function to borrow from next sibling
void borrowFromNext(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];
    child->keys[child->n] = node->keys[idx];
    if (!child->leaf) {
        child->children[child->n + 1] = sibling->children[0];
    }
    node->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->n; ++i) {
        sibling->keys[i - 1] = sibling->keys[i];
    }
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i) {
            sibling->children[i - 1] = sibling->children[i];
        }
    }
    child->n += 1;
    sibling->n -= 1;
}
// Function to merge two nodes
void merge(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];
    child->keys[ORDER / 2 - 1] = node->keys[idx];

    for (int i = 0; i < sibling->n; ++i) {
        child->keys[i + ORDER / 2] = sibling->keys[i];
    }
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i) {
            child->children[i + ORDER / 2] = sibling->children[i];
        }
    }
    for (int i = idx + 1; i < node->n; ++i) {
        node->keys[i - 1] = node->keys[i];
    }
    for (int i = idx + 2; i <= node->n; ++i) {
        node->children[i - 1] = node->children[i];
    }
    child->n += sibling->n + 1;
    node->n--;
    free(sibling);
}
// Function to remove a key from a non-leaf node
void removeFromNonLeaf(BTreeNode* node, int idx) {
    int k = node->keys[idx];
    if (node->children[idx]->n >= ORDER / 2) {
        int pred = getPredecessor(node, idx);
        node->keys[idx] = pred;
        remove(node->children[idx], pred);
    } else if (node->children[idx + 1]->n >= ORDER / 2) {
        int succ = getSuccessor(node, idx);
        node->keys[idx] = succ;
        remove(node->children[idx + 1], succ);
    } else {
        merge(node, idx);
        remove(node->children[idx], k);
    }
}
// Function to remove a key from a leaf node
void removeFromLeaf(BTreeNode* node, int idx) {
    for (int i = idx + 1; i < node->n; ++i) {
        node->keys[i - 1] = node->keys[i];
    }
    node->n--;
}
// Function to remove a key from the tree
void remove(BTreeNode* node, int k) {
    int idx = 0;
    while (idx < node->n && node->keys[idx] < k) {
        ++idx;
    }
    if (idx < node->n && node->keys[idx] == k) {
        if (node->leaf) {
            removeFromLeaf(node, idx);
        } else {
            removeFromNonLeaf(node, idx);
        }
    } else {
        if (node->leaf) {
            printf("The key %d is not present in the tree\n", k);
            return;
        }
        bool flag = ((idx == node->n) ? true : false);
        if (node->children[idx]->n < ORDER / 2) {
            fill(node, idx);
        }
        if (flag && idx > node->n) {
            remove(node->children[idx - 1], k);
        } else {
            remove(node->children[idx], k);
        }
    }
}
BTreeNode* root;
void insert(int k) {
    if (root->n == ORDER - 1) {
        BTreeNode* s = createNode(false);
        s->children[0] = root;
        root = s;
        splitChild(s, 0);
        insertNonFull(s, k);
    } else {
        insertNonFull(root, k);
    }
}
void traverse() {
    if (root != NULL) {
        traverseNode(root);
    }
}
BTreeNode* search(int k) {
    return (root == NULL) ? NULL : searchNode(root, k);
}
int main() {
    root = createNode(true);
    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(12);
    insert(30);
    insert(7);
    insert(17);
    printf("Traversal of the constructed tree is: ");
    traverse(root);
    printf("\n");
    int k = 6;
    (search(root,k) != NULL) ? printf("%d is found\n", k) : printf("%d is not found\n", k);
    k = 15;
    (search(root,k) != NULL) ? printf("%d is found\n", k) : printf("%d is not found\n", k);
    remove(root, 6);
    printf("Traversal of the tree after removing 6: ");
    traverse(root);
    printf("\n");
    remove(root, 13);
    printf("Traversal of the tree after removing 13: ");
    traverse(root);
    printf("\n");
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3  // Order of the B+ Tree (Adjustable)

// Structure for B+ Tree Node
typedef struct BPlusTreeNode {
    int keys[MAX];  // Array of keys
    struct BPlusTreeNode *children[MAX + 1];  // Array of child pointers
    struct BPlusTreeNode *next;  // Pointer to next leaf node (used in leaf nodes)
    bool isLeaf;  // Flag to indicate leaf node
    int numKeys;  // Number of keys currently in node
} BPlusTreeNode;

BPlusTreeNode *root = NULL;  // Root of the B+ tree

// Function to create a new node
BPlusTreeNode *createNode(bool isLeaf) {
    BPlusTreeNode *newNode = (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
    newNode->isLeaf = isLeaf;
    newNode->numKeys = 0;
    newNode->next = NULL;
    for (int i = 0; i <= MAX; i++) newNode->children[i] = NULL;
    return newNode;
}

// Function to find the leaf node where the key should be inserted
BPlusTreeNode *findLeaf(BPlusTreeNode *node, int key) {
    if (node == NULL) return NULL;
    if (node->isLeaf) return node;

    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) i++;
    return findLeaf(node->children[i], key);
}

// Function to insert a key into a non-full node
void insertInLeaf(BPlusTreeNode *leaf, int key) {
    int i;
    for (i = leaf->numKeys - 1; i >= 0 && leaf->keys[i] > key; i--)
        leaf->keys[i + 1] = leaf->keys[i];

    leaf->keys[i + 1] = key;
    leaf->numKeys++;
}

// Function to split a leaf node
void splitLeaf(BPlusTreeNode *leaf) {
    int mid = (MAX + 1) / 2;
    BPlusTreeNode *newLeaf = createNode(true);
    
    // Move half the keys to the new leaf
    for (int i = mid, j = 0; i < MAX; i++, j++) {
        newLeaf->keys[j] = leaf->keys[i];
        newLeaf->numKeys++;
        leaf->numKeys--;
    }
    
    // Link the new leaf
    newLeaf->next = leaf->next;
    leaf->next = newLeaf;

    // Promote the first key of the new leaf to parent
    int promotedKey = newLeaf->keys[0];

    // If the leaf is root, create a new root
    if (leaf == root) {
        BPlusTreeNode *newRoot = createNode(false);
        newRoot->keys[0] = promotedKey;
        newRoot->children[0] = leaf;
        newRoot->children[1] = newLeaf;
        newRoot->numKeys = 1;
        root = newRoot;
    } else {
        // Insert promoted key into parent
        BPlusTreeNode *parent = findLeaf(root, leaf->keys[0]); // Approximate parent
        insertInLeaf(parent, promotedKey);
        int i;
        for (i = parent->numKeys - 1; i >= 0 && parent->children[i] != leaf; i--)
            parent->children[i + 1] = parent->children[i];

        parent->children[i + 1] = newLeaf;

        // Split parent if needed
        if (parent->numKeys == MAX) splitLeaf(parent);
    }
}

// Function to insert a key
void insert(int key) {
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = key;
        root->numKeys = 1;
        return;
    }

    BPlusTreeNode *leaf = findLeaf(root, key);
    insertInLeaf(leaf, key);

    if (leaf->numKeys == MAX) splitLeaf(leaf);
}

// Function to find a key in the tree
bool search(int key) {
    BPlusTreeNode *leaf = findLeaf(root, key);
    if (leaf == NULL) return false;

    for (int i = 0; i < leaf->numKeys; i++)
        if (leaf->keys[i] == key) return true;

    return false;
}

// Function to print the B+ Tree (Level-wise)
void printTree(BPlusTreeNode *node, int level) {
    if (node == NULL) return;

    printf("Level %d : ", level);
    for (int i = 0; i < node->numKeys; i++)
        printf("%d ", node->keys[i]);
    printf("\n");

    if (!node->isLeaf)
        for (int i = 0; i <= node->numKeys; i++)
            printTree(node->children[i], level + 1);
}

// Function to delete a key (Simplified)
void deleteKey(int key) {
    if (root == NULL) return;

    BPlusTreeNode *leaf = findLeaf(root, key);
    if (leaf == NULL) return;

    int i;
    for (i = 0; i < leaf->numKeys; i++) {
        if (leaf->keys[i] == key) break;
    }

    if (i == leaf->numKeys) return; // Key not found

    for (; i < leaf->numKeys - 1; i++) {
        leaf->keys[i] = leaf->keys[i + 1];
    }

    leaf->numKeys--;

    // If root becomes empty and it is not a leaf
    if (leaf == root && leaf->numKeys == 0) {
        free(root);
        root = NULL;
    }
}

// Main function to test the B+ Tree
int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(12);
    insert(30);
    insert(7);
    insert(17);

    printf("B+ Tree:\n");
    printTree(root, 0);

    printf("\nSearch 12: %s\n", search(12) ? "Found" : "Not Found");
    printf("Search 25: %s\n", search(25) ? "Found" : "Not Found");

    printf("\nDeleting 6...\n");
    deleteKey(6);
    printTree(root, 0);

    return 0;
}
*/ 
/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5   // Maximum keys in a node
#define MIN (2 * MAX / 3)  // Minimum keys (B* property)

typedef struct BTreeNode {
    int keys[MAX];  // Keys stored in the node
    struct BTreeNode *children[MAX + 1];  // Child pointers
    int numKeys;  // Current number of keys
    bool isLeaf;  // True if node is a leaf
} BTreeNode;

BTreeNode *root = NULL;

// Function to create a new node
BTreeNode *createNode(bool isLeaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->numKeys = 0;
    node->isLeaf = isLeaf;
    for (int i = 0; i <= MAX; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to find the appropriate leaf node for insertion
BTreeNode *findLeaf(BTreeNode *node, int key) {
    if (node == NULL || node->isLeaf) return node;

    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) i++;
    return findLeaf(node->children[i], key);
}

// Function to insert a key into a non-full leaf node
void insertInLeaf(BTreeNode *leaf, int key) {
    int i;
    for (i = leaf->numKeys - 1; i >= 0 && leaf->keys[i] > key; i--)
        leaf->keys[i + 1] = leaf->keys[i];

    leaf->keys[i + 1] = key;
    leaf->numKeys++;
}

// Function to redistribute keys with sibling before splitting
void redistributeOrSplit(BTreeNode *parent, int pos) {
    BTreeNode *node = parent->children[pos];
    BTreeNode *sibling = (pos + 1 <= parent->numKeys) ? parent->children[pos + 1] : NULL;

    // If there is a right sibling and it has space, redistribute
    if (sibling && sibling->numKeys < MAX) {
        sibling->children[sibling->numKeys + 1] = sibling->children[sibling->numKeys];
        for (int i = sibling->numKeys; i > 0; i--)
            sibling->keys[i] = sibling->keys[i - 1];
        
        sibling->keys[0] = parent->keys[pos];
        sibling->children[0] = node->children[node->numKeys];

        parent->keys[pos] = node->keys[node->numKeys - 1];
        sibling->numKeys++;
        node->numKeys--;
        return;
    }

    // If redistribution is not possible, split the node
    int mid = (MAX + 1) / 2;
    BTreeNode *newNode = createNode(node->isLeaf);
    
    // Move half of the keys to the new node
    for (int i = mid, j = 0; i < MAX; i++, j++) {
        newNode->keys[j] = node->keys[i];
        newNode->numKeys++;
        node->numKeys--;
    }

    // Adjust children pointers if not a leaf
    if (!node->isLeaf) {
        for (int i = mid; i <= MAX; i++) {
            newNode->children[i - mid] = node->children[i];
            node->children[i] = NULL;
        }
    }

    // Insert the new key into the parent
    for (int i = parent->numKeys; i > pos; i--) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }

    parent->keys[pos] = newNode->keys[0];
    parent->children[pos + 1] = newNode;
    parent->numKeys++;

    // If parent is full, recursively handle
    if (parent->numKeys == MAX) {
        if (parent == root) {
            BTreeNode *newRoot = createNode(false);
            newRoot->children[0] = root;
            root = newRoot;
        }
        redistributeOrSplit(parent, 0);
    }
}

// Function to insert a key into the B* Tree
void insert(int key) {
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = key;
        root->numKeys = 1;
        return;
    }

    BTreeNode *leaf = findLeaf(root, key);
    insertInLeaf(leaf, key);

    // If the leaf becomes full, redistribute or split
    if (leaf->numKeys == MAX) {
        if (leaf == root) {
            BTreeNode *newRoot = createNode(false);
            newRoot->children[0] = root;
            root = newRoot;
        }
        redistributeOrSplit(root, 0);
    }
}

// Function to search for a key in the B* Tree
bool search(BTreeNode *node, int key) {
    if (node == NULL) return false;

    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) i++;

    if (i < node->numKeys && key == node->keys[i]) return true;

    return search(node->children[i], key);
}

// Function to delete a key from the B* Tree (simplified)
void deleteKey(BTreeNode *node, int key) {
    if (node == NULL) return;

    int i;
    for (i = 0; i < node->numKeys; i++) {
        if (node->keys[i] == key) break;
    }

    if (i == node->numKeys) return; // Key not found

    // If the node is a leaf, simply remove the key
    if (node->isLeaf) {
        for (; i < node->numKeys - 1; i++) {
            node->keys[i] = node->keys[i + 1];
        }
        node->numKeys--;
    } else {
        // For non-leaf nodes, replace with predecessor or successor (not fully implemented)
    }
}

// Function to print the tree (level-wise)
void printTree(BTreeNode *node, int level) {
    if (node == NULL) return;

    printf("Level %d : ", level);
    for (int i = 0; i < node->numKeys; i++)
        printf("%d ", node->keys[i]);
    printf("\n");

    if (!node->isLeaf)
        for (int i = 0; i <= node->numKeys; i++)
            printTree(node->children[i], level + 1);
}

// Main function to test the B* Tree
int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(12);
    insert(30);
    insert(7);
    insert(17);

    printf("B* Tree Structure:\n");
    printTree(root, 0);

    printf("\nSearch 12: %s\n", search(root, 12) ? "Found" : "Not Found");
    printf("Search 25: %s\n", search(root, 25) ? "Found" : "Not Found");

    printf("\nDeleting 6...\n");
    deleteKey(root, 6);
    printTree(root, 0);

    return 0;
}
*/