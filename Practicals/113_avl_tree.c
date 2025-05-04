#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data, height;struct Node *left, *right;} Node;
typedef struct AVL_Tree {Node *root;} AVL_Tree;
AVL_Tree* init_tree() {
    AVL_Tree* tree = (AVL_Tree*)malloc(sizeof(AVL_Tree));
    tree->root = NULL;return tree;}
int getHeight(Node* root) {return (root == NULL) ? 0 : root->height;}
int getBalanceFactor(Node* root) {return (root == NULL) ? 0 : getHeight(root->left) - getHeight(root->right);}
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    return x;
}
Node* rotateLeft(Node* x) {
    Node* y = x->right;Node* T2 = y->left;y->left = x;x->right = T2;
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    return y;}
Node* insertNode(Node* root, int data) {
    if (!root) {
        printf("%d inserted into AVL Tree.\n",data);
        return createNode(data);}
    if (data < root->data) root->left = insertNode(root->left, data);
    else if (data > root->data) root->right = insertNode(root->right, data);
    else return root;
    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));
    int balance = getBalanceFactor(root);
    if (balance > 1 && data < root->left->data) return rotateRight(root);
    if (balance > 1 && data > root->left->data) { root->left = rotateLeft(root->left); return rotateRight(root); }
    if (balance < -1 && data > root->right->data) return rotateLeft(root);
    if (balance < -1 && data < root->right->data) { root->right = rotateRight(root->right); return rotateLeft(root); }
    return root;
}
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}
Node* deleteNode(Node* root, int data) {
    if (!root) return root;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        printf("%d is deleted form AVL Tree.\n",data);
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) { temp = root; root = NULL; }
            else *root = *temp;
            free(temp);
        } else {
            Node* temp = findMin(root->right);
            printf("%d is replaced with %d",root->data,temp->data);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (!root) return root;
    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));
    int balance = getBalanceFactor(root);
    if (balance > 1 && getBalanceFactor(root->left) >= 0) return rotateRight(root);
    if (balance > 1 && getBalanceFactor(root->left) < 0) { root->left = rotateLeft(root->left); return rotateRight(root); }
    if (balance < -1 && getBalanceFactor(root->right) <= 0) return rotateLeft(root);
    if (balance < -1 && getBalanceFactor(root->right) > 0) { root->right = rotateRight(root->right); return rotateLeft(root); }
    return root;
}
void inorder_traversal(Node* root) {
    if (!root) return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}
int main() {
    AVL_Tree* tree = init_tree();
    tree->root = insertNode(tree->root, 7);
    tree->root = insertNode(tree->root, 5);
    tree->root = insertNode(tree->root, 8);
    tree->root = insertNode(tree->root, 2);
    tree->root = insertNode(tree->root, 4);
    tree->root = insertNode(tree->root, 3);
    tree->root = insertNode(tree->root, 1);
    printf("Inorder Traversal: ");
    inorder_traversal(tree->root);
    printf("\n");
    tree->root = deleteNode(tree->root, 3);
    printf("Inorder Traversal: ");
    inorder_traversal(tree->root);
    printf("\n");
}