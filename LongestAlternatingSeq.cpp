// Length of longest alternating sequence 
// Note: The input number are to be greater than 0

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, *arr;
	vector<int> list;
	int count = 0, prev;

	while(1) {
		cin>>n;
		if(n<=0) break;
		list.push_back(n);
	}
	arr = new int[list.size()-1];
	for(int i=0; i<list.size()-1; ++i) {
		if((list[i+1] - list[i]) >= 0) arr[i] = 1;
		else arr [i] = 0;
	}
	prev = arr[0];
	for(int i=1; i<list.size()-1; ++i) {
		if(prev != arr[i]) {
			++count;
			prev = arr[i];
		}
	}
	cout<<count<<endl;
	return 0;
}