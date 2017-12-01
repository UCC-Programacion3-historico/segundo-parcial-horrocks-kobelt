#ifndef INC_02_LISTAS_NODO_H
#define INC_02_LISTAS_NODO_H

#include <iostream>

template <class K, class T>
class nodo{
private:
    K clave;
    T dato;
    nodo *next;

public:
    K getClave() const {
        return clave;
    }

    void setClave(K clave) {
        nodo::clave = clave;
    }

    void setNext(nodo *next) {
        nodo::next = next;
    }
    void setDato(T dato) {
        nodo::dato = dato;
    }
    T getDato() const {
        return dato;
    }
    nodo *getNext() const {
        return next;
    }
    nodo(){
        next=NULL;
    }
    nodo (T d, K c, nodo* n){
        clave = c;
        dato = d;
        next = n;
    }
};



#endif //INC_02_LISTAS_NODO_H