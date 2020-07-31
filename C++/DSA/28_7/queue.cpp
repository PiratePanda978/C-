#include<iostream>
using namespace std;

class queue{
    public:
    int arr[10];
    int front = -1;
    int rear = -1;

    bool isEmpty(){
        if(front==-1 && rear == -1)
        return true;
        else
        return false;
    }

    bool isFull(){
        if(rear == (sizeof(arr)/sizeof(arr[0]))-1)
        return true;
        else
        return false;
    }

    void enqueue(){
        if(isFull()){
            cout << "Overflow\n";
            return;
        }
        else if (isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            rear++;
        }
        int val;
        cout << "Enter the value to be inserted : ";
        cin >> val;
        arr[rear] = val;
        
    }

    void dequeue(){
        int x=0;
        if(isEmpty()){
            cout << "Underflow \n";
            return;
        }
        else if(front==rear){
            x = arr[front];
            front=rear=-1;
        }
        else{
            x = arr[front];
            front++;
        }
        cout <<  "Element removed is : " << x << endl;
    }

    void display(){
        if(isEmpty()){
            cout << "Nothing to display.\n";
        }
        else{
            cout << "The elements in the queue are :\n";
            for(int i=front;i<=rear;i++)
            cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main(){
    queue q1;
    int c;
    cout << "Enter your choice: \n1. enqueue\n2. dequeue\n3. display\n4. Exit\n";
    cin >> c;
    do
    {
        if(c==4)
        break;
        switch (c)
        {
        case 1:
            q1.enqueue();
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            q1.display();
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
        cout << "Enter your choice: \n";
        cin >> c;
    } while (c!=4);
}