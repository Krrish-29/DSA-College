#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;int height;
    struct Node*left;
    struct Node*right;
}Node;
typedef struct AVL_Tree{
    Node * root;
}AVL_Tree;
AVL_Tree * init_tree(){
    AVL_Tree *Tree=(AVL_Tree*)malloc(sizeof(AVL_Tree));
    Tree->root=NULL;
    return Tree;}
void inorder_traversal(Node*root){
    if(root==NULL) return ;
    inorder_traversal(root->left);
    printf("%d ",root->data);
    inorder_traversal(root->right);
}
int getHeight(Node* root) {
    return (root == NULL) ? 0 : root->height;}
    int getBalanceFactor(Node* root) {
        return (root == NULL) ? 0 : getHeight(root->left) - getHeight(root->right);}
        Node* createNode(int data) {
            Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;newNode->left = NULL;
    newNode->right = NULL;newNode->height = 1;
    return newNode;}
    Node* rotateRight(Node* root) {
        Node* x=root->left;Node* T2=x->right;
        x->right=root;root->left=T2;
        root->height=1+((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));
        x->height=1+((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
        return x;}
        Node* rotateLeft(Node* x) {
            Node* y=x->right;Node* T2 = y->left;
            y->left = x;x->right = T2;
            x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
            y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
            return y;}
            Node* insertNode(Node* root, int data) {
                if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insertNode(root->left, data);
    else if (data > root->data) root->right = insertNode(root->right, data);
    else return root;
    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));
    int balance = getBalanceFactor(root);
    if (balance > 1 && data < root->left->data)
    return rotateRight(root);
    if (balance > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);}
        if (balance < -1 && data > root->right->data)
        return rotateLeft(root);if (balance < -1 && data < root->right->data) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);}
            return root;}
            int main(){
                AVL_Tree*tree=init_tree();
                tree->root=insertNode(tree->root,7);
                tree->root=insertNode(tree->root,5);
                tree->root=insertNode(tree->root,8);
                tree->root=insertNode(tree->root,2);
    tree->root=insertNode(tree->root,4);
    tree->root=insertNode(tree->root,3);
    tree->root=insertNode(tree->root,1);
    printf("Inorder traversal : ");
    inorder_traversal(tree->root);
}