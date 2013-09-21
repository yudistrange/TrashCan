// Check if a linked list is a Palindrome
#include "SLinkedList.hpp"
#include <iostream>
using namespace std;
bool Palin(Snode ** head, int &size, int &iter, Snode * tail)
{
	bool flag = true;
	if(!iter && tail->next) flag = Palin(head, ++size, iter, tail->next);

	if(iter>size/2) return flag && true;

	if(iter <= size/2) {
		if ((*head)->val != tail->val) return false;
		else {
			*head = (*head)->next;
			iter++;
			return flag;
		}
	}
}

bool isPalin(Snode * head)
{
	int size = 0, iter = 0;
	return Palin(&head, size, iter, head);
}

int main()
{
	SLinkedList list;
	int n, d;
	cin>>n;
	while(n) {
		d = n%10;
		n = n/10;
		list.hInsert(d);
	}
	cout<<isPalin(list.getHead())<<endl;
	return 0;
}