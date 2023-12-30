#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a binary tree node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new tree node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Initial height for a new node is 1
    return newNode;
}

// Function to insert a key into a binary search tree
struct Node* insertBST(struct Node* root, int key, int* comparisons, int* pointerOps) {
    if (root == NULL) {
        (*pointerOps)++; // Count a pointer operation for creating a new node
        return createNode(key);
    }

    (*comparisons)++; // Count a comparison

    if (key < root->key) {
        root->left = insertBST(root->left, key, comparisons, pointerOps);
    } else if (key > root->key) {
        root->right = insertBST(root->right, key, comparisons, pointerOps);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* findMinNode(struct Node* node) {
    if (node->left != NULL) {
        return findMinNode(node->left);
    }
    return node;
}

// Function to delete a key from a binary search tree
struct Node* deleteBST(struct Node* root, int key, int* comparisons, int* pointerOps) {
    if (root == NULL) {
        return root;
    }

    (*comparisons)++; // Count a comparison

    if (key < root->key) {
        root->left = deleteBST(root->left, key, comparisons, pointerOps);
    } else if (key > root->key) {
        root->right = deleteBST(root->right, key, comparisons, pointerOps);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            (*pointerOps)++; // Count a pointer operation
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            (*pointerOps)++; // Count a pointer operation
            return temp;
        }

        // Node with two children: get the in-order successor (smallest in the right subtree)
        struct Node* temp = findMinNode(root->right);
        root->key = temp->key;
        root->right = deleteBST(root->right, temp->key, comparisons, pointerOps);
    }

    return root;
}

// Function to calculate the height of a tree
int calculateHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create and populate the inputs
    int inputs[100][1000];

    // Open the input file containing 1000 unique positive integers
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read 1000 integers from the input file
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

    // Arrays to store BST heights
    int bstHeights[100];

    // Arrays to store comparisons and pointer operations
    int bstComparisons[100];
    int bstPointerOps[100];

    for (int i = 0; i < 100; i++) {
        struct Node* bstRoot = NULL;

        // Insert keys into BST
        for (int j = 0; j < 1000; j++) {
            int key = inputs[i][j];
            bstRoot = insertBST(bstRoot, key, &bstComparisons[i], &bstPointerOps[i]);
        }

        // Calculate and store BST heights
        bstHeights[i] = calculateHeight(bstRoot);

        // Choose 100 keys uniformly at random without replacement
        int randomKeys[100];
        for (int j = 0; j < 100; j++) {
            randomKeys[j] = inputs[i][rand() % 1000];
        }

        // Delete random keys one by one
        for (int j = 0; j < 100; j++) {
            bstRoot = deleteBST(bstRoot, randomKeys[j], &bstComparisons[i], &bstPointerOps[i]);
        }
    }

    // Write the results to a text file
    FILE *output = fopen("output2.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        fprintf(output, "Tree %d:\n", i + 1);
        fprintf(output, "BST Height: %d\n", bstHeights[i]);
        fprintf(output, "BST Comparisons: %d\n", bstComparisons[i]);
        fprintf(output, "BST Pointer Operations: %d\n", bstPointerOps[i]);
    }
    
     fclose(output);

	
    // Create a Gnuplot script file
    FILE *gpScript = fopen("plot_data.gp", "w");
    if (gpScript == NULL) {
        perror("Error opening Gnuplot script file");
        return 1;
    }

    // Write the Gnuplot script commands to the script file
    fprintf(gpScript, "set title 'BST Data'\n");
    fprintf(gpScript, "set xlabel 'Tree'\n");
    fprintf(gpScript, "set ylabel 'Values'\n");
    fprintf(gpScript, "plot 'output2.txt' using 1:3 title 'BST Heights' with lines, \n");
    fprintf(gpScript, "     'output2.txt' using 1:4 title 'BST Comparisons' with lines, \n");
    fprintf(gpScript, "     'output2.txt' using 1:5 title 'BST Pointer Operations' with lines\n");
    fclose(gpScript);

    // Execute the Gnuplot script
    system("gnuplot -persistent plot_data.gp");
    
   

    return 0;
}

