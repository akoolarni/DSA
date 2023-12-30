#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}  // tree declaration
};


Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}


void Smallest(Node* root, int& count, int k, Node*& result) {
    if (root == nullptr || count >= k) {
        return;
    }
    
    Smallest(root->left, count, k, result);
    
    count++;
    if (count == k) {
        result = root;
        return;
    }
    
    Smallest(root->right, count, k, result);
}

Node* kthSmallest(Node* root, int k) {
    int count = 0;
    Node* result = nullptr;
    Smallest(root, count, k, result);
    return result;
}


void Largest(Node* root, int& count, int k, Node*& result) {
    if (root == nullptr || count >= k) {
        return;
    }
    
    Largest(root->right, count, k, result);
    
    count++;
    if (count == k) {
        result = root;
        return;
    }
    
    Largest(root->left, count, k, result);
}

Node* kthLargest(Node* root, int k) {
    int count = 0;
    Node* result = nullptr;
    Largest(root, count, k, result);
    return result;
}


Node* lowestCommonAncestor(Node* root, int p, int q) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->data > p && root->data > q) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->data < p && root->data < q) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}


void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    
  
    
    int k = 3;
    Node* kth_smallest = kthSmallest(root, k);
    if (kth_smallest != nullptr) {
        cout << "Kth Smallest Element: " << kth_smallest->data << endl;
    } else {
        cout << "Kth Smallest Element not found!" << endl;
    }
    
    Node* kth_largest = kthLargest(root, k);
    if (kth_largest != nullptr) {
        cout << "Kth Largest Element: " << kth_largest->data << endl;
    } else {
        cout << "Kth Largest Element not found!" << endl;
    }
    
    int p = 20, q = 40;
    Node* lca = lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << ": " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found!" << endl;
    }
    
    int key_to_delete = 30;
    root = deleteNode(root, key_to_delete);
    
    cout << "Inorder Traversal after deleting " << key_to_delete << ": ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}

//TIME complexity - O(logN) worst case O(Ns)
//SPACE complexity - O(N)