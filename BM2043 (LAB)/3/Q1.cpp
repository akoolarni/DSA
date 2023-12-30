#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data){
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}

int findHeight(struct node *root){
	if(root == NULL){
		return -1;
	}

	int leftheight = findHeight(root->left);
	int rightheight = findHeight(root->right);

	return (leftheight>rightheight) ? leftheight+1 : rightheight+1;
}

int findDiameter(struct node *root){
	if(root == NULL){
		return -1;
	}

	int leftheight = findHeight(root->left);
	int rightheight = findHeight(root->right);

	int leftdiameter = findDiameter(root->left);
	int rightdiameter = findDiameter(root->right);

	int maxDiameter = (leftdiameter > rightdiameter) ? leftdiameter : rightdiameter;
    maxDiameter = (leftheight + rightheight + 2 > maxDiameter) ? leftheight + rightheight + 2 : maxDiameter;

	return maxDiameter;

}



int main(){
	struct node* root = newNode(4);                     
	root->left = newNode(2);
	root->right = newNode(6);



	struct node* node1 = newNode(1);
	root->left->left = node1;
	struct node* node2 = newNode(7);
	root->left->right = node2; 
	
	//struct node* node3 = newNode(5);
	//root->right->left = node3;
	//struct node* node4 = newNode(8);
	//root->right->right = node4;
	//
	//struct node* node5 = newNode(10);
	//root->left->left->left = node5;
	//struct node* node6 = newNode(50);
	//root->left->left->right = node6;


	int height = findHeight(root);
	int diameter = findDiameter(root);

	cout << "The height of the binary tree is: " << height << endl;
	cout << "The diameter of the binary tree is: " << diameter << endl;



	return 0;
}

//TIME complexity - O(N)
//SPACE complexity - O(logN) 