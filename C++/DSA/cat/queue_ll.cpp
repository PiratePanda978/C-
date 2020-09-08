#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;

    Node(){
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k,int d){
        key = k;
        data = d;
        next = NULL;
    }
};

class queue{
    public:
    Node* front;
    Node* rear;

    queue(){
        front = NULL;
        rear = NULL;
    }

    private:
    bool isEmpty(){
        if(front==NULL&&rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    bool nodeExists(Node* n){
        Node* temp = front;
        while(temp!=NULL){
            if(temp->key==n->key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    public:
    void enqueue(Node* n){
        if(isEmpty()){
            front = n;
            rear = n;
        }
        else if(nodeExists(n)){
            cout << "Node already exists.\n";
        }
        else{
            rear->next = n;
            rear = n;
        }
    }

    void dequeue(){
        if(!isEmpty()){
            if((front==rear)){
                front = NULL;
                rear = NULL;
            }
            else{
                front = front->next;
            }
        }
        else{
            cout << "Underflow\n";
        }
    }

    int count(){
        int c = 0;
        Node* temp = NULL;
        while(temp!=NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }

    void display(){
        if(!isEmpty()){
            Node* temp = front;
            while(temp!=NULL){
                cout << temp->key << " " << temp->key << endl;
                temp=temp->next;
            }
        }
    }

};

int main(){
    return 0;
}