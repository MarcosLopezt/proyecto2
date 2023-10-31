#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntry.h"
#include "Lista.h"
#include "../articulo.h"
#include "nodo.h"
#include <iostream>
using namespace std;

template <class K, class T>
class HashMap
{
private:
    HashEntry<K, T> **tabla;
    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMap(unsigned int k);

    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

    void print();
};

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int k)
{
    tamanio = k;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        tabla[i] = NULL;
    }
    hashFuncP = hashFunc;
}

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K))
{
    tamanio = k;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        tabla[i] = NULL;
    }
    hashFuncP = fp;
}

template <class K, class T>
HashMap<K, T>::~HashMap()
{
    for (int i = 0; i < tamanio; i++)
    {
        if (tabla[i] != NULL)
        {

            if (tabla[i]->esListaEnlazada()) {
                delete tabla[i]->getLista();
            }

            delete tabla[i];
        }
    }
}

template <class K, class T>
T HashMap<K, T>::get(K clave)
{
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tabla[pos] == NULL)
    {
        throw 404;
    }

    if(tabla[pos]->getClave() == clave){ //hay error aca
        return tabla[pos]->getValor();

    }else{
        if(tabla[pos]->esListaEnlazada()){
            //recorrer lista.
            Lista<T> *aux = tabla[pos]->getLista();
            int tam = aux->getTamanio();

            for(int i = 0; i<tam;i++){
                articulo artic = aux->getDato(i);
                if(artic.getNom() == clave ) {
                    return artic;
                }
            }
            throw 404;
        }else{
            throw 404;
        }
    }
}

template <class K, class T>
void HashMap<K, T>::put(K clave, T valor)
{
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] != NULL)
    {
        if(tabla[pos]->esListaEnlazada()){
            tabla[pos]->getLista()->insertarUltimo(valor); //inserta el ultimo elemen, si lista ya existe
        }else{
            Lista<T> * nuevaLista = new Lista<T>(); //no existe lista, la crea.
            nuevaLista->insertarUltimo(tabla[pos]->getValor());
            nuevaLista->insertarUltimo(valor);
            tabla[pos]->setLista(nuevaLista);
        }
    }else{
        tabla[pos] = new HashEntry<K, T>(clave, valor);
    }

}

template <class K, class T>
void HashMap<K, T>::remove(K clave) {}

template <class K, class T>
bool HashMap<K, T>::esVacio()
{
    for (int i = 0; i < tamanio; i++)
    {
        if (tabla[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

template <class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave)
{
    return (unsigned int)clave;
}

template <class K, class T>
void HashMap<K, T>::print()
{

    std::cout << "i"
              << " "
              << "Clave"
              << "\t\t"
              << "Valor" << std::endl;
    std::cout << "--------------------" << std::endl;
    for (int i = 0; i < tamanio; i++)
    {
        std::cout << i << " ";
        if (tabla[i] != NULL)
        {
            std::cout << tabla[i]->getClave() << "\t\t";
            std::cout << tabla[i]->getValor();
        }
        std::cout << std::endl;
    }
}

#endif // U05_HASH_HASHMAP_HASHMAP_H_