#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int key,quantity;
    string name;
    Node(){
        left = NULL;
        right = NULL;
        key = 0;
        quantity = 0;
        name = "";
    }
    Node(int k,int q,string n){
        key = k;
        quantity = q;
        name = n;
    }
};

class BST{
    public:
    Node* root;

    BST(){
        root = NULL;
    }

    BST(Node* n){
        root = n;
    }


    private:
    bool isEmpty(){
        if(root==NULL)
        return true;
        else
        return false;
    }

    void AddL(Node* n, Node* ptr){
        if(isEmpty()){
            root = n;
        }
        else{
            if(n->key < ptr->key){
                if(ptr->left!=NULL){
                    AddL(n,ptr->left);
                }
                else{
                    ptr->left = n;
                }
            }
            else if(n->key > ptr->key){
                if(ptr->right!=NULL){
                    AddL(n,ptr->right);
                }
                else{
                    ptr->right = n;
                }
            }
            else{
                cout << "The key already exists. Try another key\n";
            }
        }
    }

    void printInOrder(Node* ptr){
        if(isEmpty()){
            cout << "No leafs to display.\n";
        }
        else{
            if(ptr->left!=NULL){
                printInOrder(ptr->left);
            }
            cout << ptr->key << " " << ptr->name << " " << ptr->quantity << endl;
            if(ptr->right!=NULL){
                printInOrder(ptr->right);
            }
        }
    }

    int findSmallest(Node* ptr){
        if(root!=NULL){
            if(ptr->left!=NULL){
                return findSmallest(ptr->left);
            }
            else{
                return ptr->key ;
            }
        }
        else{
            cout << "The tree is empty.\n";
            return -1000;
        }
    }

    void removeLeaf(int k,Node* parent){
        if(root!=NULL){
            if(root->key == k){
                removeRootMatch();
            }
            else{
                if(k < parent->key && parent->left != NULL){
                    parent->left->key == k ?
                    removeMatch(parent, parent->left,true) :
                    removeLeaf(k,parent->left);
                }
                else if(k > parent->key && parent->right != NULL){
                    parent->right->key == k ?
                    removeMatch(parent, parent->right,false) :
                    removeLeaf(k,parent->right);
                }
                else{
                    cout << "Key is not in the tree.\n";
                }
            }
        }
        else{
            cout << "Tree is empty.\n";
        }
    }

    void removeRootMatch(){
        if(root!=NULL){
            Node* delPtr = root;
            int rootKey = root->key;
            int smallestRightSubtree;
            //case 0 : root has 0 children
            if(root->left==NULL&&root->right==NULL){
                root = NULL;
                delete delPtr;
            }
            //case 1 : root has 1 child
            else if(root->left==NULL&&root->right!=NULL){
                root = root->right;
                delPtr->right = NULL;
                delete delPtr;
                cout << "The root node with the key " << rootKey << "was deleted. "<<
                     "The new root contains the key " << root->key << endl;
            }
            else if(root->right==NULL&&root->left!=NULL){
                root = root->left;
                delPtr->left = NULL;
                delete delPtr;
                cout << "The root node with the key " << rootKey << "was deleted. "<<
                     "The new root contains the key " << root->key << endl;
            }
            //case 2 : root has 2 children
            else{
                smallestRightSubtree = findSmallest(root->right);
                removeLeaf(smallestRightSubtree,root);
                root->key = smallestRightSubtree;
                cout << "The root key containing " << rootKey << " was overwritten with " << root->key << endl;
            }
        }
        else{
            cout << "Cannot remove root as the tree is empty.\n";
        }
    }

    void removeMatch(Node* parent, Node* match, bool left){
        if(root!=NULL){
            Node* delptr;
            int matchKey = match->key;
            int smallestRightSubtree;
            //case 0 : 0 children
            if(match->left==NULL&&match->right==NULL){
                delptr = match;
                left == true? parent->left = NULL : parent->right = NULL;
                delete delptr;
                cout << "The node containing key " << matchKey << " was removed.\n"; 
            }
            //case 1 : 1 Child
            else if(match->left==NULL&&match->right!=NULL){
                left == true ? parent->left = match->right : parent->right = match->right;
                match->right = NULL;
                delptr = match;
                delete delptr;
                cout << "The node containing key " << matchKey << " was removed.\n"; 
            }
            else if(match->right==NULL && match->left!=NULL){
                left == true ? parent->left = match->left : parent->right = match->left;
                match->left = NULL;
                delptr = match;
                delete delptr;
                cout << "The node containing key " << matchKey << " was removed.\n"; 
            }
            //case 2 : 2 children
            else{
                smallestRightSubtree = findSmallest(match->right);
                removeLeaf(smallestRightSubtree,match);
                match->key = smallestRightSubtree;
            }
        }
        else{
            cout << "Cannot remove match. The tree is empty.\n";
        }
    }
    
    Node* returnN(int k,Node* ptr){
        if(ptr!=NULL){
            if(ptr->key == k){
                return ptr;
            }
            else{
                if(k < ptr->key){
                    return returnN(k,ptr->left);
                }
                else{
                    return returnN(k,ptr->right);
                }
            }
        }
        else{
            return NULL;
        }
    }
    
    public:
    void AddLeaf(Node* n){
       AddL(n,root);
    }

    void displayInOrder(){
        printInOrder(root);
    }
    
    void deleteLeaf(int k){
        removeLeaf(k,root);
    }

    int findSmall(){
        findSmallest(root);
    }

    Node* returnNode(int k){
        returnN(k,root);
    }
};

void Purchase(BST b1){
    int k,q,temp;
    cout << "The items in your inventory are : \n";
    b1.displayInOrder();
    cout << "Enter the key of the item you want to purchase : ";
    cin >> k;
    cout << "Enter the quantity you want to purchase : ";
    cin >> q;
    Node* n1 = b1.returnNode(k);
    if(n1->quantity >= q){
        temp = n1->quantity;
        temp-=q;
        if(temp==0){
            b1.deleteLeaf(k);
        }
        else{
            n1->quantity = temp;
        }
        cout << "Purchase of item " << n1->name << " was successful.\n";
    }
    else{
        cout << "Not enough quantity in stock.\n";
    }
}

int main(){
    BST b1;
    int i,n,key1,quantity1;
    string name1;
    cout << "Enter the number of items in your inventory : ";
    cin >> n;
    for(i=0;i<n;i++){
        Node* n1 = new Node();
        key1 = i;
        n1->key = key1;
        cout << "Enter the name of the item : ";
        cin >> name1;
        n1->name = name1;
        cout << "Enter the quantity : ";
        cin >> quantity1;
        n1->quantity = quantity1;
        b1.AddLeaf(n1);
    }
    Purchase(b1);
}