#include <iostream>
using namespace std;

long long contador = 0;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  
    {   
        if (arr[j] < pivot)  
        {  
            i++; 
            
            swap(&arr[i], &arr[j]);  
            if(arr[i]!=arr[j])
                contador += 2*(j-i)-1;
        }  
    }  
    swap(&arr[i + 1], &arr[high]);
    if(arr[i+1]!=arr[high])
        contador += 2*(high - (i+1))-1;  
    
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}   
  
int main(){
    int n;
    cin >> n;
    int m;
    for (int i = 0; i < n; i++){
        cin >> m;
        int *A = new int[m];
        for (int j = 0; j < m; j++){
            cin >> A[j];
        }
        quickSort(A,0,m-1);
        cout << "La mejor cantidad de swaps de trenes es "<<contador<<" swaps.\n";
        contador = 0;
        /* code */
    }
    
    

    return 0;
}
