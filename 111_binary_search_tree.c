#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node* left;
    struct Node* right;};
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;node->left = NULL;
    node->right = NULL;return node;}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;}
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) current = current->left;
    return current;}
struct Node* delete(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->left = delete(root->left, key); 
    else if (key > root->key) root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;} 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;}
        struct Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }return root;}
int search(struct Node* root, int key) {
    if (root == NULL) return -1; 
    if (root->key == key) return 1; 
    else if (key < root->key) return search(root->left, key); 
    else return search(root->right, key);}
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);}}
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);}}
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);}}
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    printf("Search Index of  %d: %d\n", 40, search(root, 40));
    root = delete(root, 50);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
}