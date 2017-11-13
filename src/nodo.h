#ifndef INC_02_LISTAS_NODO_H
#define INC_02_LISTAS_NODO_H

#include <iostream>

template <class T>
class nodo{
private:
    T dato;
    nodo *next;
public:
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
    nodo (T d, nodo* n){
        dato = d;
        next = n;
    }
};



#endif //INC_02_LISTAS_NODO_H
