#include<bits/stdc++.h>
using namespace std;

    class Node{
        public:
        string title,author,publisher;
        Node* next;
        
        Node(){
            title="";
            author="";
            publisher = "";
            next=NULL;
        }

        Node(string k,string d,string m){
            title=k;
            author=d;
            publisher = m;
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
                if(ptr->title==k){
                    temp = ptr;
                }
                if(ptr->author==k){
                    temp = ptr;
                }
                if(ptr->publisher==k){
                    temp = ptr;
                }
                ptr = ptr->next;
                /* code */
            }
            return temp;
        }


        void AppendNode(Node* n){
            if(nodeExists(n->title)!=NULL){
                cout << "\nNode already exists\n";
            }
            else{
                if(head==NULL){
                    head = n;
                    cout << "\nNode Appended\n";
                }
                else{
                    Node* ptr = head;
                    while (ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    cout << "\nNode appended\n";
                }
            }
        }


        void display(){
            if(head==NULL){
                cout << "\nNo nodes in the single linked list\n";
            }
            else{
                Node* temp = head;
                while (temp!=NULL)
                {
                    cout << temp->title << " by " << temp->author << endl;
                    temp = temp->next;
                    /* code */
                }
            }
        }


        void display_author(string word1){
            if(head==NULL){
                cout << "No nodes in the single linked list\n";
            }
            else{
                Node* temp = head;
                while (temp!= NULL)
                {
                    if(temp->author==word1){
                        cout << "\nA book by " << word1 << " is " << temp->title << endl;
                    }
                    temp = temp->next;
                }
            }
        }


        void display_publisher(string word1){
            if(head==NULL){
                cout << "No nodes in the single linked list\n";
            }
            else{
                
                Node* temp = head;
                while (temp != NULL)
                {
                    if(temp->publisher==word1){
                        cout << "\n A book published by " << word1 << " is " << temp->title << endl;
                    }
                    temp = temp->next;
                }
            }
        }

    };

int main(){
    SingleLinkedList s1;
    SingleLinkedList s2;
    int i,n,n3,c,as,ps,at,pt;
    string title1,author1,publisher1,author2,publisher2;
    cout << "\nEnter the number of books in StoryBooks:\n";
    cin >> n;
    for(i=0;i<n;i++){
        Node* n1 = new Node();
        cout << "\nEnter the title:\n";
        cin >> title1;
        n1->title = title1;
        cout << "\nEnter the author:\n";
        getline(cin,author1);
        getline(cin,author1);
        n1->author = author1;
        cout << "\nEnter the publisher:\n";
        getline(cin,publisher1);
        n1->publisher = publisher1;        
        s1.AppendNode(n1);
    }

    cout << "\nEnter the number of books in textbooks:\n";
    cin >> n3;
    for(i=0;i<n3;i++){
        Node* n1 = new Node();
        cout << "\nEnter the title:\n";
        cin >> title1;
        n1->title = title1;
        cout << "\nEnter the author:\n";
        getline(cin,author1);
        getline(cin,author1);
        n1->author = author1;
        cout << "\nEnter the publisher:\n";
        getline(cin,publisher1);
        n1->publisher = publisher1;        
        s2.AppendNode(n1);
    }
    
    cout << "\nStory Books,\n";
    s1.display();
    cout << "\nTextBooks.\n";
    s2.display();


    cout << "\nEnter the author whose books you want to search:\n";
    getline(cin,author2);
    if((s1.nodeExists(author2))!=NULL)
    s1.display_author(author2);
    else if((s2.nodeExists(author2))!=NULL)
    s2.display_author(author2);
    else
    cout << "\nNo book with the author.\n";


    cout << "\nMy StoryBooks collection.\n";
    s1.display();

    cout << "\nEnter the publisher whose books you want to search:\n"; 
    getline(cin,publisher2);
    if((s1.nodeExists(publisher2))!=NULL)
    s1.display_publisher(publisher2);
    else if((s2.nodeExists(publisher2))!=NULL)
    s2.display_publisher(publisher2);
    else
    cout << "\nNo book from the publisher.\n";

    cout << "\nThe total number of books in my collection:\n";
    cout << n+n3 << endl; 
    return 0;
}