#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}  // tree declaration
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

void dfsInorder(TreeNode* node) {
    if (node != nullptr) {
        dfsInorder(node->left);
        cout << node->data << " ";
        dfsInorder(node->right);
    }
}

int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
}

void printLevel(TreeNode* node, int level, bool leftToRight) {
    if (node == nullptr) {
        return;
    }
    if (level == 1) {
        cout << node->data << " ";
    } else if (level > 1) {
        if (leftToRight) {
            printLevel(node->left, level - 1, leftToRight);
            printLevel(node->right, level - 1, leftToRight);
        } else {
            printLevel(node->right, level - 1, leftToRight);
            printLevel(node->left, level - 1, leftToRight);
        }
    }
}

void dfs(TreeNode* root) {
    cout << "Depth First Search for the binary tree: ";
    dfsInorder(root); 
    cout << endl;
}

void levelOrder(TreeNode* root) {
    int height = getHeight(root);
    bool leftToRight = true;
    cout << "Level order traversal for the binary tree: ";
    for (int i = 1; i <= height; i++) {
        printLevel(root, i, leftToRight);
        leftToRight = !leftToRight;
    }
    cout << endl;
}

void zigzag(TreeNode* root) {
    cout << "Zigzag Traversal for the binary tree: ";
    int height = getHeight(root);
    bool leftToRight = true;
    for (int i = 1; i <= height; i++) {
        if (leftToRight) {
            printLevel(root, i, true);
        } else {
            printLevel(root, i, false);
        }
        leftToRight = !leftToRight;
    }
    cout << endl;
}


int main() {
    TreeNode* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    dfs(root);
    levelOrder(root);
    zigzag(root);

    

    return 0;
}

//TIME complexity - O(N)
//SPACE complexity - O(N)