    #include<Stdio.h>
    #include<stdlib.h>


    struct Node{
        int data;
        struct Node *left;
        struct Node *right;
        int height;
    };

    struct Node *newNode(int d){
        struct Node *NN=(struct Node *)malloc(sizeof(struct Node));
        NN->data=d;
        NN->left=NULL;
        NN->right=NULL;
        NN->height=1;
        return NN;
    }

    int height(struct Node *node){
        if(node==NULL){
            return 0;
        }
        return node->height;
    }

    int max(int a,int b){
        return (a>b)? a:b;
    }

    struct Node *rightRotate(struct Node *y){
       struct Node *x=y->left;
       struct Node *T2=x->right;

       x->right=y;
       y->left=T2;

        //update kardo heights

        y->height=max(height(y->left),height(y->right)+1);
        x->height=max(height(x->left),height(x->right)+1);

        return x;


    }

    struct Node *leftRotate(struct Node *x){
        struct Node *y=x->right;
        struct Node *T2=y->left;
       y->left=x;
       x->right=T2;

       x->height=max(height(x->left),height(x->right)+1);
       y->height=max(height(y->left),height(y->right)+1);
       return y;

    }

    int getBalanceFactor(struct Node *node){
        if(node==NULL){
            return 0;
        }
        return height(node->left) - height(node->right);

        
    }
    void printBalanceFactors(struct Node *node){
        if(node!=NULL){
            printBalanceFactors(node->left);
            printf("Node %d, Balance Factor %d\n",node->data,getBalanceFactor(node));
            printBalanceFactors(node->right);
        }
    }

    struct Node *insert(struct Node *node,int data){
        if(node==NULL){
            return newNode(data);
        }
        if(data<node->data){
            node->left=insert(node->left,data);
        }
        else if(data>node->data){
            node->right=insert(node->right,data);
        }
        else{
            return node;
        }
        node->height=1+max(height(node->left),height(node->right));

        int balance=getBalanceFactor(node);
        if(balance<-1 && data>node->right->data)
        return leftRotate(node);

        if(balance>1 && data<node->left->data)
        return rightRotate(node);

    
        if(balance>1  && data>node->left->data){
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }

        if(balance<-1 && data<node->right->data){
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void preorder(struct Node *root){
        if(root!=NULL){
            printf("%d ",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    int main(){
        struct Node *root=NULL;
         int nodes[] = {10, 20, 30, 40, 50, 25};
        int n=sizeof(nodes)/sizeof(nodes[0]);
        for(int i=0;i<n;i++){
        root= insert(root,nodes[i]);
        printf("After inserting %d:\n", nodes[i]);
        printBalanceFactors(root);
        printf("\n");
    }
preorder(root);
    return 0;
        }
    