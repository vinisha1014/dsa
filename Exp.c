#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
};
struct  Node *stack[MAX];
int top = -1;

void push(struct Node *treeNode){
    if(top==MAX-1){
    printf("Stack Overflow\n");
    return;
}
stack[++top]=treeNode;
}   

struct Node* pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[top--]; // Return top node and decrement top

}
int isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*'|| ch=='/');
}

struct Node *constructTree(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++){
        if(isalnum(postfix[i])){
            struct Node *newNode = createNode(postfix[i]);
            push(newNode);
        }
        else if(isOperator(postfix[i])){
                struct Node *newNode = createNode(postfix[i]);
            struct Node *right = pop();
            struct Node *left = pop();
            newNode->left = left;
            newNode->right=right;
            push(newNode);

        
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
void preorder(struct Node *root){
    if(root!=NULL){
         printf("%c",root->data);
       preorder(root->left);
       
       preorder(root->right);

    }
}
void postorder(struct Node *root){
    if(root!=NULL){
        
       postorder(root->left);
       
       postorder(root->right);
        printf("%c",root->data);

    }
}

int main(){
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    struct Node *root=constructTree(postfix);
    printf("Inorder Traversal\n");
    inorder(root);
     printf("Preorder Traversal\n");
    preorder(root);
     printf("Postorder Traversal\n");
    postorder(root);
    return 0;


}

