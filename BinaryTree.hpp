// Binary Tree ADT
struct node {
	int val; 
	node * left;
	node * right;
};

class BinaryTree {
	/**
	 * @name Private members
	 */
private:	
	node * root;

	void Inorder_rec	(node * root);
	void Postorder_rec	(node * root);
	void Preorder_rec	(node * root);

	bool PathWithSum 	(int sum, node * root);

	/**
	 * @name Public members
	 */
public:
	/**
	 * @name Constructrs and Destructors
	 */
	BinaryTree	();
	~BinaryTree	();

	/**
	 * @name Insertion 
	 */
	void Insert 	(int a, node * parent);
	void InsertAsBST(int a);

	/**
	 * @name Recursive Traversals
	 */
	void Inorder 	();
	void Postorder 	();
	void Preorder 	();

	/**
	 * @name Misc Functions
	 */
	bool PathWithSumExists	(int sum);
};