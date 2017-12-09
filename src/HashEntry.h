#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
#include "Lista.h"

template<class K,class T>
class HashEntry {
private:
    K key;
    T dato;
    HashEntry *next;

public:
    HashEntry(K k, T d, HashEntry* n){
        key = k;
        dato = d;
        next = n;
    }

    HashEntry(){
        next = NULL;
    }

    HashEntry *getNext() const {
        return next;
    }

    void setNext(HashEntry *Next) {
        this->next = Next;
    }

    HashEntry(K key, T dato) : key(key), dato(dato) {}

    K getKey()  {
        return key;
    }

    void setKey(K key) {
        HashEntry::key = key;
    }

    T getDato()  {
        return dato;
    }

    void setDato(T dato) {
        HashEntry::dato = dato;
    }

public:

};

#endif //HASHENTRY_H