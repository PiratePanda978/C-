#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5};
    int arr1[5];
    int i;
    for(i=0;i<5;i++)
    {
        arr1[i] = arr[i];
    }
    cout << "The copied array is : \n";
    for(i=0;i<5;i++)
    cout << arr1[i] << endl;
    return 0;
}