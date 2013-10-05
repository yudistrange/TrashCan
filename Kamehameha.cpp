// Byteland matrix contains demons at particular locations
// Need to find the minimum laser fires we need to kill them all

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int LaserTag(bool * mat, int size);

int main()
{
	int n;
	bool *mat, temp;
	cin>>n;
	mat = new bool[n*n];
	memset(mat, 0, n*n);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>temp;
			mat[i*n+j] = temp;
		}
	}
	cout<<LaserTag(mat, n);
	return 0;
}

struct monsters {
	int  num;
	char id;
	vector<int> pos;
};

bool mySort(monsters a, monsters b)
{
	if(a.num>b.num) return true;
	return false;
}

void PrintStats(vector<monsters> &list)
{
	cout<<"\nPrint statistics\n";
	for(int i=0; i<list.size(); i++) {
		cout<<list[i].num<<"\t";
		for(int j=0; j<list[i].pos.size(); j++)
			cout<<list[i].pos[j]<<" ";
		cout<<endl;
	}
	cout<<"\nEnd statistics\n\n";
}

int CleanUp(vector<monsters> &list)
{
	int count = 0;
	for(int i=0; i<list.size(); i++) {
		list[i].num = 0;
		for(int j=0; j<list[i].pos.size(); i++) {
			int index = list[i].pos[j];
			// TODO 
			// how to access the correct col/row number here?
			// we can devise some sort of id like c1/r1 but how to traverse in that case?
		}
	}
}	

int LaserTag(bool * mat, int size)
{
	vector<monsters> list(size*2);
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			if(mat[i*size+j]) {
				list[i].num++;
				list[i].id = 'r';
				list[i].pos.push_back(j);
				list[size+j].num++;
				list[size+j].id = 'c';
				list[size+j].pos.push_back(i);
			}
		}
	}
	sort(list.begin(), list.end(), mySort);
	PrintStats(list);

	return 0;
}