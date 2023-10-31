#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_

#include "nodo.h"
#include <iostream>
#include "../../../u03-pilas-MarcosLopezt/Pila/Pila.h"

using namespace std;

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */

template <class T> class Lista {
protected:
    nodo<T> * inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    void fnInvierte();

    void print();

    void insertAfter2(T oldValue, T newValue, T n);

    void moverPrimero(int pos);

    void moverUltimo(int pos);

    void invertir(int pos);

    void moverSegundo(int d);

};



/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T> Lista<T>::Lista() {
    inicio = nullptr;
}




/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T> Lista<T>::Lista(const Lista<T> &li) {
    inicio = li.inicio;
}



/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Lista<T>::~Lista() {
    vaciar();
}




/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() {
    return inicio == nullptr;
}




/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int Lista<T>::getTamanio() {
    nodo<T> *aux = inicio; //un puntero aux para calcular el tamaño de la lista.
    int tam = 0;

    while(aux != nullptr){ //si el nodo no es nulo, igualamos el aux al proximo nodo y aumentamos el tam.
        aux = aux->getSiguiente();
        tam++;
    }

    return tam;
}





/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T> void Lista<T>::insertar(int pos, T dato) {
    nodo<T> *aux = inicio;
    int posActual = 0;
    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);

    if(pos == 0){
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux!= nullptr && posActual<pos-1){
        aux = aux->getSiguiente();
        posActual++;
    }

    if(aux == nullptr){
        throw 400;
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}





/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */

template <class T> void Lista<T>::insertarPrimero(T dato) {
    nodo<T> *aux = inicio;
    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);

    nuevo->setSiguiente(inicio);
    inicio = nuevo;
}





/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarUltimo(T dato) {
    nodo<T> *aux = inicio;
    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);

    if(inicio == nullptr){
        inicio = nuevo;
        return;
    }

    while(aux->getSiguiente()!= nullptr){
        aux=aux->getSiguiente();
    }

    nuevo->setSiguiente(aux->getSiguiente()); //nuevo->setSiguiente(nullptr);
    aux->setSiguiente(nuevo);

}





/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
    nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;
    if(pos == 0){
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }
    while(aux!= nullptr && posActual<pos-1){
        aux = aux->getSiguiente();
        posActual++;
    }

    if(aux == nullptr){
        throw 400;
    }

    aBorrar = aux->getSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());
    delete aBorrar;
}





/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
    nodo<T> *aux = inicio;
    int posActual = 0;

    while(aux!= nullptr && posActual<pos){
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr){
        throw 400;
    }
    return aux->getDato();
}







/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T> void Lista<T>::reemplazar(int pos, T dato) {
    nodo<T> *aux = inicio;
    int posActual = 0;

    if(pos==0){
        aux->setDato(dato);
        return;
    }

    while(aux!= nullptr && posActual<pos-1){
        aux=aux->getSiguiente();
        posActual++;
    }

    if(aux== nullptr){
        throw 400;
    }

    aux->setDato(dato);
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void Lista<T>::vaciar() {
    nodo<T> *aux = inicio, *aBorrar;

    while(aux!= nullptr){
        aBorrar = aux;
        aux=aux->getSiguiente();
        delete aBorrar;
    }

    inicio = nullptr;
}

template <class T> void Lista<T>::print() {
    nodo<T> *aux = inicio;


    while(aux != nullptr){
        cout<<aux->getDato()<< " -> ";
        aux = aux->getSiguiente();
    }

    cout<< "NULL"<<endl;
}

template <class T> void Lista<T>::fnInvierte(){
    nodo<T> *anterior = nullptr, *aux = inicio, *siguiente=inicio;

    if (inicio == nullptr){
        return;
    }
    siguiente = siguiente->getSiguiente();
    while (siguiente != nullptr){
        aux->setSiguiente(anterior);
        anterior = aux;
        aux = siguiente;
        siguiente = siguiente->getSiguiente();

    }
    aux->setSiguiente(anterior);
    inicio = aux;

}

template <class T> void Lista<T>::insertAfter2(T oldValue, T newValue, T n){
    nodo<T> *aux = inicio;
    int contOldValue = 0;

    while(aux != nullptr && contOldValue!= n){
        if(aux->getDato() == oldValue){
            contOldValue++;
        }
        if (contOldValue == n){
            break;
        }
        aux = aux->getSiguiente();
    }

    if(aux == nullptr){
        throw 404;
    }

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);

}


