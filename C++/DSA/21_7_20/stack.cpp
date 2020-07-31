#include<iostream>
#include<string>
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

        void push(int val){
            if (isFull()){
                cout << "stack overflow" << endl;
            }
            else{
                top++;
                arr[top] = val;
            }
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack underflow" << endl;
                return 0;
            }
            else{
                int popVal = arr[top];
                arr[top] = 0;
                top--;
                return popVal;
            }
        }

        int count(){
            return (top+1);
        }

        int peek(int pos){
            if(isEmpty()){
                cout << "Stack underflow" << endl;
                return 0;
            }
            else{
                return (arr[pos]);
            }
        }

        void change(int pos,int val){
            arr[pos] = val;
            cout << "Item changed at position "<< pos << endl;
        }

        void display(){
            cout << "The items in the stack are :" << endl;
            for(int i=4;i>=0;i--){
                cout << arr[i] << endl;
            }
        }
};

int main(){
    Stack s1;
    int option, position, value;
    do
    {
        cout << "Enter the operation you want to perform : \n 1 : Check wether stack is empty \n 2 : Check wether stack is full or not \n 3 : Push element into stack \n 4 : Pop element from the stack \n 5 : Display number of elements in the stack \n 6 : Peek \n 7 : Change \n 8 : Display \n 0 : Exit \n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter an value to push into the stack : \n";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Pop function called. Pop Value : " << s1.pop() << endl;
            break;
        case 3:
            s1.display();
        default:
            break;
        }
    } while (option!=0);
    
    return 0;
}