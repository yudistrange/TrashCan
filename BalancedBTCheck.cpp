// Check if the binary tree is balanced or not
// Condition for balanced binary tree => 
// -1 =< Depth of left subtree - Depth of right subtree =< 1 

// @PENDING
#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

int abs(int a)
{	
	return a>0 ? a : -a;
}

bool isBalancedBT(node * root, int &depth)
{
	int ldepth=0, rdepth=0;
	bool l, r;

	if(!root) return true;

	l = isBalancedBT(root->left, ldepth);
	r = isBalancedBT(root->right, rdepth);
	if(!l || !r) return false;
	
	else if(abs(ldepth-rdepth) > 1)
		return false;	

	if(ldepth>rdepth) depth = ldepth+1;
	else depth = rdepth+1;
	
	return true;
}

int main()
{
	BinaryTree bt;
	int n, height = 0;
	while(1) {
		cin>>n;
		if(n<0) break;
		bt.InsertAsBST(n);
	}
	cout<<isBalancedBT(bt.GetRoot(), height);
}
