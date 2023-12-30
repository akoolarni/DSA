#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
};

struct TreeNode *create_Node(int data, int *comparisons, int *pointerOps) {
    struct TreeNode* new_node = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> height = 1;
    return new_node;

    (*comparisons)++;
    (*pointerOps)++;
}

int get_height(struct TreeNode *node) {
    if (node == NULL){
        return 0;
    }
    
    return node -> height;
}

void update_height(struct TreeNode *node) {
    if (node == NULL){
        return;
    }

    node -> height = 1 + (get_height(node -> left) > get_height(node -> right) ? get_height(node -> left) : get_height(node -> right));
}

struct TreeNode *right_Rotate(struct TreeNode *y) {
    struct TreeNode *x = y -> left;
    struct TreeNode *T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    update_height(y);
    update_height(x);

    return x;
}

struct TreeNode *left_Rotate(struct TreeNode *x) {
    struct TreeNode *y = x -> right;
    struct TreeNode *T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    update_height(x);
    update_height(y);

    return y;
}

struct TreeNode *balance_Node(struct TreeNode *node) {
    int balance = get_height(node -> left) - get_height(node -> right);

    if (balance > 1){
        if (get_height(node -> left -> left) >= get_height(node -> left -> right)) {
            return right_Rotate(node);
        } else {
            node -> left = left_Rotate(node -> left);
            return right_Rotate(node);
        }
    }

    if (balance < -1){
        if (get_height(node -> right -> right) >= get_height(node -> right -> left)) {
            return left_Rotate(node);
        } else {
            node -> right = right_Rotate(node -> right);
            return left_Rotate(node);
        }
    }

    return node;
}

struct TreeNode *insert_AVL(struct TreeNode *node, int data, int *comparisons, int *pointerOps) {
    if (node == NULL) {
        (*pointerOps)++;
        return create_Node(data, comparisons, pointerOps);
    }

    (*comparisons)++;
    (*pointerOps)++;
    if(data < node -> data){
        node -> left = insert_AVL(node -> left, data, comparisons, pointerOps);
    }
    else if(data > node -> data){
        node -> right = insert_AVL(node -> right, data, comparisons, pointerOps);
    }
    else{
        return node;
    }

    update_height(node);

    return balance_Node(node);
}

struct TreeNode *MinNode(struct TreeNode *node) {
    if (node -> left != NULL) {
        return MinNode(node -> left);
    }

    return node;
}

struct TreeNode *delete_AVL(struct TreeNode *root, int data, int *comparisons, int *pointerOps) {
    if (root == NULL){
        return root;
    }

    (*comparisons)++;
    
    if(data < root -> data){
        root -> left = delete_AVL(root -> left, data, comparisons, pointerOps);
    }
    
    else if(data > root->data){
        root -> right = delete_AVL(root -> right, data, comparisons, pointerOps);
    }
    else{
        if((root -> left == NULL) || (root -> right == NULL)){
            struct TreeNode *temp = root -> left ? root -> left : root -> right;
            free(root);
            return temp;
        }
        else{
            struct TreeNode *temp = MinNode(root -> right);
            root -> data = temp -> data;
            root -> right = delete_AVL(root -> right, temp -> data, comparisons, pointerOps);
        }
    }

    if (root == NULL){
        return root;
    }

    

    update_height(root);

    printf("%d deleted\n", data);
    return balance_Node(root);
}

int cal_height(struct TreeNode *node) {
    if (node == NULL){
        return -1;
        }
    int leftHeight = cal_height(node -> left);
    int rightHeight = cal_height(node -> right);
    return (1 + (leftHeight > rightHeight ? leftHeight : rightHeight));
}

int main() {
    srand(time(NULL));
    int inputs[100][1000];

    FILE *inputFile = fopen("generatedInputs.txt", "r");
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
        struct TreeNode *AVLRoot = create_Node(inputs[i][0], &AVLComparisons[i], &AVLPointerOps[i]);

        for (int j = 1; j < 1000; j++) {
            int data = inputs[i][j];
            insert_AVL(AVLRoot, data, &AVLComparisons[i], &AVLPointerOps[i]);
        }

        AVLHeights[i] = cal_height(AVLRoot);

        int randomKeys[100];
        for (int j = 0; j < 100; j++) {
            randomKeys[j] = inputs[i][rand() % 1000];
        }

        for (int j = 0; j < 100; j++) {
            AVLRoot = delete_AVL(AVLRoot, randomKeys[j], &AVLComparisons[i], &AVLPointerOps[i]);
        }
    }

    FILE *output = fopen("output_avl.txt", "w");
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

