#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>

using namespace std;

struct TreeNode{
        int data;
        struct TreeNode *left;
        struct TreeNode *right;
};

//struct TreeNode *left = NULL;
//struct TreeNode *right = NULL;

int maxPathSum(TreeNode *root , int& max_sum){
        if (root == NULL){
                return 0;
        }

        int left_sum = max(0 , maxPathSum(root -> left , max_sum));
        int right_sum = max(0 , maxPathSum(root -> right , max_sum));

        int maxima = root -> data + max(left_sum, right_sum);
        int maximaReal = root -> data + left_sum + right_sum;

        max_sum = max(max_sum , maximaReal);

        return maxima;
}

int maxPathSum(TreeNode *root){
        int max_sum = INT_MIN;
        maxPathSum(root , max_sum);
        return max_sum;
}

int main(){
 	TreeNode* root = new TreeNode;
    	root->data = -10;
    	root->left = new TreeNode;
    	root->left->data = 9;
    	root->right = new TreeNode;
    	root->right->data = 20;

    	root->right->right = new TreeNode;
    	root->right->right->data = 7;
    	root->right->right = new TreeNode;
    	root->right->right->data = 15;

 
        int finalSum = maxPathSum(root);
        cout << "Maximum path sum of the given tree is : " << finalSum <<
endl;
        return 0;
}

//TIME complexity - O(N)
//SPACE complexity - O(logN)

