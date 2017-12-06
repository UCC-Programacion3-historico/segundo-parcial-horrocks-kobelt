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
    HashEntry(K key, T dato, HashEntry *next) : key(key), dato(dato), next(next) {}


    HashEntry *getNext() const {
        return next;
    }

    void setNext(HashEntry *next) {
        HashEntry::next = next;
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