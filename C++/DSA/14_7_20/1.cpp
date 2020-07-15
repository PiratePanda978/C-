#include<iostream>
using namespace std;
int main()
{
int n,i,pos,neg,zero;
pos=0;neg=0;zero=0;
cout << "Enter the size of the array : " << endl;
cin >> n;
int arr[n];
cout << "Enter the elements of thee array : " << endl;
for(i=0;i<n;i++)
cin >> arr[i];
for(i=0;i<n;i++)
{
if(arr[i] > 0)
pos++;
else if(arr[i] < 0)
neg++;
else
zero++;
}
cout <<"\n Positive no : " << pos;
cout << "\n Negative number : " << neg;
cout << "\n zero numbers : " << zero << "\n";
}