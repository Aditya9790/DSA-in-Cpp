#include <iostream>
using namespace std;

void max_sub_array(int n, int arr[])
{
    // len = length of current max sub array
    // d = common difference
    int len = 2;
    int maxlen = 2;
    int d = arr[1] - arr[0];

    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == d)
            len++;
        else
        {
            d = arr[i] - arr[i-1]; // update dommon diff if not constant
            len = 2; // reset the length
        }
        maxlen = max(len, maxlen);// update the maximum length
    }
    cout<<maxlen<<endl;
}

int main()
{
    int n=7;      // size of array
    int arr[n] = {10, 7, 4, 6, 8, 10, 11}; // empty array of size n
    cout << "Enter Size : ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    max_sub_array(n, arr);
    return 0;
}