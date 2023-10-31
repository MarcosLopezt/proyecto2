#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_
#include "Lista.h"
#include "../articulo.h"
#include <iostream>
using namespace std;

template <class K, class T> class HashEntry {
private:
    K clave;
    T valor;
    Lista<T> *lista;
public:
    HashEntry(K c, T v){
        clave = c;
        valor = v;
        lista = nullptr;
    }

    bool esListaEnlazada() const{
        return lista != nullptr;
    }
    Lista<T> * getLista(){
        //lista->print();

        return lista;
    }

    void setLista(Lista<T> * lis){
        lista = lis;
    }

    K getClave(){
        return clave;
    }
    void setClave( K c){
        clave = c;
    }
     T getValor(){
        return valor;
    }

    void setValor(T v){
        valor = v;
    }
/*
    ~HashEntry() {
        // Libera la memoria de la lista enlazada (si está asignada).
        if (lista != nullptr) {
            delete lista;
            lista = nullptr;
        }
    }
*/
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_
