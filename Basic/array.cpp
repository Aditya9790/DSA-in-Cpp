# include<iostream>
using namespace std;

int main()
{
    
    int x[3][2] = {{10, 20}, {30, 40}, {50, 60}};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<"Element at ("<<i<<", "<<j<<") is :"<<x[i][j]<<endl;
        }
    }
    return 0;
}