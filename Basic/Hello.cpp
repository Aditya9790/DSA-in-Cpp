// #include<iostream>
// using namespace std;

// int main() // starting point of any c++ program.
// {
//     cout << "Hello Guys and fellow programers." << endl;
//     return 0;
// }
// // "<<" is known as insertion operator.
// //  cout and cin are present in iostream liabrary.
// // std:: is udes for scope resolution.
// // All the builtin files present in header file are grouped in std.

#include <cmath>
#include <cstdio>
#include <array>
#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int temp;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    cout << endl;
    for (int j = 0; j < sizeof(arr) / sizeof(int); j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}
