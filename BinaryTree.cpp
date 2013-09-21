// Binary Tree Implementation
#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	node * temp = root;
	// TODO Use a Stack to iterate through
	// the tree and delete all the nodes
}

void BinaryTree::Insert(int a, node * parent)
{
	// TODO We will need a private member function
	// which inserts the node into the tree
}

void BinaryTree::InsertAsBST(int a)
{
	node * temp = root;
	if(!temp) {
		temp = new node;
		temp->val  = a;
		temp->left = temp->right = NULL;
		root = temp;
		return;
	}

	while(temp) {
		if(temp->val > a) {
			if(temp->right) {
				temp = temp->right;
			} else {
				temp->right = new node;
				temp->right->val = a;
				return;
			}
		} else {
			if(temp->left) {
				temp = temp->left;
			} else {
				temp->left = new node;
				temp->left->val = a;
				return;
			}
		}
	}
}

void BinaryTree::Inorder()
{
	node * temp = root;
	Inorder_rec(temp);
}

void BinaryTree::Inorder_rec(node * root)
{
	if(!root) return;
	if(root->left) 	Inorder_rec(root->left);
	cout<<root->val<<"\t";
	if(root->right) Inorder_rec(root->right);	
}

void BinaryTree::Preorder()
{
	node * temp = root;
	Preorder_rec(temp);
}

void BinaryTree::Preorder_rec(node * root)
{
	if(!root) return;
	cout<<root->val<<"\t";
	if(root->left) 	Preorder_rec(root->left);
	if(root->right) Preorder_rec(root->right);	
}

void BinaryTree::Postorder()
{
	node * temp = root;
	Postorder_rec(temp);
}

void BinaryTree::Postorder_rec(node * root)
{
	if(!root) return;
	if(root->left) 	Postorder_rec(root->left);
	if(root->right) Postorder_rec(root->right);	
	cout<<root->val<<"\t";
}

bool BinaryTree::PathWithSumExists(int sum)
{
	node * temp = root;
	return PathWithSum(sum, temp);
}

bool BinaryTree::PathWithSum(int sum, node * root)
{
	if((!root && sum) || (!sum && root)) return false;
	if(sum==root->val && !root->left && !root->right)
		return true;

	return PathWithSum(sum-root->val, root->left) || PathWithSum(sum-root->val, root->right);
}

int main()
{
	BinaryTree B;
	int a, s;
	while(1) {
		cin>>a;
		if(a<0) break;
		B.InsertAsBST(a);
	}
	cin>>s;
	if(B.PathWithSumExists(s))
		cout<<"Path from root to leaf with sum "<<s<<"exists\n";
	else 
		cout<<"No path exists\"n;
	return 0;
}