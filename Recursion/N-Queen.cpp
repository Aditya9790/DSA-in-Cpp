#include<bits/stdc++.h>
using namespace std;
 

// check if a queen is placed at arr[x][y] then is it safe .
// i.e. there is no any other queen placed in row x, col y and in left and right upper diagonal.

// say we are at index x such that x<col then we will only check for indices ranging from 0 to x i.e. in that column no need to check from x+1 to n
// as at present we have placed queen at x th column so check until only that col

bool isSafe(int** arr, int x, int y, int n)
{
    for(int row=0;row<x;row++) // check for columns from 0 to x
    {
        if(arr[row][y]==1) return false;
    }

    // check for upper left diagonal
    // if under attack from upper left diagonal return false
    int row = x;
    int col = y;
    while(row >=0 && col >=0)
    {
        if(arr[row][col]==1) return false;
        row--;
        col--;
    }

    // check for upper right diagonal 
    row = x;
    col = y;
    while(row >=0 && col < n)
    {
        if(arr[row][col]==1) return false;
        row--;
        col++;
    }

    // if safe from all directions then return true
    return true;
}

//  
bool nQueen(int** arr, int x, int n)
{
    if(x >= n) return true; // when all queens placed

    for(int col=0;col < n;col++)
    {
        if(isSafe(arr, x, col, n)) arr[x][col] = 1; // if safe then place at xth row in col column

        // check if queen can be placed in other row
        if(nQueen(arr, x+1, n)) return true;

        // if we cannot place in that row then back track 
        // remove queen from that place i.e. change arr[x][col] = 0
        arr[x][col] = 0;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }


    if(nQueen(arr, 0, n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}