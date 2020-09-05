#include<iostream>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int key;
    Node(){
        left = NULL;
        right = NULL;
        key = 0;
    }
    Node(int k){
        key = k;
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
    Node* returnNode(int k){
        returnN(k,root);
    }

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
            cout << ptr->key << " ";
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
};

int main(){
    BST b1;
    Node * n1 = new Node();
    return 0;    
}