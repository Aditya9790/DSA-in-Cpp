
#include <cstring>
#include <iostream>
#include<ctype.h>
#include<algorithm>
using namespace std;

int main()
{
    string str1("COEP PUNE Baramati");
    cout<<str1<<endl;
    cout<<str1.substr(0, 2)<<endl; // slicing of string
    cout<<str1[str1.length() - 1]<<endl; // indexing in string

    // Check if a character is present in string
    // npos is retured by function when they fail to perform the given task. here we exploit this property and tell the code to print Found if they do not fail, i.e. the element is found.
    string temp = "Aditya";
    if(temp.find("a") != string::npos)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    // Convert all to uppercase pr lowercase
    // SYntax : transform(s.begin(), s.end(), s.begin(), ::toupper/tolower)

    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

    // string str ="python";
    // cout<<"String value is :"<<str<<'\n';
    // str.resize(9,'tut');
    // cout<<"After resizing, string value is :"<<str<<endl;

    // string a = ""; // we can add a string to a string as we did in python
    // a.append("Parker");
    // cout<<a + " Peter"<<endl;

    // string b = "I ate an red Apple"; // find the pattern
    // cout << b.find("ate") << endl;

    // // initialise char with specific number of occurrance
    // string str2(4, '^');
    // cout<< str2<<endl;

    //
    // string str3(str1, 6);
    // cout<<str3<<endl;

    // // initialization by part of another string : iterator version
    // string str4(str1.begin(), str1.begin()+6);
    // cout<<str4<<endl;

    // // clear function deletes all character from string
    // str4.clear();
    // cout<<str4<<endl;

   // string str  = "College Of Engineering Pune";
    // cout<<"String is :"<<str<<endl;
    // str.resize(5); // resize string to size 5
    //cout<<"String after resizing is :"<<str<<endl;

    // cout<<"Length of string :"<<str.length()<<endl;
    // cout << "The capacity of string is : "<<str.capacity() << endl;

    // Iterator in string
    // for(auto i=str.begin(); i!= str.end(); i++)
    //     cout<<*i;
    return 0;
}


// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     int N, Q;
//     string temp;
//     cin>>N>>Q;
//     for(int i=0;i<N;i++)
//     {
//       cin>>temp;
//       temp += "\n";
//     }

//     for(int i=0;i<temp.length(); i++)
//         cout<<temp[i];
//     return 0;
// }
