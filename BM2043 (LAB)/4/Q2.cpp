#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

struct TreeNode *createNode(int new_data){
    struct TreeNode *new_node = new TreeNode;
    new_node -> data = new_data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}
    

void strictLeftRightTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    
    TreeNode *current = root->left;
    while (current != NULL) {
		cout << current -> data << " ";
		current = current -> left;
        
        
    }

    
    current = root->right;
    while (current != NULL) {
		cout << current -> data << " ";
		current = current -> right;
        
        
    }
}

int main() {
    TreeNode *root = createNode(20);
    root -> left = createNode(8);
    root -> right = createNode(22);
    root -> left -> left = createNode(5);
    root -> left -> right = createNode(3);
//    root -> right -> left = createNode(6);
    root -> right -> right = createNode(25);
    root -> left -> right -> left = createNode(10);
    root -> left -> right -> right = createNode(14);
//    root -> right -> right -> left -> right = createNode(4);

    cout << "The top view of the given binary tree is :  ";
    cout << root -> data << " ";
    strictLeftRightTraversal(root);
    cout << endl;

   return 0;
}


//TIME complexity - O(N)
//SPACE complexity - O(N)
