//
// Created by tnovaira on 28/8/2023.
//

#ifndef LISTA_NODO_H
#define LISTA_NODO_H

template<class T>
class nodo {
private:
    T dato;
    nodo<T> * siguiente;

public:
    nodo(){
        siguiente = nullptr;
    }
     T getDato(){
        return dato;
    }
    void setDato(T d){
        dato = d;
    }
    nodo<T> *getSiguiente(){
        return siguiente;
    }
    void setSiguiente(nodo<T> *siguiente){
        this->siguiente = siguiente;
    }

    };


#endif //LISTA_NODO_H
