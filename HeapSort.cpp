/**
 * This Program implements the Heapsort using a binary heap
 *
 */

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

class PriorityQueue 
{
    int * heap;
    int alloc_size;
    int size;
  
public:
    PriorityQueue();
    PriorityQueue(int n);
    bool Check(int i, int j);
    void Insert(int n);
    void Swim(int n);
    void Sink(int n);
    void HeapSort();
    void swap(int a, int b);
};

PriorityQueue::PriorityQueue()
{
    alloc_size = 0; 
    size = 0;
    heap = NULL;
}

PriorityQueue::PriorityQueue(int n)
{
    alloc_size = n;
    size = 0; 
    heap = new int[n+1];
}

bool PriorityQueue::Check(int i, int j)
{
    return heap[i] < heap[j];
}

void PriorityQueue::swap(int i, int j)
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
    return;
}


void PriorityQueue::Swim(int n)
{
    
}

void PriorityQueue::Sink(int n)
{
 
}

void PriorityQueue::HeapSort()
{
    int max;
    while(size>0) {
	max = heap[1];
	heap[1] = heap[size--];
	Sink(1);
	cout<<max<<endl;
    }
}

void PriorityQueue::Insert(int n)
{
    heap[++size] = n;
    Swim(size);
}

int main()
{
    int temp;
    PriorityQueue myQueue(100);
    while (scanf("%d", &temp))
    {
	myQueue.Insert(temp);
    }
    myQueue.HeapSort();
    return 0;
}