#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int var = 100;
    int *ptr;

    ptr = &var;

    cout << "var is : " << var << endl;
    cout << "Address of var is : " << ptr << endl;

    cout<<endl;
    int a[3] = {1,2,3};

    int *ptr1;
    ptr1 = a;

    cout<<"0 th index : "<<*ptr1<<endl;
    cout<<"1 st index : "<<*(ptr1+1)<<endl;
    cout<<"2 st index : "<<*(ptr1+2)<<endl;

    return 0;
}
