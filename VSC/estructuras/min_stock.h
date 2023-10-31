//
// Created by tnovaira on 30/10/2023.
//

#ifndef VSC_MIN_STOCK_H
#define VSC_MIN_STOCK_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "articulo.h"
#include "ArbolBinarioAVL.h"

using namespace std;

//minimo de stock
articulo min_stock(string fileName, int n){
    fstream fin;
    fin.open("./" + fileName, ios::in);

    ArbolBinarioAVL<int> arbol;

    string line, word;

    while(getline(fin,line)){
        int col_actual = 0;
        int acum_stock = 0; //cant stock por artic
        string codigo = " "; //codigo de barras
        string nombre_articulo = " ";

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
                    acum_stock += cantidad_art;
                }
            }
            col_actual++;
        }

        //articulo new_articulo(nombre_articulo, acum_stock, codigo, " ");

        arbol.put(acum_stock,nombre_articulo);
    }

    arbol.print();
}



#endif //VSC_MIN_STOCK_H
