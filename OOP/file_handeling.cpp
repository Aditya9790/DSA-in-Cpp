#include<iostream>
#include <fstream>
using namespace std;
 
int main()
{
    char arr[100], arr1[100];
    cin.getline(arr, 100);

    fstream new_file;
    new_file.open("Test.txt", ios::app);
    new_file<<arr;
    cout<<"Done"<<endl;
    new_file.close();
    
    ifstream read("Test.txt", ios::in);
    read.getline(arr1, 100);
    cout<<"Read from file : "<<arr1<<endl;
    cout<<"Done"<<endl;
    return 0;
}