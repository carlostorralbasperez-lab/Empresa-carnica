#include<iostream>

using namespace std;

void cambio(int A[][3],int n);

int main(){

    int arreglo[3][3];

    for (int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arreglo[i][j];
        }
    }
    cambio(arreglo,3)
  


    return 0;
}
void cambio(int A[][3],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i%3==0){
                A[i]=0;
            }
            if(j%3==0){
                A[j]=0;
            }
            if(A[i]==5){
                A[i]=1;
            }
            if(B[j]==5){
                A[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j];
        }
    }
}