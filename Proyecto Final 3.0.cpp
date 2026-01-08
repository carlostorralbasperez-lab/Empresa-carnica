#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

string MUN;
float mayor3=0;
void AgregarMunicipio(float (*A)[10],string B[]);
float agregarentrega(float (*A)[10], string B[],int n);
void totaltonMun(float A[][10],string B[],int n);
string MayorDia3(float A[][10],string B[],int n);
float munCumpPlan(float A[][10], string B[], int n);
void promMun(float A[][10],string B[],int n);
float modificar(float (*A)[10],string B[],int n);
void sobrecump(float A[][10],string B[],int n);
void mostrarTabla(float A[][10], string B[], int nDias, int nMun);
void menu();

int main(){

    int opcion=0;
    float productos[7][10] = {{0}},plan=0;
    string municipios[10]={""},muni,entrada;
    
    while(opcion!=10){
       
        menu();
       
        if(!(cin>>opcion)){
            cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    switch(opcion){
        case 1: AgregarMunicipio(productos,municipios);break;;

        case 2: agregarentrega(productos,municipios,7);break;

        case 3:totaltonMun(productos,municipios,7);break;

        case 4:muni=MayorDia3(productos,municipios,7);
            if(muni==""){
                cout<<"\nNo se ha agregado municipios todavia";break;
            }
            else if(muni=="c"){
                cout<<"\nNo se ha agregado entregas a ningun municipio";break;
            }
           else{ 
             cout<<setprecision(10);
            cout<<"\nEl municipio que mas toneladas recibio el dia 3 es "<<muni<<" con un total de: "<<mayor3;
           };break;
        case 5:plan=munCumpPlan(productos,municipios,7);
            if(plan!=-1){
            cout<<"\nLa cantidad de municipios que reciben la cantidad adecuada es de: "<<plan;
            };break;
        case 6:promMun(productos,municipios,7);break;

        case 7: modificar(productos,municipios,7);break;

        case 8:sobrecump(productos,municipios,7);break;
        
        case 9:mostrarTabla(productos,municipios,7,10);break;
            
        case 10:cout<<"\nSaliste.";break;

        default :cout<<"Opcion invalida";break;
      
        }   
    }
    return 0;
}

                                                                         //Subprogramas//   
         //Para inicializar las entregas
void Inicializar(float (*A)[10]){
    for(int i=0;i<7;i++){
        for(int j=0;j<10;j++){
            A[i][j]=-1;
        }
    }
}

                                                                    //Para agregar municipios
void AgregarMunicipio(float (*A)[10],string B[]){
    string mun;

    for(int j=0;j<10;j++){
         // Validacion municipios agregados
        if(!B[j].empty()){
            cout<<"\nYa se agregaron municipios";
            return;
        }
    }
    //Agregar municipios
    for(int i=0;i<10;i++){
            if(B[i]==""){
            cout<<"\nDigite el nombre del municipio "<<i+1<<":";
                getline(cin >> ws, mun);
                         transform(mun.begin(),mun.end(),mun.begin(),::tolower); 
           B[i]=mun;
           cout<<"Municipio agregado con exito";
        }
     
}
Inicializar(A);//Llamada para inicializar las entregas
}

                                                                  //Para agregar entregas
float agregarentrega(float (*A)[10], string B[], int n){
    string mun;
        float valor=0;   
         // Validacion municipios agregados
                for(int i=0;i<10;i++){
                    if(B[i]==""){
                        cout << "\nNo se han agregado municipios todavia\n";
                        return 0;
                    }
                }
                for (int i=0;i<n;i++) {
                    for (int j=0;j<10;j++){
         //Validacion de las entregas
                if(A[i][j]>=0){
                    cout<<"\nYa se realizaron las entregas!\n";
                    return 0;
                }
            }
        }
        //Agrego de entregas
    for (int i=0;i<n;i++) {
        for (int j=0;j<10;j++) {
             cout<<"\nIntroduzca la cantidad de toneladas de productos del municipio "<<B[j]<<" en el dia "<<i+1<<": " << endl;
                cin>>valor;
                    setprecision(10);
                        if (cin.fail()||valor<0) {
                             cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout<<"\nIntroduzca una cantidad de toneladas validas\n";
                                        j--;
                        } 
                        else{
                             A[i][j]=valor;
                         }
            }
        }
        return 0;
    } 

                                                             //Para hallar el total de cada municipio
void totaltonMun(float A[][10],string B[],int n){

         // Validacion municipios agregados
         for(int i=0;i<10;i++){
                    if(B[i]==""){
                       cout << "\nNo se han agregado municipios todavia\n";
                        return;
                    }
                }
        
    for(int j=0;j<10;j++){
        
       string municipio;
            float total=0;
        
        for(int i=0;i<n;i++){
            //Validacion de las entregas
            if(A[i][j]<0){
                cout<<"\nNo se ha agregado entregas a ningun municipio\n";
                return;
            }
            //Total de los municipios
            municipio=B[j];
           
           total+=A[i][j];
        }
         cout<<setprecision(10);
        cout<<"El municipio "<<municipio<<" recibio "<<total<<" toneladas"<<endl;
    }
}

                                                        //Municipio que mayor cantidad recibio el dia 3
string MayorDia3(float A[][10],string B[],int n){
        float mayor=0;
            string municipio,c;
            for(int i=0;i<10;i++){
            // Validacion municipios agregados
                    if(B[i]==""){
                        return "";
                    }
                }
            //Validacion de las entregas
                for(int i=0;i<7;i++){
                    for(int j=0;j<10;j++){
                        if(A[i][j]<0){
                            return "c";
                        }
                    }
                }
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            if(i==2&&j==0){
                mayor=A[i][j];
                municipio=B[j];
                mayor3=mayor;
               
            
        }
            else if(i==2&&mayor<A[i][j]){
                mayor=A[i][j];
                municipio=B[j];
                mayor3=mayor;
        }
    }
    }
   return municipio;
}

                                                      //Municipios que cumplen con el plan de 150 toneladas
