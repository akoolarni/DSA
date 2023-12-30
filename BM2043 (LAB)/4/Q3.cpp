#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;


};

TreeNode* createNode(int new_data) {
    TreeNode* new_node = new TreeNode;
    new_node -> data = new_data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

TreeNode* findLCA(TreeNode *root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    if (root -> data == p || root -> data == q) {
        return root;
    }

    TreeNode *leftLCA = findLCA(root -> left, p, q);
    TreeNode *rightLCA = findLCA(root -> right, p, q);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}


int main() {

    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(6);

    //root->right->right = new Node(8);
    //root->left->right->left = new Node(7);
    //root->left->right->right = new Node(4);

    int p = 1;
    int q = 7;
    TreeNode *lca = findLCA(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is " << lca -> data << endl;
    } else {
        cout << "The given nodes do not have LCA. " << endl;
    }

 
    return 0;
}


//TIME complexity - O(N)
//SPACE complexity - O(N)
