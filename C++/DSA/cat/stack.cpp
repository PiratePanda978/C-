#include<iostream>
using namespace std;
class stack{
    public:
    int top;
    int arr[5];
    stack(){
        top = -1;
        for(int i=0;i<5;i++)
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

    void push(int val){
        if(isFull())
        cout << "Stack overflow";
        else{
            top++;
            arr[top]=val;
        }
    }

    int pop(){
        if (isEmpty()){
            cout << "Stack underflow\n";
            return 0;
        }
        else{
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count(){
        return top+1;
    }

    int peek(int pos){
        if (isEmpty()){
            cout << "Stack empty\n";
            return 0;
        }
        else{
            return arr[pos];
        }
    }

    void change(int pos,int value){
        arr[pos] = value;
        cout << "Value changed at position " << pos << endl;
    }

    void display(){
        for(int i=0;i<5;i++)
        cout << arr[i] << endl;
    }
};
int main(){
    stack s1;
    int n;
    int val,pos;
    cout << "Enter the values of the stack:\n";
    for(int i=0;i<5;i++){
        cin >> val;
        s1.push(val);
    }
    s1.display();
    return 0;
}