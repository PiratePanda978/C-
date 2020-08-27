#include<iostream>
#include<string.h>
#include<stack>
#include<cmath>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        data = ' ';
        next=NULL;
    }
    Node(int d){
        data = d;
    }
};

class Stack{
    public:
    Node* top;
    Stack(){
        top=NULL;
    }
    Stack(Node* n){
        top = n;
    }

    bool isEmpty(){
        if(top==NULL)
        return true;
        else
        return false;
    }

    void push(Node* n1){
        if(top==NULL){
            top = n1;
        }
        else{
            Node* temp = top;
            top = n1;
            n1->next = temp;
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

    void pop(){
        if(top==NULL){
            cout << "Stack Underflow.\n";
        }
        else{
            top = top->next;
        }
    }

    int peek(){
        if(top==NULL){
            return 0;
        }
        else{
            return top->data;
        }
    }

    void display(){
        Node* temp = top;
        cout << "The stack elements are:\n";
        while(temp!=NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

bool balanced(string s1){
   	Stack s2;
	for(int i =0;i<s1.length();i++)
	{
        Node* n1 = new Node();
		if(s1[i] == '(' || s1[i] == '{' || s1[i] == '['){
            n1->data = s1[i];
            s2.push(n1);
        }
		else if(s1[i] == ')' || s1[i] == '}' || s1[i] == ']')
		{
			if(s2.isEmpty() || !ArePair(s2.peek(),s1[i]))
				return false;
			else
				s2.pop();
		}
	}
	return s2.isEmpty() ? true:false;
}

int preced(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;              //Precedence of + or - is 1
   }else if(ch == '*' || ch == '/') {
      return 2;            //Precedence of * or / is 2
   }else if(ch == '^') {
      return 3;            //Precedence of ^ is 3
   }else {
      return 0;
   }
}

string inToPo(string s){
    char x;
    string postfix = "";
    int l = s.length();
    Stack s2;
    Node* n1 = new Node();
    n1->data = '#';
    s2.push(n1);
    for(int i = 0;i<l;i++){
        Node* n2 = new Node();
        x = s[i];
        if(isalnum(x))
        postfix+=x;
        else if(x=='('){
            n2->data='(';
            s2.push(n2);
        }
        else if(x=='^'){
            n2->data='^';
            s2.push(n2);
        }
        else if(x==')'){
            while (s2.peek() != '#' && s2.peek() != '(')
            {
                postfix+=s2.peek();
                s2.pop();
            }
            s2.pop();
        }
        else{
            if(preced(x)>preced(s2.peek())){
                n2->data = x;
                s2.push(n2);
            }
            else{
                while (s2.peek() != '#' && preced(x)<=preced(s2.peek()))
                {
                    postfix += s2.peek();
                    s2.pop();
                }
                n2->data = x;
                s2.push(n2);
                
            }
        }
    }

    while(s2.peek()!='#'){
        postfix+=s2.peek();
        s2.pop();
    }
    return postfix;
}

float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');
}

int isOperator(char ch) {
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;
   return -1;
}

int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;
   return -1;
}

float operation(int a, int b, char op) {
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a);
   else
      return INT8_MIN;
}

float postfixEval(string postfix) {
   int a, b;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++) {
      if(isOperator(*it) != -1) {
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }else if(isOperand(*it) > 0) {
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}

int main(){
    string s,s1;
    cout << "Enter the string.\n";
    cin >> s;
    if(balanced(s)){
        cout << "Expression is balanced.\n";
        s1 = inToPo(s);
        cout << "The postfix expression is : " << s1 << endl;
        cout << "The evaluated expression is : " << postfixEval(s1) << endl;
    }
    else{
        cout << "Expression is not balanced.\n";
    }
    return 0;
}