float munCumpPlan(float A[][10], string B[], int n) {
        float contador=0;
            // Validacion municipios agregados
            for(int i=0;i<10;i++){
                    if(B[i]==""){
                        cout << "\nNo se han agregado municipios todavia\n";
                        return -1;
                    }
                }
            //Validacion de las entregas
                for(int i=0;i<7;i++){
                    for(int j=0;j<10;j++){
                        if(A[i][j]<0){
                            cout<<"\nNo se han realizado entregas\n";
                            return -1;
                        }
                    }
                }

    for(int j=0;j<10;j++){
        float total=0;
        for (int i=0;i<n;i++){  
            total+=A[i][j];
        }
        if (total>=150){
            contador++;
            cout<<setprecision(10);
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
             // Validacion municipios agregados
            for(int i=0;i<10;i++){
                    if(B[i]==""){
                        cout << "\nNo se han agregado municipios todavia\n";
                        return;
                    }
                }
            //Validacion de las entregas
                for(int i=0;i<n;i++){
                    for(int j=0;j<10;j++){
                        if(A[i][j]<0){
                            cout<<"\nNo se han realizado entregas\n";
                            return;
                        }
                    }
                }
     //hallar promedio    
    for(int j=0;j<10;j++){
        float total=0;
        for(int i=0;i<n;i++){
            total+=A[i][j];
        }
        float promedio=total/n;
             cout<<setprecision(10);
                cout<<"\nEl municipio "<<B[j]<<" tiene un promedio de: "<<promedio<<" por dia";
    }
}

                                                             //Modificar las toneladas de un municipio
float modificar(float (*A)[10],string B[],int n){
        int dia=0;
            float toneladas=0;
                string municip;
            // Validacion municipios agregados
            for(int i=0;i<10;i++){
                    if(B[i]==""){
                        cout << "\nNo se han agregado municipios todavia\n";
                        return 0;
                    }
                }
            //Validacion de las entregas
                for(int i=0;i<n;i++){
                    for(int j=0;j<10;j++){
                        if(A[i][j]<0){
                            cout<<"\nNo se han realizado entregas\n";
                            return 0;
                        }
                    }
                }
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
                       cout<<"\nMunicipio no encontrado\n";
                        return 0;  
}  

                                                            //Para saber si la empresa sobrecumplio el plan              
void sobrecump(float A[][10],string B[],int n){
    float totalton=0,ingresos=0;
        long long planIngresos=0;

            // Validacion municipios agregados
            for(int i=0;i<10;i++){
                    if(B[i]==""){
                        cout << "\nNo se han agregado municipios todavia\n";
                        return;
                    }
                }
            //Validacion de las entregas
                for(int i=0;i<n;i++){
                    for(int j=0;j<10;j++){
                        if(A[i][j]<0){
                            cout<<"\nNo se han realizado entregas\n";
                            return;
                        }
                    }
                }

        cout<<"Introduzca el plan de ingresos de la empresa: "<<endl;
            cin>>planIngresos;

        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                totalton+=A[i][j];
            }
        }
        ingresos=totalton*150;

            if(ingresos>planIngresos){
                 cout<<setprecision(10);
                cout<<"\nLa empresa ha sobrecumplido el plan de: "<<planIngresos<<" con un total de: "<<ingresos;
            }
            else{
                 cout<<setprecision(10);
                cout<<"\nLa empresa no sobrecumplio el plan porque genero: "<<ingresos<<" y no excedio el plan de: "<<planIngresos<<" pesos";
            }
}

                                                                            //Tabla
void mostrarTabla(float A[][10], string Municipios[], int nDias, int nMun) {
    // Validacion municipios agregados
    for (int j = 0; j < nMun; j++) {
        if (Municipios[j].empty()) {
            cout << "\nNo se han agregado municipios todavia\n";
            return;
        }
    }
    
    cout << "\nTabla de entregas por municipio y dia:\n\n";
    cout<<left<<setw(10)<<"Dia";
    for (int j=0;j<nMun;j++) {
        cout<< setw(17) << Municipios[j];
    }
    cout << endl;

   
    string dias[7] = {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};

   
    for (int i = 0; i < nDias; i++) {
        cout<< setw(10) << dias[i];
        for (int j = 0; j < nMun; j++) {
             cout<<setprecision(10);
            cout <<setw(17) << A[i][j];
        }
        cout << endl;
    }
}
                                                                                 //Menu
void menu(){
        cout<<"\n\tDigite la opcion que desee: "<<endl;
        cout<<"\n1.Adicionar nombre del municipio";
        cout<<"\n2.Adicionar una entrega del MINCIN a un municipio.";
        cout<<"\n3.Total de toneladas de cada municipio.";
        cout<<"\n4.Municipio que mayor cantidad recibio el dia 3.";
        cout<<"\n5.Municipios que reciben la cantidad adecuada de toneladas (150).";
        cout<<"\n6.Calcular promedio de productos que se entrega a cada municipio en la semana.";
        cout<<"\n7.Modificar los productos de un municipio especifico.";
        cout<<"\n8.Ver si la empresa ha sobrecumplido el plan de ingresos(1233.43 pesos por tonelada).";
        cout<<"\n9.Mostrar tabla";
        cout<<"\n10.Salir."<<endl;
        cout<<"Opcion: ";
}