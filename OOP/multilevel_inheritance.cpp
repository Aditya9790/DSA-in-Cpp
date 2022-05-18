#include <iostream>
using namespace std;

/*
Multilevel inheritance
                A
                |
                B
                |
                C
Here B is inherited from A and C is inherited from B.
*/

class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number(void);
};

void Student::set_roll_number(int r)
{
    roll_number = r;
}

void Student ::get_roll_number()
{
    cout << "Roll number is :" << roll_number << endl;
}

/*
class Exam is inherited publically from Student.
But the variable roll_number is protected in Student class so it is inherited as a protected variable in Exam class.
*/
class Exam : public Student
{
protected:
    float math, physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam::set_marks(float m1, float m2)
{
    math = m1;
    physics = m2;
}

void Exam::get_marks()
{
    cout << "Marks obtained in maths are : " << math << endl;
    cout << "Marks obtained in physics are : " << physics << endl;
    // cout << "Roll no is in exam: " << roll_number<<endl;
}

/*
class Result is inherited from class Exam. This is multilevel inheritance.
*/

class Result : public Exam
{
    float percentage;

public:
    void display_marks()
    {
        get_roll_number();
        get_marks();
        cout << "Percentage is :" << (math + physics) / 2 << endl;
        // cout<<"Roll no in result : " << roll_number<<endl;
    }
};

/*
If we are inheriting B from A and C from B:[A-->B-->C]
    1. A is base class for B and B is base class for C.
    2. A-->B-->C is calles the inheritance path.
*/
int main()
{

    Result harry;
    harry.set_roll_number(420);
    harry.set_marks(90.0, 60.0);

    Exam ese;
    ese.set_marks(90, 35);
    ese.get_marks();

    harry.display_marks();
    return 0;
}