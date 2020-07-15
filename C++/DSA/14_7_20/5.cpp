
#include<bits/stdc++.h>
using namespace std; 
void sort(int n, int* ptr) 
{ 
    int i, j, t; 
    for (i = 0; i < n; i++) { 
  
        for (j = i + 1; j < n; j++) { 
  
            if (*(ptr + j) < *(ptr + i)) { 
  
                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 
    for (i = 0; i < n; i++) 
        cout << *(ptr + i);
} 
int main() 
{ 
    int n;
    cout << "Enter the number of elements :" << endl;
    cin >> n; 
    int arr[n];
    cout << "Enter the elements of the array : " << endl;
    for(int i = 0;i<n;i++)
    cin >> arr[i];
    sort(n, arr);
    return 0; 
}