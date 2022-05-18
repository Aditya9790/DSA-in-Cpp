#include <iostream>
using namespace std;
/*
    Protected is a variable which is private to some extent and can be inherited.
    Protected variable means not private the only difference is that protected member can be inherited.

For protected members : 

    |BaseclassVisibility-->|  Public derivation | Private derivation  | Protected Derivation |
    ---------------------------------------------------------------------------------------|
    |1. Private Members    |  Not Inherited      | Not Inherited      | Not Inherited      |
    |2. Protected Members  |  Protected          | Private            | Protected          |
    |3. Public Members     |  Public             | Private            | Protected          |
    |--------------------------------------------------------------------------------------|
*/
class Base
{
protected:
    int a;
private:
    int b;
public:
    int c;
    void setdata(int A)
    {
        a = A;
        cout<<a<<endl;
    }
};

class Derived : public Base
{
public:
    void getdata()
    {
        cout<<"Protected Member is :"<< a <<endl;
    }

};

int main()
{
    Base b;
    b.setdata(49);
    Derived der; // an object of Derived class derived from base class
    der.getdata();
    
    // below line will throw an error as class Derived is derived in protected mode so even though the variable "a" is inherited in the class Derived we will not be able to access it directly we will need to access it using a function defined in class Derived.

    //cout<<der.a;

    // now even if we try to print variable "c" which is a public we will get an error as it is inherited in protected visibility mode.
    
    //cout<<der.c;


    return 0;
}