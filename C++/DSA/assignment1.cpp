#include<bits/stdc++.h>
using namespace std;
class Stack1{
    public:
    int top;
    char arr[100];
    Stack1(){
        top = -1;
        for(int i=0;i<100;i++)
        arr[i] = 0;
    }

    bool isEmpty(){
        if(top==-1)
        return true;
        else
        return false;
    }

    bool isFull(){
        if(top==4)
        return true;
        else
        return false;
    }

    void push(char val){
        if(isFull())
        cout << "Stack overflow";
        else{
            top++;
            arr[top]=val;
        }
    }

    void pop(){
        if (isEmpty()){
            cout << "Stack underflow\n";
        }
        else{
            int popValue = arr[top];
            arr[top] = 0;
            top--;
        }
    }

    char top_el(){
        return arr[top];
    }

};

class Stack1 :: 
int main(){
    Stack1 s1;
    string str;
    char ch;
    int i,c,x;
    x=0;
    cout << "Enter a balanced expression:\n";
    cin >> str;
    int n = str.length();
    for(i=0;i<n;i++){
        s1.push(str[i]);
    }
    return 0;
}