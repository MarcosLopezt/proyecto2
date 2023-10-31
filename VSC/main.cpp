#include <iostream>
#include <fstream> //file stream, para manejar archivos
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "string.h"
#include "estructuras/HashMap.h"
#include "articulo.h"
#include <limits>
#include <ctime>
#include "estructuras/min_stock.h"

using namespace std;

void menu(){
    cout<< "--------------------------------------------"<<endl;
    cout<<"|       PROCESADOR INVENTARIO FISICO.        |"<<endl;
    cout<< "--------------------------------------------"<<endl;
    cout<< "[1]- Cantidad total de articulos diferentes. "<<endl;
    cout<< "[2]- Cantidad total de articulos."<<endl;
    cout<< "[3]- El stock del articulo ingresado como argumento."<<endl;
    cout<< "[7]- SALIR"<<endl;

}

unsigned int hashFunc(string clave){
    unsigned int key = 0;

    for (int i =0; i<clave.length();i++) {
       key = key* 31 + static_cast<unsigned int> (clave[i]);
    }

    return key;
}

void exploreHeaders(string fileName, int &cont_depositos){
    fstream fin;

    fin.open("./"+ fileName, ios::in); //input output system

    string headers, header;
    getline(fin,headers);
    stringstream s(headers);
    while(getline(s,header, ',')) //s seria la fila, que la separa segun las comas, y guarda la info en header.
    {
        cont_depositos++;
    }
}

void exploreCSV(string fileName, HashMap<string, articulo> hash, int &total_art_dif, int &total_art) { //explora el csv, y devuelve total_art_dif y total_art.

    fstream fin;
    fin.open("./" + fileName, ios::in);

    string line, word;
    //getline(fin,line);

    while (getline(fin, line)) //fila por fila en el line.
    {

        int col_actual = 0;
        int acum_stock = 0; //cant stock por artic
        string codigo = " "; //codigo de barras
        string nombre_articulo = " ";

        total_art_dif++; //suma filas
        stringstream s(line);

        while (getline(s, word, ',')) //columna por columna
        {
            if (col_actual == 1) {
                codigo = word;
            }

            if (col_actual == 2) {
                nombre_articulo = word;
            }

            if (col_actual >= 3) {
                int cantidad_art = atoi(word.c_str());  //pasamos de string a entero, la cantidad de artic que hay en ese deposito.
                if (cantidad_art >= 1) {
                    total_art += cantidad_art;
                    acum_stock += cantidad_art;
                }
            }
            col_actual++;
        }

        articulo new_articulo(nombre_articulo, acum_stock, codigo, " ");
        //new_articulo.imprimir();
        hash.put(nombre_articulo, new_articulo);
    }
    fin.close();
}


void stock(HashMap<string, articulo> hashmapa) {
    string articName;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //LIMPIAR BUFFER de entrada.
    std::cin.clear();

    cout << endl << "Ingrese el nombre del articulo que desea buscar: " << endl;
    getline(cin, articName);

    try {
        articulo artic_buscado = hashmapa.get(articName);
        cout << endl << "Articulo Buscado:  " <<endl<<endl;
        artic_buscado.imprimir();
    } catch (int error) {
        if (error == 404) {
            cout << "Articulo no encontrado. " << endl;
        } else {
            cout << "Error desconocido" << endl;
        }
    }
}

int main(int argc, char **argv){

    clock_t begin;
    cout<< "Comenzando a medir tiempo"<<endl;
    begin = clock();

    int n, cont_depositos = -3;
    string archivo;

    HashMap<string,articulo> hash(1000,hashFunc);

    int total_art_dif = -1; //los headers
    int total_art = 0;

   cout<< "Cantidad de argumentos: "<< argc <<endl;
    for (int i = 0; i < argc; i++){

        cout<< "Argumento "<< i << " : " << argv[i] << endl;

        if(strcmp(argv[i], "-file") == 0){
            cout<<endl<< "Nombre del archivo: "<< argv[i+1] <<endl; //hay que hacer checkeo de que sea un archivo y que exista.
            archivo = argv[i+1];
            exploreHeaders(archivo,cont_depositos);
            cout<< "Cantidad de depositos: "<<cont_depositos<<endl;
            //exploreCSV(archivo,hash, total_art_dif,total_art);
            min_stock(archivo,2);
            //hash.print();
            //stock(hash);
            break;
        }
    }
/*
    do{
        menu();
        cin>>n;
        switch (n) {
            case 1:
                cout<<endl<<"Total de articulos diferentes: "<<total_art_dif<<endl<<endl;
                break;

            case 2:
                cout<< endl<<"Cantidad total de articulos: "<<total_art<<endl<<endl;
                break;

            case 3:
                stock(hash);
                break;

        }

    }while(n != 7);
*/
    clock_t end = clock();

    double time = (double(end - begin) / CLOCKS_PER_SEC);

    cout << " Execution Time: " << time << endl;

    return 0;
}

