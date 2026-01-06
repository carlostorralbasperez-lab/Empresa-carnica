#include<iostream>
#include <sstream>

using namespace std;

string MUN;
float agregarentrega(float (*A)[10], string B[],int n);
void totaltonMun(float A[][10],string B[],int n);
string MayorDia3(float A[][10],string B[],int n);
float munCumpPlan(float A[][10], string B[], int n);
void promMun(float A[][10],string B[],int n);
float modificar(float (*A)[10],string B[]);
void sobrecump(float A[][10],int n);
void menu();

int main(){

    int opcion=0;
    float productos[7][10] = {{0}},plan=0;
    string muni,entrada;
    string ID[10]={"ciego de avila","moron","chambas","primero de enero","ciro Redondo","florencia","majagua","baragua","bolivia","venezuela"};

      
    
    
    while(opcion!=8){
       
    menu();
    cin>>opcion;

    switch(opcion){
        case 1: agregarentrega(productos,ID,7);break;

        case 2:totaltonMun(productos,ID,7);break;

        case 3:muni=MayorDia3(productos,ID,7);
            if(muni=="c"){
                cout<<"Ningun municipio recibio toneladas el dia 3"<<endl;break;
            }
           else  cout<<"\nEl municipio que mas toneladas recibio el dia 3 es: "<<muni;break;
        
        case 4:plan=munCumpPlan(productos,ID,7);
            cout<<"\nLa cantidad de municipios que cumplen con el pan es de: "<<plan;break;

        case 5:promMun(productos,ID,7);break;

        case 6: modificar(productos,ID);break;

        case 7:sobrecump(productos,7);break;

        default: cout<<"Opcion invalida";
        }   
    }
    return 0;
}
                                                    //Subprogramas//                            
        //Para agregar entregas
float agregarentrega(float (*A)[10], string B[], int n){
    string mun;
        float valor = 0;   
                int cont=0;
               

    cout << "\nIntroduzca el ID del municipio: ";
        cin.ignore();
            getline(cin, mun);
                 transform(mun.begin(),mun.end(),mun.begin(),::tolower); 

    for (int i=0;i<n;i++) {
        for (int j=0;j<10;j++) {
            if (mun==B[j]) {
                cont++;
                if (A[i][j] != 0) {
                    cout << "El municipio " << B[j] << " ya recibió su entrega en la semana "<< endl;
                    return 0;
                }

                cout<<"\nIntroduzca la cantidad de toneladas de productos del municipio "<<B[j]<<" en el dia "<<i+1<<": " << endl;

                cin>>valor;
                if (valor>=0)
                {
                    A[i][j]+=valor;
                }
                

                
            }
        }
    } 
    if(cont==0){
        cout<<"Municipio no encontrado";    }
    return 0; 
}


        //Para hallar el total de cada municipio
void totaltonMun(float A[][10],string B[],int n){
        
    for(int j=0;j<10;j++){
       string municipio;
            float total=0;
        
        for(int i=0;i<n;i++){
            municipio=B[j];
           
           total+=A[i][j];
        }
        cout<<"El municipio "<<municipio<<" recibio "<<total<<" toneladas"<<endl;
    }
}
        //Municipio que mayor cantidad recibio el dia 3
string MayorDia3(float A[][10],string B[],int n){
        float mayor=0;
            string municipio,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            if(i==2&&j==0){
                mayor=A[i][j];
                municipio=B[j];
            
        }
            else if(i==2&&mayor<A[i][j]){
                mayor=A[i][j];
                municipio=B[j];
        }
    }
    }
    if(mayor==0){
        return "c";
    }
    
    else return municipio;
}
        //Municipios que cumplen con el plan
float munCumpPlan(float A[][10], string B[], int n) {
        float contador=0;

    for(int j=0;j<10;j++){
        float total=0;
        for (int i=0;i<n;i++){  
            total+=A[i][j];
        }
        if (total>=150){
            contador++;
            cout<<"\nEl municipio "<<B[j]<<" cumple el plan con: "<<total<<" toneladas.";
        } 
        else{
            cout<<"\nEl municipio "<<B[j]<<" no cumple el plan tiene: "<<total<<" toneladas.";
        }
    }

    return contador;
}
        //Hallar el promedio de cada municipio
void promMun(float A[][10],string B[],int n){
         
    for(int j=0;j<10;j++){
        float total=0;
        for(int i=0;i<n;i++){
            total+=A[i][j];
        }
        float promedio=total/n;
            cout<<"\nEl municipio "<<B[j]<<" tiene un promedio de: "<<promedio<<" por dia";
    }
}
        //Modificar las toneladas de un municipio
float modificar(float (*A)[10],string B[]){
        int dia=0;
            float toneladas=0;
                string municip;
        cout<<"Introduzca el nombre del municipio que desea modificar: "<<endl;
            cin.ignore();
                getline(cin, municip);   
                    transform(municip.begin(),municip.end(),municip.begin(),::tolower); 
                    
                        
                             cout<<"Introduzca el dia que desea modificar: "<<endl;
                                cin>>dia;
                                if (dia<1 || dia>7){
                                     cout << "\nDatos invalidos.";
                                        return 0;
                                }
                            cout<<"Introduzca la cantidad de toneladas nuevas: "<<endl;
                                cin>>toneladas;
                                if (toneladas<0) {
                                     cout << "\nDatos invalidos.";
                                        return 0;
                                }
                    for(int i=0;i<7;i++){
                      for(int j=0;j<10;j++){
                            if(B[j]==municip){
                                 A[dia-1][j]=toneladas;
                                    return A[dia][j];
                            }
                        } 
                    }
                       cout<<"\nMunicipio no encontrado";
                        return 0;  
}  
                    
                
                
void sobrecump(float A[][10],int n){
    float totalton=0,ingresos=0;
        long long planIngresos=0;

        cout<<"Introduzca el plan de ingresos de la empresa: "<<endl;
            cin>>planIngresos;

        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                totalton+=A[i][j];
            }
        }
        ingresos=totalton*150;

            if(ingresos>planIngresos){
                cout<<"\nLa empresa ha sobrecumplido el plan de: "<<planIngresos<<" con un total de: "<<ingresos;
            }
            else{
                cout<<"\nLa empresa no sobrecumplio el plan porque genero: "<<ingresos<<" y no excedio el plan de: "<<planIngresos<<" pesos";
            }
}
void menu(){
     cout<<"\n\tDigite la opcion que desee: "<<endl;
        cout<<"\n1.Adicionar una entrega del MINCIN a un municipio.";
        cout<<"\n2.Total de toneladas de cada municipio.";
        cout<<"\n3.Municipio que mayor cantidad recibio el dia 3.";
        cout<<"\n4.Municipios que reciben la cantidad adecuada de toneladas (150).";
        cout<<"\n5.Calcular promedio de productos que se entrega a cada municipio en la semana.";
        cout<<"\n6.Modificar los productos de un municipio especifico.";
        cout<<"\n7.Ver si la empresa ha sobrecumplido el plan de ingresos(1233.43 pesos por tonelada).";
        cout<<"\n8.Salir."<<endl;
       cout<<"Opcion: ";
}