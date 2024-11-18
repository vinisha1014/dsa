#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 10

struct Node{
   char  data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
};

struct Node *stack[MAX];
int top=-1;
void push(struct Node *treeNode){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        
    }
    stack[++top]=treeNode;
}
struct Node *pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[top--];
}
int isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/'); 
}
struct Node *constructTree(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++){
       char ch=postfix[i];
       printf("Processing %c\n",ch);
       if(isalnum(ch)){
        struct Node *node=createNode(ch);
        push(node);
       }
       else if(isOperator(  ch)){
        struct Node *node=createNode(ch);
        node->right=pop();
        node->left=pop();
        push(node);
       }
    }
    return pop();
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}
void postorder(struct Node* node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%c ", node->data);
}

// Preorder traversal of the tree
void preorder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%c ", node->data);
    preorder(node->left);
    preorder(node->right);
}
int main(){
    char postfix[]="ab+c*";
    struct Node *root=constructTree(postfix);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    return 0;
}