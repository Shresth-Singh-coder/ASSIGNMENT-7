//write a program to find depth of given node.

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

int findDepth(struct node* root, int value, int depth) {
    if (root == NULL) {
        return -1;  // Node not found
    }

    if (root->data == value) {
        return depth;  // Found the node
    }

    int leftDepth = findDepth(root->left, value, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }

    return findDepth(root->right, value, depth + 1);
}

int main() {
    struct node* root = NULL;
    int n, value, nodeValue;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter the node value to find its depth: ");
    scanf("%d", &nodeValue);

    int depth = findDepth(root, nodeValue, 0);

    if (depth == -1) {
        printf("Node with value %d not found in the tree.\n", nodeValue);
    } else {
        printf("Depth of the node with value %d is: %d\n", nodeValue, depth);
    }

    return 0;
}
