// First unique character in a stream of characters
//
// @NOTE
// The stream cannot be read more than once. Stream has two interfaces getNext and hasNext.
// getNext returns the next character in the stream
// hasNext returns whether the stream has any more characters left.

#include <iostream>
#include <map>

#define INT_MAX 100000000

using namespace std;

class Stream {
private:
	string byteStream;
	int pos;
public:
	Stream(string s);
	char getNext();
	bool hasNext();
};

Stream::Stream(string str)
{
	byteStream = str;
	pos = 0;
}

char Stream::getNext()
{
	return byteStream[pos++];
}

bool Stream::hasNext()
{
	return pos < byteStream.size();
}

// Get Unique char function implementation
char GetUniqueChar(Stream &s)
{
	if(!s.hasNext()) return '#';
	char c;
	int pos = 0;

	map<char, int> myMap;
	map<char, int>::iterator iter;
	pair<map<char, int>::iterator, bool> check;

	while(s.hasNext()) {
		c = s.getNext();
		check = myMap.insert(std::make_pair<char, int>(c, pos));
		pos++;
		if(!check.second) {
			myMap[c] = -1;
		}
	}
	int min = INT_MAX;
	for(iter = myMap.begin(); iter!=myMap.end(); ++iter) {
		if(iter->second >= 0 && iter->second < min) {
			min = iter->second;
			c   = iter->first;
		}
	}
	return c;
}

int main()
{
	string s;
	Stream * str;
	cin>>s;
	str = new Stream(s);
	cout<<GetUniqueChar(*str)<<endl;
	return 0;
}