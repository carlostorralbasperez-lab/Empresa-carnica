#include <iostream>
using namespace std;

void nombre(float A[],int n);
float promedio(float A[],int n);

int main(){

    float notas[5],prom=0;

    for(int i=0;i<5;i++){
        cout<<"Digite la nota del estudiante";
        cin>>notas[i];
    }

    prom=promedio(notas,5);
    nombre(notas,5);

    cout<<"\nEl promedio de las notas es de: "<<prom;







    return 0;
}
float promedio(float A[],int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma+=A[i];
    }
    return  suma/n;
}
void nombre(float A[],int n){
    for(int i=0;i<n;i++){
        cout<<"\nLas notas de los estudiantes son: ";
        cout<<A[i];
    }
}