#include <iostream>
#include <string>
using namespace std;
int main()
{
	string long_word;
	int num; // stores length of middle words
	cin>>num; //take input 

	for(int i=0;i<num;i++)
	{
		cin>>long_word;
		if (long_word.length()>10)
		{
			cout<<long_word[0]<<long_word.length()-2<<long_word[long_word.length()-1]<<endl;;
		}
		else
			cout<<long_word<<endl;
	}
	return 0;
}
