/*
STL has :
1. Containers : It contains predefined data structures, also are objects that hold data of same kind.
Types of Containers :
    a. Sequence Containers : Stores data in linear fashion. Examples : vectors, list, dqueue(double ended queue).

    Vector : Insertion and Deletion slow
    Insertion at end fast

    List : Insertion Fast
    Deletion and Insertion Fast.

    b. Assocative Container : Gives faster access to element. Also provide direct access. Ex : Set, Multiset, Map, Multimap. All operations fast except Random Access. As stores element in Tree Data Structure.

    c. Derived Container : These can be derived from other two  containers. Gives best methods, and gives best model of real world. Ex : Stack, Queue, Priority Queue.

2. Algorithm
3. Iterator

*/
// Vector
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void printlist(list<int> mylist)
{
    list<int>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}

int main()
{
    // vector<int> v;
    // int elem;
    // vector <int> ::iterator j;
    // for(auto i=0;i<5;i++)
    // {
    //     cin>>elem;
    //     v.push_back(elem);
    // }

    // cout<<"--------------"<<endl;
    // for(j=v.begin();j!=v.end();j++)
    // {
    //     cout<<*j<<endl;
    // }

    // for(int value:v)
    // {
    //     cout<<value<<" ";
    // }

    // std::list<int> mylist = {1, 1, 2, 3};
    // cout << "List elements are: ";
    // printlist(mylist);
    // mylist.push_front(0);
    // mylist.push_back(5);
    // cout << "\nList contents after push_front and push_back: ";
    // printlist(mylist);
    // int a = mylist.front();
    // cout << a;
    // cout << endl;
    // mylist.pop_front();
    // mylist.pop_back();
    // printlist(mylist);
    vector <int> v={1,2,3,4,5,6};
 for(int i=0;i<v.size();i++)
 {
 cout<<v[i]<<" ";
 }
 cout<<endl;
 for(auto it : v){
 cout<<(it)<<" ";
 }


    return 0;
}