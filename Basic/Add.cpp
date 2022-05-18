#include <iostream>
using namespace std;

int main()
{

    int a, b;
    float c, d;
    string str;

    cout << "May I know your name?" << endl;
    getline(cin, str);
    cout << "Hello " << str << endl;
    cout << endl; //adds new line

    cout << "Enter 3 numbers:" << endl;
    cin >> a >> b >> c;
    d = a + b + c;
    cout << "Addition is:" << d;
    return 0;
}