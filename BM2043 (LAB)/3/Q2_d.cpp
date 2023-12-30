#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {} // tree declaration
};

int search(int arr[], int start, int end, int target) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}

TreeNode* Tree(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[preIndex]);
    preIndex++;

    if (inStart == inEnd) {
        return root;
    }

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->left = Tree(inorder, preorder, inStart, inIndex - 1, preIndex);
    root->right = Tree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
     printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}





int main(){
    int inorder[] = {5, 8, 10, 3, 14, 20, 22, 25};
    int preorder[] = {20, 8, 5, 3, 10, 14, 22, 25};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    TreeNode* root = Tree(inorder, preorder, 0, n - 1, preIndex);

    cout << "Inorder traversal of the constructed tree: " << endl;;
    printInorder(root);
    cout << endl;
    return 0;
}


//TIME complexity - O(N)
//SPACE complexity - O(N)