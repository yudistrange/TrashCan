// Linked list ADT
#include "SLinkedList.hpp"
#include<iostream>
using namespace std;


SLinkedList::SLinkedList()
{
	head = NULL;
	size = 0;
}

void SLinkedList::hInsert(int i)
{
	Snode * temp = new Snode;
	temp->val  = i;
	temp->next = head;
	size++;
	head = temp;
	return;
}

void SLinkedList::tInsert(int i)
{
	if(!head) {
		head 	   = new Snode;
		head->next = NULL;
		head->val  = i;
		size++;
		return;
	}

	Snode * temp = head;
	while(temp->next) temp = temp->next;
	temp->next  = new Snode;
	temp    	= temp->next;
	temp->val   = i;
	temp->next  = NULL;
	size++;
}

void SLinkedList::pInsert(int i, int pos)
{
	Snode * temp;
	Snode * newNode;

	if(pos<=0) {
		temp = new Snode;
		temp->val = i;
		temp->next = head;
		head = temp;
		size++;
		return;
	}

	temp = head;
	while (temp->next && --pos) temp = temp->next;
	newNode = new Snode;
	newNode->next = temp->next;
	newNode->val  = i;
	temp->next 	  = newNode;
	size++;
	return;
}

void SLinkedList::Delete(int i)
{
	if(!head) return;
	
	int	pos = Search(i);
	if(pos > 0 && pos <=size) 
		pDelete(pos);
}

void SLinkedList::pDelete(int pos)
{
	if(!head) return;

	Snode * temp = head;
	if(pos==0) {
		head = head->next;
		size--;
		delete temp;
		return;
	}

	while(temp && --pos) temp = temp->next;

	if(!temp->next) return;

	Snode * dnode = temp->next;
	temp->next = dnode->next;
	size--;
	delete dnode;
}

int SLinkedList::Search(int i)
{
	if(!head) return -1;

	Snode * temp = head;
	int pos = 0;
	while(temp) {
		if(temp->val == i)	return pos;
		pos++;
	}
	return -1;
}

int SLinkedList::binSearch(int i)
{
	// TODO
	return -1;
}

Snode * SLinkedList::nSearch(int i)
{
	if(!head) return NULL;

	Snode * temp = head;

	while(temp) {
		if(temp->val == i)	
			return temp;

		temp = temp->next;
	}
	return NULL;	
}

Snode * SLinkedList::getHead()
{
	return head;
}