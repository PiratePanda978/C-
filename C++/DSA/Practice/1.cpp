#include<bits/stdc++.h>
using namespace std;

void printRange(int arr[],long n){
    clock_t start,end;
    start = clock();
    int i,min,max;
    min = arr[0];
    max = arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
    cout << "[" << min << "," << max << "]\n";
}

int main(){
    long n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        arr[i] = rand();
    }
    printRange(arr,n);
}