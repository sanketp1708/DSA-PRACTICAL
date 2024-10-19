
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} BSTNode;

BSTNode* createNode(int data) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BSTNode* insertNode(BSTNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data); }
    return root;}

void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }}
void preorderTraversal(BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }}
void postorderTraversal(BSTNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }}
int searchNode(BSTNode* root, int key) {
    if (root == NULL) {
        return 0;     }
    if (root->data == key) {
        return 1;    }
    if (key < root->data) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }}
BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == NULL)
    return root;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No child (Leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL; }
        // Case 2: One child
        else if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children - directly replace with the rightmost child from the left subtree
        else {
            BSTNode* parent = root;
            BSTNode* succ = root->left;
            while (succ->right != NULL) {
                parent = succ;
                succ = succ->right; }
            root->data = succ->data;
            if (parent != root) {
                parent->right = succ->left;
            } else {
                parent->left = succ->left;   }
            free(succ);
        }}
    return root;
}

int main() {
    BSTNode* root = NULL;
    int choice, value;
    do {
          printf("1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Search\n6.Delete\n7. Exit ");
          printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (searchNode(root, value))
                    printf("Node found.\n");
                else
                    printf("Node not found.\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }  }
while(choice!=7);
    return 0;
}
