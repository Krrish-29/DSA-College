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