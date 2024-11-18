#include<stdio.h>
#include<stdlib.h>
//balance fcator

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node *createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};
struct Node *insert(struct Node *node,int data){
    if(node == NULL)
    {
        return createNode(data);
    }
    if(data<node->data){
        node->left = insert(node->left,data);
    }
    if(data>node->data){
        node->right=insert(node->right,data);
    }
    return node;
}
int height(struct Node *node){
    if(node == NULL){
        return 0;
    }
    int leftHeight=height(node->left);
    int rightheight=height(node->right);
    return (leftHeight>rightheight)?leftHeight:rightheight+1;
}

int getBalanceFactor(struct Node *node){
    if(node == NULL){
        return 0;
    }
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);
    return leftHeight-rightHeight;
}
int main(){
    struct Node *root = root;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
      


    int balanceFactor=getBalanceFactor(root);

    printf("%d",balanceFactor);
}
