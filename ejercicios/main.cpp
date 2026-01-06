#include <iostream>

using namespace std;
void clasificacion(double A[],double B[],int n);
double mayor_ancho(double A[],double B[],int n);
double cant_may(double A[],double B[],int n);
int main()
{

    const int NUM_FLORES = 5;

    double mayor=0,cant_mayor=0;

    // Arreglo de anchos de p�talos
    double ancho[NUM_FLORES] = {1.8, 1.2, 1.6, 0.5, 1.9};

    // Arreglo de longitudes de p�talos
    double longitud[NUM_FLORES] = {1.2, 1.8, 2.1, 1.0, 1.4};

    cout << "Clasificacion de las flores existentes:" << endl;

   clasificacion(ancho,longitud,5);
   mayor=mayor_ancho(ancho,longitud,5);
   cant_mayor=cant_may(ancho,longitud,5);

    cout<<"\nEl mayor ancho de petalos de la flor Iris Versicolor es de: "<<mayor;
    cout<<"\nLas iris virginicas supera en "<<cant_mayor<<" a las iris setosas. ";

    return 0;
}
void clasificacion(double A[],double B[],int n){
    for (int i=0;i<n;i++){
        if(A[i]<=0.6){
            cout<<"\nLa flor es una Iris setosa";
        }
        else if(A[i]>1.7){
            cout<<"\nLa flor es una Iris Virginica";
        }
        else if(B[i]<=1.5){
            cout<<"\nLa flor es Iris Virginica";
        }
        else    {
            cout<<"\nLa flor es Iris Versicolor";

        }
    }
}


double mayor_ancho(double A[],double B[],int n){
    float mayor=0;

     for (int i=0;i<n;i++){
        if(A[i]<=0.6){
        }
        else if(A[i]>1.7){

        }
        else if(B[i]<=1.5){
        }
        else if(B[i]>mayor)  {
            mayor=A[i];
        }
    }
    return mayor;
}
double cant_may(double A[],double B[],int n){
    double v=0,s=0;
    for (int i=0;i<n;i++){
        if(A[i]<=0.6){
            s++;
        }
        else if(A[i]>1.7){
            v++;
        }
        else if(B[i]<=1.5){
            v++;
        }
    } if(v>=s){
            v-s;
        }
        else{
            v-s*-1;}
            return v-s;
}