template <class T> void Lista<T>::moverPrimero(int pos) {
    if(esVacia()){
        throw 404;
    }
    if( pos == 0){
        return;
    }
    nodo<T> * aux = inicio;
    nodo<T> *anterior = nullptr;
    int contPos = 0;

    while(aux != nullptr && contPos != pos){
        anterior = aux;
        aux = aux->getSiguiente();
        contPos++;
    }

    if(aux == nullptr || aux->getSiguiente() == nullptr){
        throw 400;
    }
    anterior->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(inicio);
    inicio = aux;

}

template <class T> void Lista<T>::moverUltimo(int pos) {
    if(esVacia()){
        throw 404;
    }

    nodo<T> * aux = inicio;
    nodo<T> * anterior = inicio ;
    int contPos = 0;

    if(pos == 0){
        while(aux->getSiguiente()!= nullptr){
            aux = aux->getSiguiente();
        }
        inicio = anterior->getSiguiente();
        aux->setSiguiente(anterior);
        anterior->setSiguiente(nullptr);
        return;
    }

    while(aux != nullptr && contPos != pos){
        anterior = aux;
        aux = aux->getSiguiente();
        contPos++;
    }

    if(aux == nullptr){
        throw 400;
    }
    if(aux->getSiguiente() == nullptr){
        return;
    }

    anterior->setSiguiente(aux->getSiguiente());
    while(anterior->getSiguiente() != nullptr){
        anterior = anterior->getSiguiente();
    }
    anterior->setSiguiente(aux);
    aux->setSiguiente(nullptr);
}

template <class T> void Lista<T>::invertir(int pos) {

    if(esVacia()){
        throw 404;
    }

    nodo<T> * aux = inicio;
    nodo<T> * anterior;
    Pila<T> pila;
    int contPos = 0, cont2 = 0;

    if(pos == 0){
        while(aux != nullptr) {
            pila.push(aux->getDato());
            aux = aux->getSiguiente();
            contPos++;
        }
        aux = inicio;
        while(cont2 != contPos){
            aux->setDato(pila.pop());
            aux = aux->getSiguiente();
            cont2++;
        }
        return;
    }

    while(aux != nullptr && contPos != pos){
        aux = aux->getSiguiente();
        contPos++;
    }
    anterior = aux;
    if(aux == nullptr){
        throw 400;
    }

    contPos = 0;
    while(aux != nullptr){
        pila.push(aux->getDato());
        aux = aux->getSiguiente();
        contPos++;
    }

    while(cont2 != contPos ){
        anterior->setDato(pila.pop());
        anterior = anterior->getSiguiente();
        cont2++;
    }

}

template <class T> void Lista<T>::moverSegundo(int d) {

    if(esVacia()){
        throw 404;
    }
    nodo<T> * aux = inicio;
    nodo<T> * anterior = inicio;

    if(d == inicio->getDato()){
        aux = inicio->getSiguiente();
        anterior->setSiguiente(aux->getSiguiente());
        aux->setSiguiente(anterior);

        inicio = aux;
        return;
    }

    while(aux->getDato() != d && aux != nullptr) {
        anterior = aux;
        aux = aux->getSiguiente();
    }

    if(aux == nullptr){
        throw 404;
    }

    anterior->setSiguiente(aux->getSiguiente());

    anterior = inicio->getSiguiente();
    aux->setSiguiente(anterior);
    inicio->setSiguiente(aux);

}

#endif