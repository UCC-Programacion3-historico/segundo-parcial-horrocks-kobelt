#ifndef MAILMANAGER_ARBOL_H
#define MAILMANAGER_ARBOL_H

#include <iostream>
#include "nodoArbol.h"


template<class S, class E>
class Arbol {
private:
    nodoArbol<S, E> *raiz;
public:
    Arbol();

    ~Arbol();

    void put(S clave, E valor);

    void ArbolPorFrom(string from);

    void ArbolPorDate(string date);

    // void remove(T dato);

    // bool esVacio();

    // void print();

};


/**
 * Constructor del Arbol
 * @tparam S Clave por la cual va a ordenar el árbol
 * @tparam E Valor guardado por el árbol
 */

template<class S, class E>
Arbol<S, E>::Arbol() {
    raiz = NULL;
}


/**
 * Destructor del Arbol
 */

template<class S, class E>
Arbol<S, E>::~Arbol() {


}

template<class S, class E>
void Arbol<S, E>::put(S clave, E valor) {
    if (raiz == NULL) {
        raiz = new nodoArbol<S, E>(clave, valor);
    } else {
        raiz->put(clave, valor);
    }
}

/**
 * formar el arbol en base a los remitentes de los mails
 */

template <class S, class E>
void Arbol<S, E>::ArbolPorFrom(string from) {


}

/**
 * formar el arbol en base a la fecha de los mails
 */

template <class S, class E>
void Arbol<S, E>::ArbolPorDate(string date) {
    if (date == *raiz)
        throw 1;
    else if (date < *raiz) { // va a la izq
    }
}


#endif //MAILMANAGER_ARBOL_H
