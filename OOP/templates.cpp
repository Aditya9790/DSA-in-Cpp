#include<iostream>
using namespace std;
/*
It is basically a parametarized class.
It follows Do Not Repeat principal.
Generic programming

syntax of templates : 

template <class T> T can be int float, char, etc
class class_name
{
    T* arr;
public :
    code body....
    ....
}

int main()
{
    class_name<data type> func_name(param...)
}

different data type can be passed to a template.
*/

// template <typename F>
template <class T>
class vector
{
public:
    T * arr;
    int size;
    vector(int m)
    {
        size = m;
        arr = new T[size]; // malloc in cpp
    }

    T dotProduct(vector &v)
    {
        T d = 0;
        for(int i=0;i < size; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};

int main()
{
    vector <float>v1(3);
    v1.arr[0] = 3.23;
    v1.arr[1] = 10.75;
    v1.arr[2] = 20.12;

    vector <float>v2(3);
    v2.arr[0] = 10.46;
    v2.arr[1] = 2.46;   
    v2.arr[2] = 1.23;

    float a = v1.dotProduct(v2);
    cout<<a<<endl;

    return 0;
}