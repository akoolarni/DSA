#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

struct TreeNode *createNode(int new_data){
    struct TreeNode *new_node = new TreeNode;
    new_node -> data = new_data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

bool BinarySearchTreeCheck(TreeNode *root, TreeNode *temp = NULL){
    if(root == NULL){
        return true;
    }

    if(!BinarySearchTreeCheck(root -> left, temp)){
        return false;
    }

    if(temp != NULL && root -> data <= temp -> data){
        return false;
    }

    temp = root;

    return BinarySearchTreeCheck(root -> right , temp);

}

int main(){
    TreeNode *root = createNode(3);
    root -> left = createNode(5);
    root -> right = createNode(2);
    root -> left -> left = createNode(1);
    root -> left -> right = createNode(4);
    root -> right -> left = createNode(6);


    if(BinarySearchTreeCheck(root)){
        cout << "The tree is a Binary Search Tree." << endl;
    }

    else{
        cout << "The tree is not a Binary Search Tree." << endl;
    }

    return 0;

    
    
}

//TIME complexity - O(N)
//SPACE complexity - O(logN) worst case O(N)