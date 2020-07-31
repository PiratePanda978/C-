#include<iostream>
using namespace std;

class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack(){
            top = -1;
            for(int i=0;i<5;i++)
                arr[i] = 0;
            }

        bool isEmpty(){
            if(top==-1)
            return true;
            else
            return false ;   
        }

        bool isFull(){
            if(top==4)
            return true;
            else
            return false;
        }

        int push(int val){
            if (isFull()){
                return 0;
            }
            else{
                top++;
                arr[top] = val;
                return 1;
            }
        }

        void display(){
            cout << "The binary equivalent is  :" << endl;
            for(int i=4;i>=0;i--){
                cout << arr[i];
            }
        }
};

int main(){
    int n,val,rem,quo,a;
    Stack s1;
    cout << "Enter the decimal number : \n";
    cin >> n;
    do
    {
        val = n%2;
        a = s1.push(val);
        if(a==0){
            cout << "Stack Overflow" << endl;
            break;
        } 
        n=n/2;
    } while (n!=0);
    if(a!=0){
        s1.display();
    }
    else{
        cout << "Operation could not be performed because of Stack Overflow.\n";
    }
    return 0;
}