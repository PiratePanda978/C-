#include<bits/stdc++.h>
using namespace std;
struct account{
    int acc_no;
    char name[20];
    char acc_type[20];
    int bal;
};
int main()
{
    int x,i,n;
    x=1;
    char na[20];
    cout << "Enter the number of account holders :" << endl;
    cin >> n;
    struct account acc[n];
    cout << "Enter the details :\n";
    for(i=0;i<n;i++)
    {
        cout << "Enter account no :\n";
        cin >> acc[i].acc_no;
        cout << "Enter name :\n";
        cin >> acc[i].name;
        cout << "Enter the account type 'savings' or 'demat': \n";
        cin >> acc[i].acc_type;
        cout << "Enter the account balance:\n";
        cin >> acc[i].bal;
    }

    //subquestion 1

    cout << "Enter the name to be searched :\n";
    cin >> na;
    for(i=0;i<n;i++)
    {
        if(strcmp(na,acc[i].name)==0)
        {
            x=0;
            cout << acc[i].name << "\n" << acc[i].bal << "\n" << acc[i].acc_type << "\n" << acc[i].acc_no;
        }
    }
    if(x==1)
    cout << "Not found";

    //subquestion2
    for(i=0;i<n;i++)
    {
        if(acc[i].bal<500)
        {
            cout << "\n" << acc[i].name << "\n" << acc[i].bal << "\n" << acc[i].acc_type << "\n" << acc[i].acc_no;
        }
    }

    //subquestion3

    for(i=0;i<n;i++)
    {
        if(strcmp(acc[i].acc_type,"demat")==0)
        {
            cout << "\n" << acc[i].name << "\n" << acc[i].bal << "\n" << acc[i].acc_type << "\n" << acc[i].acc_no;
        }
    }
    return 0;
}