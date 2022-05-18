#include <iostream>
using namespace std;

/*
Operator overloading means specifying more then one definition for an operator in same scope.
It's a type of polymorphism, which enhances functionality of operator.

Following operators cannot be overloaded in C++:
    1. Scope Resolution (::)
    2. sizeof
    3. Member Selector or Dot operator (.)
    4. Member pointer (*)
    5. Ternary operator (?:)
*/
class Complex
{
private:
    int real, img;
public:
    Complex() // default constructor
    {
        real = 0; img = 0;
    }

    Complex(int r, int i) // paramaterized constructor
    {
        real = r;
        img = i;
    }

    void print() // display complex number
    {
        cout<<real<<" + "<<img<<"i"<<endl;
    }

    // Operator overloading

    /*
    Syntax for operator overloading : 
        class_name operator symbol_of_operator(object of the class this is optional)
        here, 
        class_name = Complex
        symbol_of_operator = +
        object of the class = Complex c

    */
    friend Complex operator +(Complex c, Complex d)
    {// this is binary operator as it oprates on two operands.
        Complex temp;
        temp.real = d.real + c.real;
        temp.img = d.img + c.img;
        return temp;
    }
};

int main()
{
    Complex c1(3, 4);
    Complex c2(5, 4);
    Complex c3(1, 4);
    Complex c4;
    
    // Below line will throw error if operator overloading nopt used as the program does not know how to add complex numbers so we need to change the functionality of conventional "+/Plus" operator such that it will be able to add complex numbers also.
    // c4 = c1+c2+c3;
    // c1.print();
    // c2.print();
    // c3.print();
    c4.print();
    return 0;
}