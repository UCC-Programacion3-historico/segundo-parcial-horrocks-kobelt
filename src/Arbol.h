#ifndef MAILMANAGER_ARBOL_H
#define MAILMANAGER_ARBOL_H

#include <iostream>
#include "nodoArbol.h"


template<class S, class E>
class Arbol {
private:
    nodoArbol<S, E> *raiz;
    string fecha, de;

public:
    Arbol();

    ~Arbol();

    void put(S clave, E valor);

    void remove(S clave, E valor);

    bool esVacio();

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

template <class S, class E>
void Arbol<S, E>::remove(S clave, E valor) {
        if (raiz == NULL)
            throw 1;
        else
            raiz->remover(clave, valor);
}


#endif //MAILMANAGER_ARBOL_H
