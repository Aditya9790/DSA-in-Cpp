#include <iostream>
#include <string>
using namespace std;

class binary
{
    string b;

public:
    void read();
    void check_bin();
    void complement();
    void display();
};

void binary ::read()
{
    cout << "Enter binary number : ";
    cin >> b;
}

void binary ::check_bin()
{
    for (int i = 0; i < b.length(); i++)
    {
        if (b.at(i) != '0' && b.at(i) != '1')
        {
            cout << "Incorrect binary format." << endl;
            exit(0);
        }
    }
}

void binary ::complement()
{
    for (int i = 0; i < b.length(); i++)
    {
        if (b.at(i) == '1')
            b.at(i) = '0';
        else
            b.at(i) = '1';
    }
}

void binary ::display()
{
    cout << "The number is : "<< b << endl;
}

int main()
{   
    binary b;

    b.read();
    b.check_bin();
    b.display();
    b.complement();
    b.display();
    return 0;
}
