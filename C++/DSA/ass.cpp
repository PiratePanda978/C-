#include <bits/stdc++.h> 
using namespace std; 
bool findDuplicateparenthesis(string str) 
{ 
    stack<char> Stack;  //creating stack using library class
    for (char ch : str) 
    {  
        if (ch == ')') 
        { 
            char top = Stack.top(); 
            Stack.pop(); 
            int elementsInside = 0; 
            while (top != '(') 
            { 
                elementsInside++; 
                top = Stack.top(); 
                Stack.pop(); 
            } 
            if(elementsInside < 1) { 
                return true; 
            } 
        } 
        else
            Stack.push(ch); 
    }
    return false; 
}
int main() 
{ 
    // input balanced expression 
    string str;
    cout << "Enter the string:\n";
    cin >> str;
    if (findDuplicateparenthesis(str)) 
        cout << "Duplicate Found "; 
    else
        cout << "No Duplicates Found "; 
  
    return 0; 
} 