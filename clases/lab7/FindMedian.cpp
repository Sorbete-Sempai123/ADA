#include <iostream>
using namespace std;

long maximo(long *arr,long n){
   long max = arr[0];
   for (long i = 1; i < n; i++){
       if(arr[i]>max){
           max = arr[i];
       }
   }
   return max;
}

//4 argumentos : array , tamaño, divisor, mediana
long FindMed(long *arr,long tam,long divC,long med){
   long *B = new long[tam];
   long i=0,j=tam-1;
   if(divC == 1) return arr[i];
  
   for (long k=0 ; k < tam; k++){
       if((arr[k]/divC)%2 == 0 ){
           B[i]=arr[k];
           i++;}
       else{
           B[j]=arr[k];
           j--;}
   }
   if(med < i-1){//Caso 1
       return FindMed(B,i,(divC+1)/2,med);
   }//Caso 2
   else if( med > i-1){
       return FindMed(&B[i],tam-i,(divC+1)/2,med-(i));
   }//Caso 3
   return maximo(B,i);
}

int main(){
   long n=8000;
   long max = 2147483648;//Siguiente 2^n de 2 mil millones
   long *A = new long[n];
   for (long i = 0; i < n; i++){
       long m;
       cin >>m;
       A = new long[m];
       for (long j = 0; j < m; j++){
           cin >> A[j];
       }
       cout << FindMed(A,n,(max+1)/2,n/2-1) << endl;
       /* code */
   }
 
 
   return 0;
}
