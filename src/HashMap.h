#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.h"

template<class K, class T>
class HashMap {
private:
    //Lista<HashEntry<K,T>*> *tablaL;

    HashEntry<K, T> **tabla;

    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

    HashEntry<K, T> *inicio;


public:
    HashMap(unsigned int tamanio);

    HashMap(unsigned int tamanio, unsigned int (*hashFuncP)(K clave));

    void get(K clave, vector<email> &resultado);

    void put(K clave, T valor);

    void remove(K clave, int id);

    ~HashMap();

    bool esVacio();

};

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int tamanio) {
    this->tamanio = tamanio;
    hashFuncP = hashFunc;
    tabla = new HashEntry<K, T> *[tamanio];
    inicio = NULL;
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
}

template<class K, class T>
HashMap<K, T>::~HashMap() {

    for (int i = 0; i < tamanio; i++) {
        HashEntry<K, T> *aux = tabla[i], *tmp;

        if (tabla[i] != NULL) {
            while (aux->getNext() != NULL) {
                tmp = aux;
                aux = aux->getNext();
                delete tmp;
            }
            delete tabla[i];
        }
    }
}

template<class K, class T>
void HashMap<K, T>::get(K clave, vector<email> &resultado) {
    bool bander = false;
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL)
        throw 2;

    else {
        HashEntry<K, T> *aux = tabla[pos];

        while (aux != NULL) {
            if (aux->getKey() == clave) {
                bander = true;
                resultado.push_back(aux->getDato());
            }
            aux = aux->getNext();
        }
        if (bander == false)
            throw 5;
    }
}

template<class K, class T>
void HashMap<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % tamanio;


    if (tabla[pos] != NULL) {
        //genero un dato aux con el cual voy a ir recorriendo los hashentrys en esa pos
        HashEntry<K, T> *aux = tabla[pos];

        while (aux->getNext() != NULL) {
            aux = aux->getNext();
        }
        //cuando encontro que el siguiente dato es nulo, seteo el dato entrante
        HashEntry<K, T> *nuevo = new HashEntry<K, T>(clave, valor, nullptr);
        aux->setNext(nuevo);

    } else //si no estaba utlizada la posicion, cargo un hashentry nuevo
        tabla[pos] = new HashEntry<K, T>(clave, valor, nullptr);
}

template<class K, class T>
void HashMap<K, T>::remove(K clave, int id) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] != NULL) {
        HashEntry<K, T> *aux = tabla[pos];

        //si la posicion no devuelve la key que quiero, busca las otras en la misma pos
        if (tabla[pos]->getKey() != clave) {

            while (aux != NULL && aux->getDato().getId() == id) {
                aux = aux->getNext();
            }

            //si no encontro, lanza error
            if (aux == NULL)
                throw 4;
            else {

                //si encontro, guarda en temporal la que quiere borrar y setea a anterior a la siguiente
                HashEntry<K, T> *tmp = aux->getNext();
                aux->setNext(aux->getNext()->getNext());
                delete tmp;
            }

        } else { //borra directamente
            delete tabla[pos];
            tabla[pos] = NULL;
        }
    } else
        cout << "no se encuentra dato para borrar" << endl;
}

template<class K, class T>
bool HashMap<K, T>::esVacio() {

    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL)
            return false;
    }
    return true;
}

template<class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave) {
    return (unsigned int) clave;
}

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int tamanio, unsigned int (*fp)(K)) {
    this->tamanio = tamanio;
    this->hashFuncP = fp;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
}


#endif //HASHMAP_H