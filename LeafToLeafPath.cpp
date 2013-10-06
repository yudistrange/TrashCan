// Longest leaf to leaf path in a binary tree
// @FINISHED

#include "BinaryTree.hpp"
#include <iostream>

using namespace std;

int HelperFunc(node * root, int &path)
{
	if(!root) return 0;
	int leftB  = HelperFunc(root->left, path);
	int rightB = HelperFunc(root->right, path);
	if(path < leftB + rightB + 1) path = leftB + rightB + 1;

	return leftB > rightB ? leftB + 1 : rightB + 1;
}

int LongestLeafPath(node * root)
{
	int path = 0, branch;
	branch = HelperFunc(root, path);
	return path;
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
	cout<<LongestLeafPath(B.GetRoot())<<endl;
	return 0;
}