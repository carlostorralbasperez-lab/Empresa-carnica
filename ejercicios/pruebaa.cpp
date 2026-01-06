#include <iostream>
using namespace std;
void Clasif(double ancho[], double lon[],int t);
double AnchoIrV(double ancho[], double lon[],int t);
int main()
{
    const int NUM_FLORES = 5;
    // Arreglo de anchos de p�talos
    double ancho[NUM_FLORES] = {1.8, 1.2, 1.6, 0.5, 1.9};
    // Arreglo de longitudes de p�talos
    double longitud[NUM_FLORES] = {1.2, 1.8, 2.1, 1.0, 1.4};
    cout << "Clasificacion de las flores existentes:" << endl;

    /*Ponga a partir de aqu� su c�digo*/   
    //c
    Clasif(ancho,longitud,NUM_FLORES);
    double anchoiris=AnchoIrV(ancho,longitud,NUM_FLORES);
    cout<<"el ancho de petalos de Iris Versicolor con petalos de mayor long es: "<<anchoiris<<endl;



    return 0;
}
//a
void Clasif(double ancho[], double lon[],int t){
    int flores=1;
    for(int i=0;i<t;i++){
        if(ancho[i]<=0.6) cout<<"la flor "<<flores<<" es Iris Setosa"<<endl;
        else if(ancho[i]>1.7) cout<<"la flor "<<flores<<" es Iris Virginica"<<endl;
        else if(lon[i]<=1.5) cout<<"la flor "<<flores<<" es Iris Virginica"<<endl;
        else cout<<"la flor "<<flores<<" es Iris Versicolor"<<endl;
        flores++;
    }
}
//b
double AnchoIrV(double ancho[], double lon[],int t){
    int posi_mayorlong=0;
    double mayorlong=0;
   for(int i=0;i<t;i++){
        if(ancho[i]<=0.6){}
        else if(ancho[i]>1.7) {}
        else if(lon[i]<=1.5) {}
        else if(lon[i]>mayorlong){
            posi_mayorlong=i;
            mayorlong=lon[i];
        } 
}
 return ancho[posi_mayorlong];
}