/*
Inheritance : Properties of one class can be inherited into other.The capability of a class to derive properties and characteristics from another class is called Inheritance.
    Sub Class: The class that inherits properties from another class is called Sub class or Derived Class.
    Super Class: The class whose properties are inherited by sub class is called Base Class or Super class.

Type of inheritance :
1) Single Inheritance : A derived class can inherit from only single base class.

2) Multiple Inheritance : Here a class can inherit from more than one class. One subclass inherited from more than one base classes. The constructors of inherited classes are called in the same order in which they are inherited.
The destructors are called in reverse order of constructors.

3)Multilevel Inheritance : Here a derived class is created from another derived class. A-->B-->C.

4) Hierarchical Inheritance : More than one sub class is inherited from a single base class i.e. more than one derived class is created from a single base class.

*/

#include <iostream>
using namespace std;

// base class aka Parent class
class Employee
{
    int id;
    // float salary;

public:
    float salary, num;
    Employee(int inpId) // constructor
    {
        id = inpId;
        salary = 30.00;
    }
    Employee(){}; // default constructor
};

/* derived Class aka child class
syntax for inheriting class
class derived_class_name(child class) : visibility_mode base_class_name(parent class)
{
    class members.....
}

Visibility mode = The mode in which we want to inherit the derived class.
It can be of two types public and private.

1. If inherited PUBLICALLY then public members of base class(parent class) become PUBLIC members of derived class(child class).

2. If inherited PRIVATELY then the public members of base class(parent class) become the PRIVATE members of derived class(child class) and cannot be accessed directly with the object of derived class.

Default visibility mode is PRIVATE.

In any case we cannot inherit private members of the base class(parent class).
*/

// A derived class named programmer is created
class Programmer : private Employee // inherited from employee privately
{
public:
    int languageCode = 9, Pid;
    Programmer(int inpId)
    {
        Pid = inpId;
    }
    void getData()
    {
        num=78.66;
        cout << "Employee Id is : " << Pid << endl;
        cout<<num<<endl;
    }
};

int main()
{
    Employee harry(1), aditya(2);
    cout << harry.salary << endl;
    cout << aditya.salary << endl;

    Programmer skillF(1);
    cout << "Language Code is : " << skillF.languageCode << endl; // Public variable of programmer
    skillF.getData();

    // As we have inherited Programmer privately so we cannot call skillF.id as id is a public variable for base class but as it is iherited privately id becomes private variable for Programmer class.

    // cout<<skillF.num<<endl;
    return 0;
}

/*
When we call skillF(1) then it goes to class programmer and updated it's id but as Programmer is derived from Employee class so the code tries to call the default constructor of class Employee.

If default constructor of Employee is not present then the code gives error so we need to create a default constructor in parent class.
*/