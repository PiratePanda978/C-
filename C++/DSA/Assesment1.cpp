#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string reg;
    string name;
    double cgpa;
    Node* next;
    Node(){
        reg = "";
        name = "";
        cgpa = 0.0;
        next = NULL;
    }
    Node(string r,string n,double c){
        reg = r;
        name = n;
        cgpa = c;
    }
};

class Single{
    public:
    Node* head;
    Single(){
        head = NULL;
    }
    Single(Node* n){
        head = n;
    }
    
    Node* exists(string r){
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr!=NULL){
            if(ptr->reg==r){
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    
    
    void pop(){
        if(head==NULL){
            cout << "List Underflow.\n";
        }
        else{
            head = head->next;
        }
    }
    
    void display(){
        Node* temp = head;
        cout << "The student details are:\n";
        while(temp!=NULL){
            cout << temp->reg << " " << temp->name << " " << temp->cgpa << endl;
            temp = temp->next;
        }
    }

    void Push(Node* n){
        if(head==NULL){
            cout << "Node pushed will be (" << n->name << ")-->\n";
            head = n;
        }
        else if(exists(n->reg)!=NULL){
            cout << "Same reg not allowed.\n";
        }
        else{
            cout << "Node pushed will be (" << n->name << ")-->\n";
            Node* temp = head;
            head = n;
            n->next = temp;
        }
    }

    Node* search(string r){
        Node* ptr = NULL;
        Node* temp = head;
        while (temp!=NULL)
        {
            if(temp->reg==r){
                ptr = temp;
                return ptr;
            }
            temp = temp->next;
        }
        return ptr;
    }
};


int main(){
    Single stack1;
    Single s2;
    Single s3;
    int i,n;
    string name1,reg1,regx;
    double cgpa1,x;
    cout << "Enter the number od students:\n";
    cin >> n;
    cout << "Enter the details to be pushed to the stack.\n";
    for(i=0;i<n;i++){
        Node* n1 = new Node();
        cout << "Reg: ";
        cin >> reg1;
        n1->reg = reg1;
        cout << "Name: ";
        cin >> name1;
        n1->name = name1;
        cout << "CGPA: ";
        cin >> cgpa1;
        n1->cgpa = cgpa1;
        stack1.Push(n1);
    }
    for(i=0;i<n;i++){
        Node* temp = new Node();
        temp = stack1.head;
        if(temp->cgpa <= 9.0){
            Node* n1 = new Node();
            n1->name = temp->name;
            n1->reg = temp->reg;
            n1->cgpa = temp->cgpa;
            s2.Push(n1);
        }
        else{
            Node* n2 = new Node();
            n2->reg = temp->reg;
            n2->name = temp->name;
            n2->cgpa = temp->cgpa;
            s3.Push(n2);
        }
        stack1.pop();
    }
    cout << "The contents of L1 are:\n";
    s3.display();
    cout << "The contents of L2 are:\n";
    s2.display();
    return 0;
    for(i=0;i<3;i++){
        cin >> regx;
        if(s3.search(regx)!=NULL){
            cout << "Found in L1\n";
            cout << s3.search(regx)->reg << " " << s3.search(regx)->name << " " << s3.search(regx)->cgpa << endl;
        }
        else if(s2.search(regx)!=NULL){
            cout << "Found in L2\n";
            cout << s2.search(regx)->reg << " " << s2.search(regx)->name << " " << s2.search(regx)->cgpa << endl;
        }
        else{
            cout << "Not Found.\n";
        }
    }
    return 0;
}