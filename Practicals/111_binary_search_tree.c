#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;struct TreeNode * left;
    struct TreeNode * right;}TreeNode;
typedef struct Tree{TreeNode * root;}Tree;
Tree *initilaize_tree(){
    Tree * tree =(Tree*)malloc(sizeof(Tree));
    tree->root=NULL;return tree;}
void inorder(TreeNode*root){
    if(root==NULL) return ;inorder(root->left);
    printf("%d ",root->data);inorder(root->right);}
void preorder(TreeNode*root){
    if(root==NULL) return ;printf("%d ",root->data);
    preorder(root->left);preorder(root->right);}
void postorder(TreeNode*root){
    if(root==NULL) return ;postorder(root->left);
    postorder(root->right);printf("%d ",root->data);}
TreeNode* insertNode(TreeNode*root,int data){
    if(root==NULL){
        TreeNode*leafNode=(TreeNode*)malloc(sizeof(TreeNode));
        leafNode->data=data;leafNode->left=NULL;
        leafNode->right=NULL;return leafNode;}
    if(root->data>data){root->left=insertNode(root->left,data);}
    else if(root->data<data){root->right=insertNode(root->right,data);    }
    return root;}
TreeNode*findNode(TreeNode*root,int data){
    if(root==NULL) {printf("The Tree is empty\n");return NULL;}
    if(root->data==data) {return root;}
    else if(root->data>data) { 
        if(root->left==NULL)return NULL;
        return findNode(root->left,data);}
    else if(root->data<data) {
        if(root->right==NULL)return NULL;
        return findNode(root->right,data);}}
TreeNode*findSuccessor(TreeNode*root){
    while(root!=NULL&&root->left!=NULL)  root=root->left;
    return root;}
TreeNode* deleteNode(TreeNode*root,int data){
    if(root==NULL) return NULL;
    if(root->data>data){root->left=deleteNode(root->left,data);}
    else if(root->data<data){root->right=deleteNode(root->right,data);}
    else{if(root->left==NULL&&root->right==NULL){
            free(root);return NULL;}
        else if(root->left==NULL||root->right==NULL){
            TreeNode*temp=(root->left==NULL?root->right:root->left);
            free(root);return temp;}
        else{
            TreeNode*temp=findSuccessor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);}
    }return root;}
int main() {
    Tree* tree = initilaize_tree();
    tree->root = insertNode(tree->root, 9);
    tree->root = insertNode(tree->root, 1);
    tree->root = insertNode(tree->root, 6);
    tree->root = insertNode(tree->root, 4);
    tree->root = insertNode(tree->root, 7);
    printf("In-order traversal : ");inorder(tree->root);
    printf("\nPre-order traversal : ");preorder(tree->root);
    printf("\nPost-order traversal : ");postorder(tree->root);
    printf("\nDeleting node with data 9.");tree->root=deleteNode(tree->root,9);
    printf("\nDeleting node with data 6.");tree->root=deleteNode(tree->root,6);
    printf("\nIn-order traversal : ");inorder(tree->root);
    printf("\nNode with data %d exists:%s",9,((findNode(tree->root,9)==NULL)?"No":"Yes"));
    printf("\nNode with data %d exists:%s\n",7,((findNode(tree->root,7)==NULL)?"No":"Yes"));
}