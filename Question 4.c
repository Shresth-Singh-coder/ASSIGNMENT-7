//write a program to count number of leaf nodes and internal nodes in binary search tree.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int countLeafNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;  // Leaf node
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);  // Recurse on both sides
}

int countInternalNodes(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;  // No internal node if root is null or it's a leaf
    }

    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);  // Count the node and recurse
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    int leafNodes = countLeafNodes(root);
    int internalNodes = countInternalNodes(root);

    printf("\nNumber of Leaf Nodes: %d\n", leafNodes);
    printf("Number of Internal Nodes: %d\n", internalNodes);

    return 0;
}
