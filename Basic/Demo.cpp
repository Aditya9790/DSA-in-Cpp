/*
#include<iostream>
using namespace std;

int main()
{
    string name;

    cout<<"What is your name your name:";
    getline(cin,name); // read entire line until you press enter.
    cout<<"Welcome Mr."<<name<<".";
    return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> parseInts(string str)
{
    stringstream ss(str); // stringstreams function
    vector<int> out; // output vector
    char ch;
    int temp;

    while(ss>>temp)
    {
        out.push_back(temp);
        ss >> ch;
    }
    return out;
}

int main()
{
    string str;
    cin>>str;

    vector<int> integers = parseInts(str);
    for(int i=0; i<integers.size(); i++)
        cout<<integers[i]<<endl;
    return 0;
}
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Box
{
  int l, b, h; // private
  public:
    Box(void); // default constructor
    Box(int, int, int);// paramaterized constructor
    Box(const Box &B) // copy constructor
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }
    
    int getLength(void);
    int getBreadth(void);
    int getHeight(void);
    long long CalculateVolume(int l, int b, int h);
};

Box ::Box(void) // default conctructor
{
    l=0; b=0; h=0;
}

Box ::Box(int a, int b_, int c) // paramaterized constructor
{
    a = l;b_ = b; c = l;
}

int Box::getLength(void)
{
    return l;
}

int Box::getBreadth(void)
{
    return b;
}

int Box::getHeight(void)
{
    return h;
}

long long Box::CalculateVolume(int l, int b, int h)
{
    return ((long long)l*b*h);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 


    return 0;
}

    