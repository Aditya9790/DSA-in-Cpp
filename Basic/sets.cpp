#include <iostream>
#include <set>
#include <iterator>

using namespace std;
/*
Sets :
Each element must be unique no repetations allowed.

Syntax : set<datatype> set_name; // empty set
set<int> val = {1, 2, 3, 4} // set definition

1. Stores elements in sorted order.
2. All values are unique.
3. Values are immutable.
4. Follows BST implementation.
5. Values are unindexed.

For storing values in descending order:

set<datatype, greater<datatype>> setname;
*/

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(45);
    s.insert(6);
    s.insert(46);
    s.insert(92);
    s.insert(92);

    set<int>::iterator i; // iterator definition for set
    for (i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}