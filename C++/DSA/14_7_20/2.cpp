#include<iostream>
using namespace std;
int main()
{
int n,i,sum;
sum = 0;
cout << "Enter the number : \n";
cin >> n;
for(i=1;i<n;i++)
{
if(n%i == 0)
sum+=i;
}
if(sum == n)
cout << "\n True\n";
else
cout << "\n False\n";
}
