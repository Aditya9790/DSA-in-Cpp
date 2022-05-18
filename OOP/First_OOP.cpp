/*
The data is stored in separate templates of their own. 
These templates are known as Classes.
The data present in one class is not accessable by other.
It treates data as a critical element.
Decomposes the entire problem into different objects & 
data and functions are created on top of the objects.

Objects : Run time entities

Data Abstractions : 


Class :  The building block of C++ that leads to Object-Oriented programming is a Class. It is a user-defined data type, which holds its own members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object.
    # Data members are the data variables and member functions are the functions used to manipulate these variables and together these data members and member functions define the properties and behavior of the objects in a Class.
    #In the above example of class Car, the data member will be speed limit, mileage etc and member functions can apply brakes, increase speed etc.

Object : Instance of the class. It has some characteristics and behavior.When class is defined no memory allocated but when it is initiated(object is created) memory is allocated.
Objects can interact without having to know details of each other’s data or code, it is sufficient to know the type of message accepted and type of response returned by the objects.

Encapsulations : Wrapping data and function into single function.Encapsulation is defined as binding together the data and the functions that manipulate them.Encapsulation also leads to data abstraction or hiding. 

Abstraction : Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.

Polymorphism : Ability of a function to take multiple forms.A real-life example of polymorphism, a person at the same time can have different characteristics. Like a man at the same time is a father, a husband, an employee. So the same person posses different behavior in different situations. 
    Type 1: Compile Time
            Function Overloading
            operator Overloading

Inheritance : Properties of one class can be inherited into other.The capability of a class to derive properties and characteristics from another class is called Inheritance.
    Sub Class: The class that inherits properties from another class is called Sub class or Derived Class. 
    Super Class: The class whose properties are inherited by sub class is called Base Class or Super class. 

*/

#include <iostream>
using namespace std;

class Employee // Name of the class is employee
{
private:
    // private variables can only be accessed by function created inside
    // the class
    // here function is setData.
    int a, b, c;

public:
    int d, e;
    void setData(int a1, int b1, int c1); // Function Declared
    //cout<<"Privare variable a is :"<<a<<endl;
    void getData()
    {
        cout << " The value of a is :" << a << endl;
        cout << " The value of b is :" << b << endl;
        cout << " The value of c is :" << c << endl;
        cout << " The value of d is :" << d << endl;
        cout << " The value of e is :" << e << endl;
    }
};

// To call a function created in a given class
// Syntax is == "class_name :: func_name(*, *, *)"
void Employee ::setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Employee aditya; // "aditya" is an object of class Employee
    // access a function created in employee class with help of object aditya
    aditya.setData(1, 2, 10);
    cout<<sizeof(aditya);

    // we can access variables "d" and "e" by calling them with object
    // as they are public variables
    // but we cannot access variable a, b or c using obj_name.a
    // as we have declard a, b and c as private variables
    // and they can only be accessed by the function created in the class.
    aditya.d = 20;
    aditya.e = 100;

    aditya.getData();
    return 0;
}

/*
class car
{
    string name;
    int reg_number;

    public:
        int car_number;
        void getDetails(string name, int reg_number);
        
};

void car ::getDetails(string name, int reg_number)
{
    cout<<"Car name is : "<< name <<endl;
    cout<<"Car's number is : "<<reg_number <<endl;
}

int main()
{
    car c1; // object of class car

    string name = "Mecedese";
    int reg_number = 2791;

    c1.car_number = 100;
    cout<<"This is "<<c1.car_number<<"th car."<<endl;
    c1.getDetails(name, reg_number);
}*/