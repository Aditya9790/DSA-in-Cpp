#include<iostream>
using namespace std;

template <class T>

class addition
{
private:
    T a, b, sum;
public:
    void setdata(T x, T y);
    void add();
};

template <class T>
void addition <T> :: setdata(T x, T y)
{
    a = x;
    b = y;
}

template <class T>
void addition <T> :: add()
{
    cout<<a+b<<endl;
}

int main()
{
    addition <int> A;
    addition <float> B;
    A.setdata(10, 20);
    B.setdata(1.2, 2.9);
    A.add();
    B.add();
    return 0;