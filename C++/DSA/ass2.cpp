#include<iostream>
using namespace std;

    class Node{
        public:
        int data;
        Node* next;
        Node(){
            data=0;
            next=NULL;
        }
        Node(int d){
            data = d;
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

        void AppendNode(Node* n){
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

        void display_middle(int n){
            int c=1;
            int middle;
            if(n%2==0){
                middle = n/2;
                Node* temp = head;
                while(c < middle){
                    temp = temp->next;
                    c++;
                }
                cout << "\nThe middle elements are :\n";
                cout << "(" << temp->data <<")-->" << "(" << temp->next->data << ")-->\n"; 
            }
            else{
                Node* temp = head;
                middle = (n/2)+1;
                while(c < middle){
                    temp = temp->next;
                    c++;
                }
                cout << "\nThe middle element is : \n";
                cout << "(" << temp->data <<")-->\n";
            }

        }

        void display(){
            if(head==NULL){
                cout << "No nodes in the single linked list\n";
            }
            else{
                cout << "The single linked list is : \n";
                Node* temp = head;
                while (temp!=NULL)
                {
                    cout << "(" << temp->data << ")-->";
                    temp = temp->next;
                    /* code */
                }
            }
        }


    };

int main(){
    SingleLinkedList s1;
    int i,n,data1;
    cout << "Enter the number of elements in the single linked list:\n";
    cin >> n;
    cout << "Enter the elemets of the linked list:\n";
    for(i=0;i<n;i++){
        Node* n1 = new Node();
        cin >> data1;
        n1->data = data1;
        s1.AppendNode(n1);
    }
    s1.display();
    s1.display_middle(n);
    return 0;
}