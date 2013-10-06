// Program to check whether all the leaves of a binary tree are on the same level

#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

bool isTreeLevel(node * root, int & depth, int currdepth) 
{
	if(!root) return true;

	if(!root->left && !root->right) { // Is a leaf node
		if(depth == -1) depth = currdepth;
		else if(depth!=currdepth) return false;
		else return true;
	}

	return isTreeLevel(root->left, depth, currdepth+1) && isTreeLevel(root->right, depth, currdepth+1);
}

int main()
{
	BinaryTree bt;
	int n, depth = -1, currdepth = 0;
	while(1) {
		cin>>n;
		if(n<0) break;
		bt.InsertAsBST(n);
	}
	cout<<isTreeLevel(bt.GetRoot(), depth, currdepth);
	return 0;
}