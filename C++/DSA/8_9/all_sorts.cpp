#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[],int n){
    int i,j,min,temp;
    clock_t start,end;
    start = clock();
    for (i = 0; i < n-1; i++){
        min = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min])  
            min = j;  
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}

void bubbleSort(int arr[],int n){
    clock_t start,end;
    start = clock();
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}

void insertionSort(int arr[],int n){
    clock_t start,end;
    start = clock();
    int i,j,k;
    for(i=1;i<n;i++){
        k = arr[i];
        j = i-1;
        while(j>=0&&arr[j]>k){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}

void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int tempL[n1];
    int tempR[n2];
    for(i=0;i<n1;i++)
    tempL[i] = arr[l+i];
    for(j=0;j<n2;j++)
    tempR[j] = arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2){
        if(tempL[i]<=tempR[j]){
            arr[k] = tempL[i];
            i++;
        }
        else{
            arr[k] = tempR[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = tempL[i];
        i++;
        k++;
    }
    while (j < n2) { 
        arr[k] = tempR[j]; 
        j++; 
        k++; 
    }
}

void mergeSort(int arr[],int l,int r){
    clock_t start,end;
    start = clock();
    if(l<r){
        int m = l+(r-1)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}

int partition (int arr[], int low, int high)  
{
    int temp;
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  
    {
        if (arr[j] < pivot)  
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;  
        }  
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}  

void quickSort(int arr[], int low, int high)  
{
    clock_t start,end;
    start = clock();
    if (low < high)  
    {  
        int pi = partition(arr, low, high);    
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}  

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}

void generateRandom(int n){
    clock_t start,end;
    start = clock();
    for(int i=0;i<n;i++){
        cout << rand() << endl;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}

int main(){
    int n,i;
    clock_t start,end;
    cout << "Enter the size : ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : \n";
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    int option;
    option=-1;
    while(option!=0)
    {
        cout << "Enter your choice :\n1 : Selection Sort.\n2 : Merge Sort\n3 : Bubble Sort\n4 : Insertion Sort\n5 : Quick Sort\n6 : Random Number Generation\n";
        cin >> option;
        switch (option)
        {
        case 1:
            SelectionSort(arr,n);
            printArray(arr,n);
            break;
        case 2:
            mergeSort(arr,0,n-1);
            printArray(arr,n);
            break;
        case 3:
            bubbleSort(arr,n);
            printArray(arr,n);
            break;
        case 4:
            insertionSort(arr,n);
            printArray(arr,n);
            break;
        case 5:
            quickSort(arr,0,n-1);
            printArray(arr,n);
            break;
        case 6:
            generateRandom(n);
            break;
        case 0:
            break;
        default:
            cout << "Invalid Option.\n";
            break;
        }
    }
    return 0;
}