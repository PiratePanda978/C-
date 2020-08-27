#include<bits/stdc++.h>
using namespace std;

    class Node{
        public:
        string word,meaning;
        Node* next;
        Node(){
            word="";
            meaning="";
            next=NULL;
        }
        Node(string k,string d){
            word=k;
            meaning=d;
        }
    };
    
    class SingleLinkedList{
        public:
        Node* head;
        SingleLinkedList(){
            head = NULL;
        }
        SingleLinkedList(Node* n){
            head = n;
        }

        Node* nodeExists(string k){
            Node* temp = NULL;
            Node* ptr = head;
            while (ptr!=NULL)
            {
                if(ptr->word==k){
                    temp = ptr;
                }
                ptr = ptr->next;
                /* code */
            }
            return temp;
        }

        void AppendNode(Node* n){
            if(nodeExists(n->word)!=NULL){
                cout << "Node already exists\n";
            }
            else{
                if(head==NULL){
                    head = n;
                    cout << "Node Appended\n";
                }
                else{
                    Node* ptr = head;
                    while (ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    cout << "Node appended\n";
                }
            }
        }


        void deleteNode(string k){
            if(head==NULL){
                cout << "Linked List already empty Nothing to delete\n";
            }
            else if(head!=NULL){
                if(head->word == k){
                    head = head->next;
                    cout << "Node with key value " << k << "has been unlinked\n";
                }
                else{
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;
                    while (currentptr!=NULL)
                    {
                        if(currentptr->word==k){
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else{
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                        /* code */
                    }
                    if(temp!=NULL){
                        prevptr->next = temp->next;
                    }
                    else{
                        cout << "No node exists with the given key value \n";
                    }
                    
                }
            }
        }


        void display(){
            if(head==NULL){
                cout << "No nodes in the single linked list\n";
            }
            else{
                Node* temp = head;
                while (temp!=NULL)
                {
                    cout << temp->word << "_" << temp->meaning << endl;
                    temp = temp->next;
                    /* code */
                }
            }
        }

        Node* deleteLast(){
            Node* temp = head;
            Node* ptr;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            return(temp->next);
        }

        void display_meaning(string word1){
            if(head==NULL){
                cout << "No nodes in the single linked list\n";
            }
            else{
                cout << "The meaning is : \n";
                Node* temp = head;
                while (temp->next->word != word1)
                {
                    temp = temp->next;
                }
                cout << temp->next->meaning << endl;
            }  
        }

        int counter(){
            int c = 0;
            Node* temp = head;
            while (temp!=NULL)
            {
                c++;
                temp = temp->next;
                /* code */
            }
            return c;
        }
    };

int main(){
    SingleLinkedList s1;
    int i,n,c;
    string word1,meaning1,word2;
    cout << "Enter the number of words in the list:\n";
    cin >> n;
    for(i=0;i<n;i++){
        Node* n1 = new Node();
        cout << "Enter the word:\n";
        cin >> word1;
        n1->word = word1;
        cout << "Enter the meaning:\n";
        getline(cin,meaning1);
        getline(cin,meaning1);
        n1->meaning = meaning1;
        s1.AppendNode(n1);
    }
    cout << "The single linked list before deletion : \n";
    s1.display();
    cout << endl;
    Node* ptr;
    ptr = s1.deleteLast();
    s1.deleteNode(ptr->word);
    cout << "The single linked list after deletion : \n";
    s1.display();
    cout << endl;
    cout << "Enter the word whose meaning you want to display:\n";
    cin >> word2;
    if((s1.nodeExists(word2))==NULL){
        cout << "No node with the word.\n";
    }
    else
    s1.display_meaning(word2);
    c = s1.counter();
    cout << "The size of dictionary is : " << c << endl;
    return 0;
}