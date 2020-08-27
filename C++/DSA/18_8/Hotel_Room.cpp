#include<iostream>
using namespace std;

    class Node{
        public:
        int key;
        string name,id,status;
        Node* next;
        Node(){
            key=0;
            name="";
            id = "";
            status = "";
            next=NULL;
        }
        Node(int k, string n, string i, string st){
            key=k;
            name = n;
            id = i;
            status = st;
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

        void updateNode(int k,string s){
           Node* ptr = nodeExists(k);
           if(ptr!=NULL){
               ptr->status = s;
               cout << "The status of room with key number " << k << " has been updated\n";
           }
           else{
               cout << "No room exists with the key value\n";
           }
        }

        string whoStays(int k){
            Node* temp = NULL;
            if(nodeExists(k)!=NULL){
                return (nodeExists(k)->name);
            }
            else{
                return "Not_Found\n";
            }
        }

        int returnKey(string i){
            Node* temp = head;
            while (temp!=NULL)
            {
                if(temp->id==i){
                    return (temp->key);
                }
                temp = temp->next;
            }
            return -1;
        }

        
    };

int main(){
    SingleLinkedList s1;
    int i;
    string id1,name1,status1;
    int key1,room_count;
    room_count = 0;
    cout << "Enter your choice:\n1:Add customer\n2:Remove customer\n3:Inform Manager\n4:Inform Manager Key\n5:Return Key\n0:Exit\n";
    cin >> i;
    while (i!=0)
    {
        Node* n1 = new Node();
        switch (i)
        {
        case 1:
            if(room_count==10){
                cout << "\nRooms are full.\n";
                break;
            }
            else{
                cout << "\nName : ";
                cin >> name1;
                n1->name = name1;
                cout << "\nID : ";
                cin >> id1;
                n1->id = id1;
                cout << "\nKey : ";
                cin >> key1;
                n1->key = key1;
                n1->status = "Unavailable";
                if(s1.nodeExists(key1)==NULL){
                    s1.AppendNode(n1);
                    room_count++;
                    break;
                }
                else{
                    cout << "\nENter different key Number\n";
                }
                 
            }
            break;
        case 2:
            cout << "\nEnter the key number of room that has been vacated.\n";
            cin >> key1;
            s1.deleteNode(key1);
            room_count--;
            break;
        case 3:
            cout << "\nThe number of rooms available are " << (10-room_count) << endl;
            break;
        case 4:
            cout << "\nEnter the key number of the room : ";
            cin >> key1;
            if(s1.whoStays(key1)!="Not_Found"){
                cout << "The person staying in room " << key1 << " is " << s1.whoStays(key1) << endl;
                break;
            }
            else{
                cout << "\nNot Found\n";
            }
            break;
        case 5:
            cout << "\nEnter the id of the customer : ";
            cin >> id1;
            if(s1.returnKey(id1)!=-1){
                cout << "\nThe Key number is : " << s1.returnKey(id1) << endl;
            }
            else{
                cout << "\nNot Found.\n";
            }
        }
        cout << "\nEnter your choice:\n";
        cin >> i;
    }
    
    return 0;
}