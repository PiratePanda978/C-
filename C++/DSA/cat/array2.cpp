#include<iostream>
using namespace std;
int main(){
    int i,position,n,j;
    cout << "Enter the lenght of array:\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements:\n";
    for(i=0;i<n;i++)
    cin >> arr[i];
    cout << "Enter the position of deletion:\n";
    cin >> position;
    j=position;
    while(j<n){
        arr[j-1]=arr[j];
        j+=1;
    }
    n=n-1;
    for(i=0;i<n;i++)
    cout << arr[i];
    cout << endl;
    return 0;
}