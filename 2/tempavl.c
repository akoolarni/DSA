#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* create_Node(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int get_height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

void updateHeight(struct Node* node) {
    if (node == NULL)
        return;
    node->height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

struct Node* balanceNode(struct Node* node) {
    int balance = get_height(node->left) - get_height(node->right);

    if (balance > 1) {
        if (get_height(node->left->left) >= get_height(node->left->right)) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balance < -1) {
        if (get_height(node->right->right) >= get_height(node->right->left)) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

struct Node* insertAVL(struct Node* node, int key, int* comparisons, int* pointerOps) {
    if (node == NULL) {
        (*pointerOps)++;
        return create_Node(key);
    }

    (*comparisons)++;
    if (key < node->key)
        node->left = insertAVL(node->left, key, comparisons, pointerOps);
    else if (key > node->key)
        node->right = insertAVL(node->right, key, comparisons, pointerOps);
    else
        return node;

    updateHeight(node);

    return balanceNode(node);
}

struct Node* findMinNode(struct Node* node) {
    if (node->left != NULL) {
        return findMinNode(node->left);
    }
    return node;
}

struct Node* deleteAVL(struct Node* root, int key, int* comparisons, int* pointerOps) {
    if (root == NULL)
        return root;

    (*comparisons)++;
    if (key < root->key)
        root->left = deleteAVL(root->left, key, comparisons, pointerOps);
    else if (key > root->key)
        root->right = deleteAVL(root->right, key, comparisons, pointerOps);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMinNode(root->right);
            root->key = temp->key;
            root->right = deleteAVL(root->right, temp->key, comparisons, pointerOps);
        }
    }

    if (root == NULL)
        return root;

    updateHeight(root);

    //printf("%d deleted\n", key);
    return balanceNode(root);
}

int calculateHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    srand(time(NULL));
    int inputs[100][1000];

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            if (fscanf(inputFile, "%d", &inputs[i][j]) != 1) {
                perror("Error reading input");
                fclose(inputFile);
                return 1;
            }
        }
    }

    fclose(inputFile);

    int AVLHeights[100];
    int AVLComparisons[100];
    int AVLPointerOps[100];

    for (int i = 0; i < 100; i++) {
        struct Node* AVLRoot = create_Node(inputs[i][0]);

        for (int j = 1; j < 1000; j++) {
            int key = inputs[i][j];
            insertAVL(AVLRoot, key, &AVLComparisons[i], &AVLPointerOps[i]);
        }

        AVLHeights[i] = calculateHeight(AVLRoot);

        int randomKeys[100];
        for (int j = 0; j < 100; j++) {
            randomKeys[j] = inputs[i][rand() % 1000];
        }

        for (int j = 0; j < 100; j++) {
            AVLRoot = deleteAVL(AVLRoot, randomKeys[j], &AVLComparisons[i], &AVLPointerOps[i]);
        }
    }

    FILE *output = fopen("output1.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        fprintf(output, "Tree %d:\n", i + 1);
        fprintf(output, "AVL Height: %d\n", AVLHeights[i]);
        fprintf(output, "AVL Comparisons: %d\n", AVLComparisons[i]);
        fprintf(output, "AVL Pointer Operations: %d \n", AVLPointerOps[i]);
    }

    fclose(output);

    return 0;
}

