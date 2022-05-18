#include <iostream>
using namespace std;

void max_till_i(int arr[], int n)
{
    int mx = -1000;
    for(int i=0;i<n;i++)
    {
        mx = max(mx, arr[i]);
        cout<<mx<<endl;
    }
}

int main()
{
    int n; // size of array
    int arr[n]; // empty array of size n
    cout << "Enter Size : ";
    cin >> n;

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    max_till_i(arr, n);
    return 0;
}