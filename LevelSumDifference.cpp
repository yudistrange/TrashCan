// Calculate the difference between the sum of nodes at odd height
// and the nodes at even height in a binary tree

#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

void LevelSumDiff(node * root, int height, int &even, int &odd)
{
	if(!root) return;

	if(height%2) odd+=root->val;
	else even+=root->val;

	LevelSumDiff(root->left, height+1, even, odd);
	LevelSumDiff(root->right, height+1, even, odd);
}

int main()
{
	BinaryTree bt;
	int n, height = 1;
	int even=0, odd=0;
	while(1) {
		cin>>n;
		if(n<0) break;
		bt.InsertAsBST(n);
	}
	LevelSumDiff(bt.GetRoot(), height, even, odd);
	cout<<even-odd<<endl;
	return 0;
}