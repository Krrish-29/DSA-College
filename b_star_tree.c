
#include <stdio.h>
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