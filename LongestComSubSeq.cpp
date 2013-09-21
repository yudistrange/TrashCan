//Longest subsequnce
#include<iostream>
using namespace std;

int maxi(int a, int b)
{
	return (a>b)?a:b;
}

int main()
{
	string s1, s2;
	int max =0;
	cin>>s1>>s2;

	int ** a = new int * [s1.size()+1];
	for(int i=0; i<=s1.size(); ++i) {
		a[i] = new int[s2.size()+1];
	}

	for(int i=0; i<=s1.size(); ++i) {
		for(int j=0; j<=s2.size(); ++j) 
			a[i][j] = 0;
	}

	for(int i=1; i<=s1.size(); ++i) {
		for(int j=1; j<=s2.size(); ++j) {
			if(s1[i]==s2[j]) 
				a[i][j] = a[i-1][j-1] + 1;
			else 
				a[i][j] = maxi(a[i-1][j], a[i][j-1]);

			if(max < a[i][j]) max = a[i][j];
		}
	}
	cout<<max<<endl;
	return 0;
}