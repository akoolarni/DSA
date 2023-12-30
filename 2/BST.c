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
    struct TreeNode *new_node = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> height = 1; 
    return new_node;
}


struct TreeNode *insert_BST(struct TreeNode *root, int data, int *comparisons, int *pointerOps) {
    if (root == NULL) {
        (*pointerOps)++; 
        return create_Node(data, comparisons, pointerOps);
    }

    (*comparisons)++; 

    if(data < root -> data){
        root -> left = insert_BST(root -> left, data, comparisons, pointerOps);
    } 
    else if(data > root -> data){
        root -> right = insert_BST(root -> right, data, comparisons, pointerOps);
    }

    return root;
    (*pointerOps)++;
    (*comparisons)++;
}


struct TreeNode *MinNode(struct TreeNode *node) {
    if(node -> left != NULL){
        return MinNode(node -> left);
    }
    return node;

    
}


struct TreeNode *delete_BST(struct TreeNode *root, int data, int *comparisons, int *pointerOps) {
    if (root == NULL) {
        return root;
    }

    (*comparisons)++; 

    if(data < root -> data){
        root -> left = delete_BST(root -> left, data, comparisons, pointerOps);
    } 
    else if(data > root -> data){
        root -> right = delete_BST(root -> right, data, comparisons, pointerOps);
    } 
    else{
        if(root -> left == NULL){
            struct TreeNode *temp = root -> right;
            free(root);
            (*pointerOps)++; 
            return temp;
        } 
        else if(root -> right == NULL) {
            struct TreeNode *temp = root -> left;
            free(root);
            (*pointerOps)++; 
            return temp;
        }

       
        struct TreeNode *temp = MinNode(root -> right);
        root -> data = temp -> data;
        root -> right = delete_BST(root -> right, temp -> data, comparisons, pointerOps);
    }
    return root;
    

    (*comparisons)++;
    (*pointerOps)++;
}


int get_height(struct TreeNode *node) {
    if(node == NULL){
        return 0;
    }

    int leftHeight = get_height(node -> left);
    int rightHeight = get_height(node -> right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
  
    srand(time(NULL));

 
    int inputs[100][1000];

   
    FILE *inputFile = fopen("generatedInputs.txt", "r");
    if(inputFile == NULL) {
        perror("Error in opening input file");
        return 1;
    }

    
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 1000; j++) {
            if(fscanf(inputFile, "%d", &inputs[i][j]) != 1) {
                perror("Error reading input");
                fclose(inputFile);
                return 1;
            }
        }
    }

    fclose(inputFile);

   
    int BSTHeights[100];

   
    int BSTComparisons[100];
    int BSTPointerOps[100];

    for (int i = 0; i < 100; i++) {
        struct TreeNode* BSTRoot = NULL;

       
        for (int j = 0; j < 1000; j++) {
            int data = inputs[i][j];
            BSTRoot = insert_BST(BSTRoot, data, &BSTComparisons[i], &BSTPointerOps[i]);
        }

        
        BSTHeights[i] = get_height(BSTRoot);

       
        int randomKeys[100];
        for (int j = 0; j < 100; j++) {
            randomKeys[j] = inputs[i][rand() % 1000];
        }

        
        for (int j = 0; j < 100; j++) {
            BSTRoot = delete_BST(BSTRoot, randomKeys[j], &BSTComparisons[i], &BSTPointerOps[i]);
        }
    }

    
    FILE *output = fopen("output_bst.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        fprintf(output, "Tree %d:\n", i + 1);
        fprintf(output, "BST Height: %d\n", BSTHeights[i]);
        fprintf(output, "BST Comparisons: %d\n", BSTComparisons[i]);
        fprintf(output, "BST Pointer Operations: %d\n", BSTPointerOps[i]);
    }
    
     fclose(output);
   

    return 0;
}

