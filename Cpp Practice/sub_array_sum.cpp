#include <iostream>
using namespace std;

void sub_array_sum(int arr[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            cout << sum << " ";
        }
    }
}

int main()
{
    int n;      // size of array
    int arr[n]; // empty array of size n
    cout << "Enter Size : ";
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sub_array_sum(arr, n);

    return 0;
}