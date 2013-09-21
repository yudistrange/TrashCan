// Maximum product subarray
#include<iostream>
#include<vector>
using namespace std;

int MaxProd(vector<int> list)
{
	return 0;
}

int main()
{
	vector<int> list;
	int num, n;
	cin>>num;
	while(num--) {
		cin>>n;
		list.push_back(n);
	}
	cout<<MaxProd(list);
}