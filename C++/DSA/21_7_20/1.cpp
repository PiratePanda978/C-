#include <bits/stdc++.h>  
using namespace std; 
int findMaxNum(int arr[], int n) 
{    
    sort(arr, arr+n, greater<int>());
    int num = arr[0]; 
    for(int i=1; i<n; i++) 
    { 
        num = num*10 + arr[i]; 
    } 
    return num; 
}
int findlessNum(int arr[], int n) 
{    
    sort(arr, arr+n, less<int>());
    int temp;
    if(arr[0]==0)
    {
        temp = arr[1];
        arr[1] = 0;
        arr[0] = temp;
    }
    int num = arr[0]; 
    for(int i=1; i<n; i++) 
    { 
        num = num*10 + arr[i]; 
    } 
    return num; 
}
int main()
{ 
    int n;
    cout << "Enter the number of digits : \n";
    cin >> n;
    int arr[n];
    cout << "Enter the digits : \n";
    for(int i=0;i<n;i++)
    cin >> arr[i];
    cout<<"The greatest number that can be formed is: " << findMaxNum(arr,n) << endl; 
    cout << "The smallest number that can be formed is: " << findlessNum(arr,n);
    return 0; 
}