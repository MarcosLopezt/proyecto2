/*#include <iostream>
#include <stdlib.h>
#include "string.h"
#include "estructuras/HashMap.h"
#include "articulo.h"
using namespace std;

int codigo_ascii(string code, int total, int cont){ //funcion que cambia el cod de barras a un numero.
    int valor = 0;
    int arreglo[total];
    /*
    if(code.length() >= 4){
        for(int i = 0; i<4 ; i++){
            valor += static_cast<int> (code[i]);
        }

        valor += static_cast<int> (code[code.length()-1]); //mas el ultimo caracter del codigo.
    }else{
        for (int i = 0;i<code.length();i++){
            valor += static_cast<int> (code[i]);
        }
    }

    for(int i=0; i<code.length();i++){
        valor += static_cast<int> (code[i]);
    }

    for (int j = 0; j<cont-1;j++){ //se repite el codig
        if(arreglo[j] == valor%total){
            //otra funcion.
            char x;
            cout<< "SE REPITE"<<endl<<endl<<endl<<endl;
            cin>>x;
            valor = valor / 2;
        }
    }

    arreglo[cont]= valor%total;

    //haria valor%300, para que se haga mas chico el numero.
    cout<< "VALOR ASCII: "<<valor%total<<endl<<endl;
    return valor%total;
}


int main(){
    string cod = "AMLM-AM-U61-A";
    cout<< codigo_ascii(cod,6,0)<<endl;
    cout<< codigo_ascii("TURBOAR_M288C_SEC.PELO.PARED",6,1)<<endl;
    cout<< codigo_ascii("TURBOAR_M798C_SEC.MANO.PARED",6,2)<<endl;
    cout<< codigo_ascii("CTNIH-210-90",6,3)<<endl;
    cout<< codigo_ascii("SMFS45 SIN/REG-DERECHA",6,4)<<endl;
    cout<< codigo_ascii("PJZZ52/18",6,5)<<endl;
    cout<< codigo_ascii("PJZZ52/18",6,6)<<endl;
    cout<< codigo_ascii("AMAMMA",6,7)<<endl;
}




int codigo_ascii(string code, int total, int cont){ //funcion que cambia el cod de barras a un numero.
    int valor = 0;
    int arreglo[total];

    for(int i=0; i<code.length();i++){
        valor += static_cast<int> (code[i]);
    }


    for (int j = 0; j<cont-1;j++){ //se repite el codig
        if(arreglo[j] == valor%431){
            //otra funcion.
            char x;
            cout<<endl;
            cout<< "SE REPITE"<<endl<<endl<<endl<<endl;
            //cin>>x;
            valor = valor / 2;
        }
    }

    arreglo[cont]= valor%431;

    //haria valor%300, para que se haga mas chico el numero.
    cout<< "VALOR ASCII: "<<valor%431<<endl<<endl;

    return valor%431;
}

*/



