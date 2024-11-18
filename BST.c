#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform inorder traversal
void inorder(struct Node *root) {
    if (root != NULL) { 
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search for a node in the BST
struct Node *search(struct Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to find the minimum node in the BST
struct Node *findMin(struct Node *root) {
    struct Node *current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to find the maximum node in the BST
struct Node *findMax(struct Node *root) {
    struct Node *current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Function to find the predecessor of a node
struct Node *findPredecessor(struct Node *root) {
    if (root->left != NULL) {
        return findMax(root->left);
    }
    return NULL;
}

// Function to find the successor of a node
struct Node *findSuccessor(struct Node *root) {
    if (root->right != NULL) {
        return findMin(root->right);
    }
    return NULL;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);

    // Print inorder traversal of the tree
    inorder(root);
    printf("\n");

    // Search for a value
    printf("Searching for 40: %s\n", search(root, 40) != NULL ? "found" : "not found");

    // Find and print the predecessor of node 40
    struct Node *predecessor = findPredecessor(search(root, 40));
    if (predecessor != NULL) {
        printf("Predecessor of 40: %d\n", predecessor->data);
    } else {
        printf("No predecessor found for 40\n");
    }

    // Find and print the successor of node 40
    struct Node *successor = findSuccessor(search(root, 40));
    if (successor != NULL) {
        printf("Successor of 40: %d\n", successor->data);
    } else {
        printf("Successor of 40: Does not exist (no right subtree)\n");
    }

    // Find and print the minimum and maximum values in the tree
    printf("Minimum value: %d\n", findMin(root)->data);
    printf("Maximum value: %d\n", findMax(root)->data);

    return 0;
}
