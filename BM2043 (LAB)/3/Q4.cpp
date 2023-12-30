#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}  //tree declaration
};

Node* findLCA(Node* root, int p, int q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == p || root->data == q) {
        return root;
    }

    Node* leftLCA = findLCA(root->left, p, q);
    Node* rightLCA = findLCA(root->right, p, q);

    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}


int main() {

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    //root->right->right = new Node(8);
    //root->left->right->left = new Node(7);
    //root->left->right->right = new Node(4);

    int p = 1;
    int q = 7;
    Node* lca = findLCA(root, p, q);

    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is " << lca->data << endl;
    } else {
        cout << "The given nodes do not have LCA. " << endl;
    }

 
    return 0;
}


//TIME complexity - O(N)
//SPACE complexity - O(N)