#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &vec, int tem)
{
    // if elem to insert i.e. array is empty simply insert in array
    // or if element is greater thrn the  largest element in array then insert at last
    if (vec.size() == 0 || tem >= vec[vec.size() - 1])
    {
        vec.push_back(tem);
        return;
    }

    // if that's not the case then pop the last element and again call recursion i.e. reduce the input and again call function recursively.
    int last = vec[vec.size() - 1];
    vec.pop_back();
    insert(vec, tem);
    vec.push_back(last); // after insertion of tem at right place put the last element "last" that was popped in last index of array
}

void sort(vector<int> &vec)
{
    int len = vec.size();
    // if only 1 element in array return
    // base case for recursion
    if (vec.size() == 1)
        return;

    // recursively call fuction by decreasing the size of very
    // by once in every iteration
    int tem = vec[len - 1]; // store the last element in tem variable

    // remove last element ans call sort again
    // size of ve c reduced by 1.
    vec.pop_back();
    sort(vec);
    // after calling sort we need to insert the last element that
    // is poppped into it's right place to do so right a insert
    // function tht inserts the last element in right place
    insert(vec, tem);
}

int main()
{
    vector<int> vec = {5, 2, 1, 0, 10};
    sort(vec);
    // for(auto &i:vec) cout<<i<<" ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    return 0;
}