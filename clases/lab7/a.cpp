#include <iostream>
#include <random>
#include <time.h>

#define MAX 16

using namespace std;
mt19937 mt(time(0));

void Generador(int *array,int n,int m = 0){
    for(int i=0 ; i < n ; i++ ) {
        array[i] = mt()%(MAX);
    }
}

void printarr(int *arr,int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int maximo(int *arr,int n){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout <<endl <<  "MAX ->"<<max<<endl;
    return max;
}

//4 argumentos , array , tamaño, divisor
int FindMed(int *arr,int tam,int max,int div,int med){
    cout << "Begin ->";
    
    int *B = new int[tam];
    int i=0,j=tam-1;
    int divC = max/div;
    if(divC == 1 || med == 0){
        cout << "Caso Final" <<"//"<<med << "\n";
        return arr[i];
    }
    for (int k=0 ; k < tam; k++){
        if((arr[k]/divC)%2 == 0 ){
            B[i]=arr[k];
            i++;
        }
        else{
            B[j]=arr[k];
            j--;
        }
    }
    printarr(B,tam);
    cout << i << "<>" << j << "=" << tam-i;
    cout << " | Divc" << divC << endl;
    if(med < i-1){//Caso 1
        cout << "Caso 1" <<"//"<<med <<"\n";
        return FindMed(B,i,max,div*2,med);
    }//Caso 2
    else if( med > i-1){
        cout << "Caso 2" <<"//"<<med-(i) << "\n";
        return FindMed(&B[i],tam-i,max,div*2,med-(i));
    }
    cout << "Caso 3" <<"//"<<med << "\n";
    return maximo(B,i);
}

int main(){
    int n=8;
    int *A = new int[n];
    Generador(A,n);
    printarr(A,n);
    cout << endl;
    cout<<FindMed(A,n,MAX,2,n/2-1)<<endl;


    return 0;
}
