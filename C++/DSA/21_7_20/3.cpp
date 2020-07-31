#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool checkpair(char open,char close)
{
	if(open == '(' && close == ')')
    return true;
	return false;
}
bool balanced(string s1)
{
	stack<char>  S;
	for(int i =0;i<s1.length();i++)
	{
		if(s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
			S.push(s1[i]);
		else if(s1[i] == ')' || s1[i] == '}' || s1[i] == ']')
		{
			if(S.empty() || !checkpair(S.top(),s1[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	
	string s1;
	cout<<"Enter an expression:\n"; 
	cin>>s1;
	if(balanced(s1))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}