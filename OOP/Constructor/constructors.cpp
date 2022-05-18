#include <iostream>
using namespace std;

// /* Constructor is a special member function, with same name as the class
// Used to initialise the object of it's class.

// It is automatically invoked when the object is created.

// Should be declared as public.
// There do not have return type.
// */

// class Complex
// {
//     int a, b;

// public:
//     Complex(void); // Constructor declaration
//     void printNum()
//     {
//         cout << "The number is :" << a << "+" << b << "i" << endl;
//     }
// };

// // while writing function for constructor declaration we do not need to
// // write the return data type as we did while calling a function
// // inside a class.

// Complex ::Complex(void) // This is default constructor as takes no input arguments
// {
//     a = 10;
//     b = 20;
// }


// // We neeed not to invoke "Complex(void)" function 
// // as it is already invoked while creation of the object.
// int main()
// {
//     // when object c created "Complex(void)" automatically got invoked
//     Complex c;

//     c.printNum();
//     return 0;
// }

class A
{
    public:
    A()
    {
        cout<<"Hii"<<endl;
    }
};

int main()
{
    A a1, a2, a3;
    return 0;
}