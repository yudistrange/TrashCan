// Range min Query implementation
// Used to find the minimum between two indices in an array
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> PreProcessRMQ(vector<int> &list)
{
	int sqroot = sqrt(list.size());
	int count  = 0;
	int min    = INT_MAX;
	std::vector<int> v;
	for(int i=0; i<list.size(); i++) {

		if(count >= sqroot) {
			count %= sqroot;
			min    = INT_MAX;
			v.push_back(min);
		}
		if(min>list[i]) min = list[i];
		count++;
	}
}

int main()
{
	int n, temp, i, j;
	vector<int> list, *RMQ;
	cin>>n;
	while(n--) {
		cin>>temp;
		list.push_back(temp);
	}
	RMQ = PreProcessRMQ(list);
	cout<<"\n\nEnter the indices to be queried\n";
	cin>>i>>j;

	
}
