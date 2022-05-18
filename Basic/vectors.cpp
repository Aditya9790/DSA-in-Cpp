/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int size = v.size();

    for(int i=0;i<5;i++)
    {
        v.push_back(i+1); // pushing element in vector
    }

    for(auto j=v.cbegin(); j != v.end(); j++)
    {
        cout<<*j<<" "<<endl;
    }

    v.pop_back(); // remove last element

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
*/

/*
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;


int main() {
    int N, num;
    vector<int>v;
    cin>>N; // size

    for(int i=0;i<N;i++)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cout<<"Before erasing"<<endl;
    for(auto i=v.cbegin();i != v.end();i++)
        cout<<*i<<" ";

    cout<<"After erasing"<<endl;
    v.erase(v.begin()+1);

    for(auto i=v.cbegin();i != v.end();i++)
        cout<<*i<<" ";

    return 0;
}
*/

/*
Index of an element in a vector

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = { 7, 3, 6, 2, 6 };
    int key = 6;

    std::vector<int>::iterator itr = std::find(v.begin(), v.end(), key);

    if (itr != v.cend()) {
        std::cout << "Element present at index " << std::distance(v.begin(), itr);
    }
    else {
        std::cout << "Element not found";
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
/*
Lower Bound : Works on sorted data structure
Returns a pointer.
If the value passed is present in a vector then it returns the value itself.
If such a value is passed that is not present in the vector then it returns a value immediately greater than the element passed.

If such a value is passed that is neither present in array nor the element greater than the value is present then it returns a garbage value.

syntax for lower bound: 
lower_bound(start, end, element_of_interest)
*/
    vector<int> v1;
    v1.push_back(6);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(25);
    v1.push_back(7);
    v1.push_back(8);

    sort(v1.begin(), v1.end());

    for(auto i=v1.begin();i != v1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    auto it = lower_bound(v1.begin(), v1.end(), 24);
    cout<<"Lower Bound: "<<(*it)<<endl;

    /*
    Upper Bound : 
    Returns a element that is immediately greater than the element passed.
    */
   
   cout<<"1 index elem is and "<<v1[1]<<" Address is "<<&v1[1]<<endl;
   cout<<"2 index elem is and "<<v1[2]<<" Address is "<<&v1[2]<<endl;
   
   auto it1 = upper_bound(v1.begin(), v1.end(), 4);
   cout<<"Upper Bound: "<<(&it1)<<endl;
   cout<<"Upper Bound: "<<(*it1)<<endl;

    return 0;
}
