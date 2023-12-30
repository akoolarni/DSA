#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}  //tree declaration
};


void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal results: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal results: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal results: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}


//TIME complexity - O(N)
//SPACE complexity - O(N)