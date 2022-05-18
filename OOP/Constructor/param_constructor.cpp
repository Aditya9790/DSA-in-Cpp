#include <iostream>
using namespace std;

// void add(Complex , Complex );
class Complex
{
    int a, b;

public:
    Complex(int, int); // parameterized construction
    void printNum()
    {
        cout << "The number is :" << a << "+" << b << "i" << endl;
    }
    void add(Complex A, Complex B);
};

Complex ::Complex(int x, int y)
{
    a = x;
    b = y;
}

 void Complex :: add(Complex A, Complex B)
{
    cout << "The sum is :" << A.a + B.a << "+" << A.b + B.b <<"i"<<endl;
}

// We neeed not to invoke "Complex(void)" function 
// as it is already invoked while creation of the object.

int main()
{
    // when object c created "Complex(void)" automatically got invoked
    // and values 4 and 6 are passed to the function

    Complex c(4, 6); // implicit call
    c.printNum();

    Complex c1 = Complex(1, 3); // explicit call
    c1.printNum();

    Complex c2(41, 61); // implicit call
    c2.printNum();

  // add(c, c1);
    return 0;
}
