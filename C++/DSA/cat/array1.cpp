#include<iostream>
using namespace std;
int main(){
    int i,item,position,n,j;
    cout << "Enter the lenght of array:\n";
    cin >> n;
    j=n;
    int arr[n];
    cout << "Enter the array elements:\n";
    for(i=0;i<n;i++)
    cin >> arr[i];
    cout << "Enter the position of insertion:\n";
    cin >> position;
    cout << "Enter the element to be inserted:\n";
    cin >> item;
    //Creatig space for insertion
    n+=1;
    while(j>=position){
        arr[j+1]=arr[j];
        j-=1;
    }
    //Inserting element
    arr[position] = item;
    for(i=0;i<n;i++)
    cout << arr[i];
    cout << endl;
    return 0;
}