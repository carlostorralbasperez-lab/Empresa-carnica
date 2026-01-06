#include<iostream>

using namespace std;



int main(){

    float prueba[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            prueba[i][j]=-1;
        }
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<prueba[i][j];
        }
    }



}