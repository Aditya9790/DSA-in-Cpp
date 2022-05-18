#include <iostream>
#include <string>
using namespace std;

/*
Write a program to enter the info of n number of students,and then display using multilevel inheritance.
class personal(roll_no, name, sex)
class physical(height, weight)
class academic(branch, sem)
*/

class personal
{
public:
    string name, sex;
    int roll;
    personal() // default
    {
        roll = 0;
        name = "Null";
        sex = "Null";
    }

    personal(int roll_no, string stud_name, string stud_sex) // constructor
    {
        roll = roll_no;
        name = stud_name;
        sex = stud_sex;
    }
};

class physical : public personal
{
public:
    float height, weight;

    physical()
    {
        height = 0;
        weight = 0;
    }
    physical(int Roll, string Name, string Sex, float stud_ht, float stud_wt) : personal(Roll, Name, Sex)
    {
        height = stud_wt;
        weight = stud_wt;
    }
};

class academic : public physical
{
public:
    string branch;
    int sem;

    academic()
    {
        branch = "Null";
        sem = 0;
    }
    academic(int Roll, string Name, string Sex, float Height, float Weight, string stud_branch, int stud_sem) : physical(Roll, Name, Sex, Height, Weight)
    {
        branch = stud_branch;
        sem = stud_sem;
    }
    void display();
};

void academic::display()
{
    cout << "Student name : " << name << endl;
    cout << "Student Roll no. : " << roll << endl;
    cout << "Student sex : " << sex << endl;
    cout << "Student weight : " << weight <<" Kg"<< endl;
    cout << "Student Height : " << height <<" cm"<< endl;
    cout << "Student branch : " << branch << endl;
    cout << "Student Sem : " << sem << endl;
}

int main()
{
    academic stud1(37, "Aditya", "M", 169.67, 79, "Instru", 6);
    stud1.display();
    return 0;
}

/*
#include <iostream>

using namespace std;

class personal
{

public:
    long int rollNo;
    string name, sex;
    personal()
    {
        rollNo = 0;
        name = "NA";
        sex = "NA";
    }
    personal(long int roll, string Name, string Sex)
    {
        rollNo = roll;
        name = Name;
        sex = Sex;
    }
};

class physical : public personal
{

public:
    float height;
    float weight;
    physical()
    {
        height = 0;
        weight = 0;
    }
    physical(long RollNo, string Name, string Sex, float Height, float Weight) : personal(RollNo, Name, Sex)
    {
        height = Height;
        weight = Weight;
    }
};

class academic : public physical
{

public:
    string branch;
    string sem;
    academic()
    {
        branch = "NA";
        sem = "NA";
    }
    academic(long RollNo, string Name, string Sex, float Height, float Weight, string Branch, string Sem) : physical(RollNo, Name, Sex, Height, Weight)
    {
        branch = Branch;
        sem = Sem;
    }
    void display();
};

int main()
{
    academic s1(111, "Mahesh", "Male", 160, 50, "E&Tc", "VI");
    s1.display();
    return 0;
}

void academic::display()
{
    cout << "Student name : " << name << endl;
    cout << "Student roll NO : " << rollNo << endl;
    cout << "Student sex : " << sex << endl;
    cout << "Student weight : " << weight << endl;
    cout << "Student Height : " << height << endl;
    cout << "Student branch : " << branch << endl;
    cout << "Student Sem : " << sem << endl;
}
*/