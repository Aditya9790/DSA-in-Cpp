#include <iostream>
using namespace std;

class Complex
{
    int a, b, c;

public:
    Complex(){};
    Complex(int x, int y) // Constructor declaration
    {
        a = x;
        b = y;
    }
    Complex(int x1, float y1)
    {
        a = x1;
        b = y1;
        // c = z;
    }
    void printNum()
    {
        cout << "The number is :" << a << "+" << b << "i" << endl;
        cout<<c<<endl;
    }
};

int main()
{
    Complex c(4, 6);
    c.printNum();

    Complex c1(5, 0.44);
    c1.printNum();
    return 0;
}