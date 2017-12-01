#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.h"

template<class K, class T>
class HashMap {
private:
    Lista<HashEntry<K,T>*> *tablaL;

    HashEntry<K, T> **tabla;

    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

    Lista<email> lisHash;


public:
    HashMap(unsigned int tamanio);

    HashMap(unsigned int tamanio, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

};

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int tamanio) {
    this->tamanio = tamanio;
    hashFuncP = hashFunc;
    tablaL =new Lista<T> [tamanio];
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
}

template<class K, class T>
HashMap<K, T>::~HashMap() {

    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL)
            delete tabla[i];
    }
}

template<class K, class T>
T HashMap<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tablaL[pos].getDato(0) == NULL)
        throw 2;
    return tablaL[pos].getDato(0)->getDato();
}

template<class K, class T>
void HashMap<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    tablaL[pos].insertar(new HashEntry<K,T>(clave,valor));
    if (tabla[pos] != NULL)
        lisHash.insertar(valor);

    tabla[pos] = new HashEntry<K, T>(clave, valor);
}

template<class K, class T>
void HashMap<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tablaL[pos].getDato(pos) != NULL) {
        delete tablaL[pos];
        tablaL[pos] = NULL;
    }
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
    tablaL = new Lista<HashEntry<K, T>*> [tamanio];
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
}


#endif //HASHMAP_H