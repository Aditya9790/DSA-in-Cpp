#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	
	int compare = s1.compare(s2);
	if (compare > 0)
		cout << 1;
	else if (compare == 0)
		cout << 0;
	else
		cout << -1;
	return 0;
}