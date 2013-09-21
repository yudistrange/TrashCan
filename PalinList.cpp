// Check if a linked list is a Palindrome
#include "SLinkedList.hpp"
#include <iostream>
using namespace std;

bool isPalin(SLinkedList * pList)
{

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
	cout<<isPalin(&list)<<endl;
	return 0;
}