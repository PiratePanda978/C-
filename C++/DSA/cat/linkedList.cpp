#include<iostream>
using namespace std;

    class Node{
        public:
        int key,data;
        Node* next;
        Node(){
            key=0;
            data=0;
            next=NULL;
        }
        Node(int k, int d){
            key=k;
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

        Node* nodeExists(int k){
            Node* temp = NULL;
            Node* ptr = head;
            while (ptr!=NULL)
            {
                if(ptr->key==k){
                    temp = ptr;
                }
                ptr = ptr->next;
                /* code */
            }
            return temp;
        }

        void AppendNode(Node* n){
            if(nodeExists(n->key)!=NULL){
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

        void prependNode(Node* n){
            if(nodeExists(n->key)!=NULL){
                cout << "Node already exists\n";
            }
            else{
                n->next=head;
                head = n;
                cout << "Node Prepended\n";
            }
        }

        void insertNode(int k,Node* n){
            Node* ptr = nodeExists(k);
            if(ptr==NULL){
                cout << "No node exists with the key value " << k << endl; 
            }
            else{
                if(nodeExists(n->key)!=NULL){
                    cout << "Node already exists\n";
                
                }
                else{
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node inserted\n";
                }
            }
        }

        void deleteNode(int k){
            if(head==NULL){
                cout << "Linked List already empty Nothing to delete\n";
            }
            else if(head!=NULL){
                if(head->key == k){
                    head = head->next;
                    cout << "Node with key value " << k << "has been unlinked\n";
                }
                else{
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;
                    while (currentptr!=NULL)
                    {
                        if(currentptr->key==k){
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
                        cout << "Node with key value "<<k<<" has been unlinked\n";
                    }
                    else{
                        cout << "No node exists with the given key value \n";
                    }
                    
                }
            }
        }


        void updateNode(int k,int d){
           Node* ptr = nodeExists(k);
           if(ptr!=NULL){
               ptr->data = d;
               cout << "Node with key value " << k << " has been updated\n";
           }
           else{
               cout << "No node exists with the key value\n";
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
                    cout << "(" << temp->key << "," << temp->data << ")-->";
                    temp = temp->next;
                    /* code */
                }
            }
        }


    };

int main(){
    return 0;
}