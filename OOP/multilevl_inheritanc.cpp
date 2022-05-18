#include <iostream>
using namespace std;

/*
Here a derived class is made from two or more base classes.

                A       B -------------->Base Classes
                \       /
                 \     / 
                  \   /
                    C ------------------> Derived Class
Syntax for multilevel inheritance :

class derived_class_name : visibility mode base1, vidibility mode base 2
{
    class body
};
*/

class Base1
{
protected:
    int baseint1;

public:
    void set_baseline1(int a)
    {
        baseint1 = a;
    }
};

class Base2
{
protected:
    int baseint2;

public:
    void set_baseline2(int a)
    {
        baseint2 = a;
    }
};

/* Here class derived is derived from two base classes named Base1 and Base2
And as both Base classes have visibility mode as public so we can access values of both variables from derived class.
*/
class Derived : public Base1, public Base2
{
public:
    void show()
    {
        cout << "Value of baseint1 is :" << baseint1 << endl;
        cout << "Value of baseint1 is :" << baseint2 << endl;
        cout << "Sum is  :" << baseint1 + baseint2 << endl;
    }
};

int main()
{
    Derived aditya;
    
    aditya.set_baseline1(20);
    aditya.set_baseline2(30);

    aditya.show();
    return 0;
}