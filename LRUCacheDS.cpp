// Data structure which will keep the most recent 'n' unique integers
// and which supports delete, search and insert in order 1.
// 
// Upon overflow it should release the least recently used integer.
#include <iostream>
#include <map>
using namespace std;

class LRUCache {
private:
	int 	size;
	int 	index;
	int *	pool;
	map <int, int>  hashmap;

	void	Rearrange	(int n);

public:
	LRUCache(int n);

	bool 	Add		(int n);
	bool	Delete 	(int n);
	int 	Search 	(int n);
	void 	Status	();
};

LRUCache::LRUCache(int n)
{
	size  = n;
	pool  = new int[n];
	index = 0;
}

void LRUCache::Rearrange(int n)
{
	int i;
	for(i=n; i<size-1; i++)
		pool[i] = pool[i+1];

	index = i;
}

bool LRUCache::Add (int n)
{
	pair<map<int, int>::iterator, bool> check;
	map<int, int>::iterator iter;
	check = hashmap.insert(make_pair<int, int>(n, index));
	if(check.second) {
		int prev = pool[index];
		iter = hashmap.find(prev);
		if(iter != hashmap.end()) {
			hashmap.erase(iter->first);
		}
		pool[index++] = n;
		index %= size;
		return true;
	}
	return false;
}

int LRUCache::Search(int n)
{
	map<int, int>::iterator iter;
	iter = hashmap.find(n);
	if(iter != hashmap.end()) {
		return iter->second;
	}
	return -1;
}

bool LRUCache::Delete(int n)
{
	map<int, int>::iterator iter;
	int i;
	
	iter = hashmap.find(n);
	if(iter != hashmap.end()) {
		i = iter->second;
		hashmap.erase(iter->first);
		Rearrange(i);
		return true;
	}
	return false;
}

void LRUCache::Status()
{
	for(int i=0; i<size; i++) {
		if(i != index) cout<<pool[i]<<"\t";
	}
	cout<<"\n";
}

int main()
{
	LRUCache * c;
	int n, i;
	cin>>n;
	c = new LRUCache(n);
	while(1) {
		cin>>i;
		if(i<0) break;
		if(c->Add(i)) cout<<"Added successfully\n";
		else cout<<"Duplicate exists\n";
	}
	c->Status();
	return 0;
}