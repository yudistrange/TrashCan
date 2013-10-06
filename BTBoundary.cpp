// Print the boundary of a binary tree

#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

void PrintBoundaryHelper(node * root, bool isLeft, bool isRight)
{
	if(!root) return;

	if(isLeft || isRight) cout<<root->val<<"\t";

	else if(!root->left && !root->right) cout<<root->val<<"\t";

	PrintBoundaryHelper(root->left, isLeft, false);
	PrintBoundaryHelper(root->right, false, isRight);
}

void PrintBoundary(node * root)
{
	if(!root) return;
	cout<<root->val<<"\t";
	PrintBoundaryHelper(root->left, true, false);
	PrintBoundaryHelper(root->right, false, true);
	cout<<"\n";
}

int main()
{
	BinaryTree bt;
	int n;
	while(1) {
		cin>>n;
		if(n<0) break;
		bt.InsertAsBST(n);
	}
	PrintBoundary(bt.GetRoot());
	return 0;
}