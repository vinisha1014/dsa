#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node *createNode(int d){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
    

}
struct Node *insert(){
    int key;
    printf("Enter the key -1 to terminate\n");
    scanf("%d",&key);
    if(key == -1){
        return NULL;
    }
    struct Node* node = createNode(key);
    printf("Insert left child of %d\n",key);
    node->left=insert();
    printf("Insert right child of %d\n",key);
    node->right=insert();
    return node;

   
    
}
int countNodes(struct Node *node){
    if(node == NULL){
        return 0;
    }
    return 1+countNodes(node->left)+countNodes(node->right);
}

int leafNodes(struct Node *node){
    if(node == NULL){
        return 0;
    }
    if(node->left==NULL  && node->right==NULL){
        return 1;
    }
    return leafNodes(node->left)+leafNodes(node->right);
}
struct Node *height(struct Node *node){
    if(node == NULL){
        return 0;
    }
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);
    if(leftHeight>rightHeight){
        return leftHeight+1;
    }
    else{
        return rightHeight+1;
    }

}

struct Node *toFind(struct Node *node,int data){
    if(node == NULL){
        return 0;
    }
    if(node->data==data){
        return node;
    }
    struct Node *leftResult=toFind(node->left,data);
    if(leftResult!=NULL){
        return leftResult;
    }
    return toFind(node->right,data);
}