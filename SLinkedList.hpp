struct Snode {
	int val;
	Snode * next;
};

class SLinkedList {
private:
	Snode * head;
	int 	size;

public:
	SLinkedList	();

	Snode * getHead		();

	void 	hInsert		(int i);
	void 	tInsert		(int i);
	void 	pInsert		(int i, int pos);

	void 	Delete 		(int i);
	void 	pDelete		(int pos);

	int  	Search 		(int i);
	int  	binSearch	(int i);
	Snode * nSearch 	(int i);
};
