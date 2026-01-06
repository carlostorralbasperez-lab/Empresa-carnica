#include<iostream>

using namespace std;

float promedio(float A[],int n);
float mayor(float A[],int n);
float menor(float A[],int n);
float cant(float A[],int n);

int main(){
int n=0;
float promedi=0,may=0,men=0,can=0;

    cout<<"Introduzca la cantidad de vehiculos: "<<endl;
    cin>>n;
    float litros[n];

    for (int i=0;i<n;i++){
        cout<<"\nIntroduzca la cantidad de litros consumidos por el vehiculo "<<i+1<<": " <<endl;
        cin>>litros[i];

        cout<<"\nEl consumo del carro "<<i+1<<" es de: "<<endl;
        cout<<litros[i];
    }

    promedi=promedio(litros,n);
    may=mayor(litros,n);
    men=menor(litros,n);
    can=cant(litros,n);


    cout<<"\nEl promedio de litros es de: "<<promedi;
    cout<<"\nEl mayor consumo fue de: "<<may;
    cout<<"\nEl menor consumo fue de: "<<men;
    cout<<"\nLa cantidad de autos que su consumo fue menor a 50 es de: "<<can;





    return 0;
}
float promedio(float A[],int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma+=A[i];
    }
    return suma/n;
}
float mayor(float A[],int n){
    float mayor=0;
    for(int i=0;i<n;i++){
        if(i==0){
            mayor=A[i];
        }
        if(mayor<A[i]){
            mayor=A[i];
        }
    }
    return mayor;
}
float menor(float A[],int n){
    float menor=0;
    for(int i=0;i<n;i++){
        if(i==0){
            menor=A[i];
        }
        if(menor>A[i]){
            menor=A[i];
        }
    }
    return menor;
}
float cant(float A[],int n){
    int cant=0;
    for(int i=0;i<n;i++){
        if (A[i]<50)
        {
            cant++;
        }
    }
    return cant;
}