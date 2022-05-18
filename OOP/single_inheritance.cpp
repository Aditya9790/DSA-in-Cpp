#include <iostream>
using namespace std;

class Base
{
    int data1; // private and not inherited
public:
    int data2;
    void setData();
    int getData1(); // returns data1
    int getData2(); // returns data2
};

void Base ::setData(void)
{
    data1 = 10;
    data2 = 20;
}

int Base ::getData1(void)
{
    return data1; // can access private variable data1 with function getData.
}

int Base ::getData2(void)
{
    return data2;
}

class Derived : public Base // inherited from Base class publically
{
    int data3; // private for Derived
public:
    void process();
    void display();
};

void Derived ::process(void)
{
    data3 = data2 * getData1(); // cannot directly access data1 as it is private for base class so we access it from gatdata1() function.
}

void Derived ::display(void)
{
    cout << "Value of data1 is :" << getData1() << endl; // cannot inherit private variables so accessed using gatData1() function of base class.

    // can access data2 and data3 directly as data 2 is publicaly inherited and data3 is also a public variable defined in Derived class.
    cout << "Value of data2 is : " << data2 << endl;
    cout << "Value of data3 is : " << data3 << endl;
}

int main()
{

    Derived der;   // object of derived class
    der.setData(); // can call set data with help of an onject of Derived as setData() has been inherited from Base class.

    der.process();
    der.display();
    return 0;
}