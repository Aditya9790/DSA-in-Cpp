#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter  numbers" << endl;
    cin >> a >> b;

    if (a > b)
        cout << "Max number is : " << a;
    else
        cout << "Max number is : " << b;
    return 0;
}