#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,j,k,c,ct,m;
ct=0;
string search,dep;
cout << "\nEnter the number of array elements : ";
cin >> n;
m=n;
string reg[n];
cout << "\n Enter the register numbers : \n";
for(i=0;i<n;i++)
cin >> reg[i];
//removing dupliucates
for(i=0;i<n;++i)
for(j=i+1;j<n;)
{
if(reg[i]==reg[j])
{
for(k=j;k<n-1;++k)
reg[k]=reg[k+1];
--n;
}
else
++j;
}
cout << "Enter the register number to be searched : \n";
cin >> search;
for(i=0;i<n;i++)
{
if(reg[i] == search)
{
cout << "Found at position " << i;
dep = search.substr(3,2);
if(dep == "ME")
cout << "\nDepartment : Mechanical\n";
else if(dep == "EE")
cout << "\nDepartment : ELectrical\n";
else if(dep =="CE")
cout << "\nDepartment : Computer\n";
}
}

cout << "The number of unique elements in the array are : " << n << endl;
cout << "The array after removing the duplicates is : \n ";
for(i=0;i<n;i++)
cout << reg[i] << endl;
return 0;
}
