// Longest common substring

#include<iostream>
using namespace std;
int main()
{
	string s1, s2;
	int **a;
	cin>>s1>>s2;
	a = new int *[s1.size()+1];
	for(int i=0; i<=s1.size(); i++) {
		a[i] = new int[s2.size()+1];
	}

	for(int i=0; i<=s1.size(); ++i) {
		for(int j=0; j<=s2.size(); ++j) 
			a[i][j] = 0;
	}

	for(int i=0; i<=s1.size(); ++i) {
		for(int j=0; j<=s2.size(); ++j) 
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

	int max = 0
;	for(int i=1; i<=s1.size(); ++i) {
		for(int j=1; j<=s2.size(); ++j) {
			if(s1[i-1]==s2[j-1]) {
				a[i][j] = a[i-1][j-1] + 1;
				if(max < a[i][j]) max = a[i][j];
			}
		}
	}
	cout<<"\n\nLength = "<<max<<endl;
	return 0;
}