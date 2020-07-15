#include<bits/stdc++.h>
using namespace std;

void swap (int &x , int &y)
{
    int temp = x ;
    x = y ;
    y = temp ;
}

int main()
{
    int n,i,j,k,m,x;
    cout << "Enter the size of the array\n";
    cin >> n;
    cout << "Enter the array : \n";
    int arr[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cin >> arr[i][j];
    }
    for (int k = 0; k < n; k++)
    {
        for (int m = 0; m < n; m++)
        {
            x = m+1;
            for (int i = k; i < n ; i++)
            {
                for (int j = x; j < n; j++)
                {
                    if (arr[k][m] > arr[i][j])
                        swap(arr[k][m] ,arr[i][j]);
                }
                x=0;
            } 
        }
    }

    cout << "The sorted array is : \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << arr[i][j] << endl;
        }
    }
}