// Maximum product subarray
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int MaxProd(vector<int> list)
{
	int prod, maxProd, maxNeg;
	prod = maxProd = 1;
	maxNeg = INT_MIN;
	for(int i=0; i<list.size(); i++) {
		if(list[i]<0 && list[i]>maxNeg) 
			maxNeg = list[i];

		if(list[i]==0) {
			if(prod<0) prod = prod/maxNeg;

			if(maxProd<prod) maxProd = prod;

			prod = 1;
			maxNeg = INT_MIN;

		} else {
			prod *= list[i];
		}
	}
	if(prod<0) 		 	prod = prod/maxNeg;
	if(maxProd<prod) maxProd = prod;

	return maxProd;
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
	cout<<MaxProd(list)<<endl;
}