// Dutch flag problem
// Given an array containing 0, 1 and 2. Sort it in place so that the array becomes
// 000..111..222.. or in other words tricolored dutch flag. (Can be called the french flag too for that matter)

#include <iostream>
using namespace std;

void CreateDutchFlag(string &s)
{
	int low, mid, high;
	low  = 0; 
	mid  = 0;
	high = s.size()-1;

	while(mid<high) {
		if(s[mid]=='0') {
			s[mid] = s[low];
			s[low] = '0';
			mid++, low++;
		} else if(s[mid]=='1') {
			mid++;

		} else if(s[mid]=='2') {
			s[mid] = s[high];
			s[high] = '2';
			high--;
		}
	}
}

int main()
{
	string s;
	cin>>s;
	CreateDutchFlag(s);
	cout<<s<<endl;
	return 0;
}
