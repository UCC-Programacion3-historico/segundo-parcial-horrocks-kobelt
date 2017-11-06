#ifndef MAILMANAGER_ARBOL_H
#define MAILMANAGER_ARBOL_H

#include <iostream>
#include "nodoArbol.h"


template<class S, class E>
class Arbol {
private:
    Arbol<S, E> *raiz, fecha;
public:
    Arbol();

    ~Arbol();

    void put(S dato, E *mail);

    void ArbolPorFrom();

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
void Arbol<S, E>::put(S dato, E *mail) {
    if (raiz == NULL) {
        raiz = new nodoArbol<S, E>(dato, *mail);
    } else {
        raiz->put(dato, *mail);
    }
}

/**
 * formar el arbol en base a los remitentes de los mails
 */

template <class S, class E>
void Arbol<S, E>::ArbolPorFrom() {


}

/**
 * formar el arbol en base a la fecha de los mails
 */

template <class S, class E>
void Arbol<S, E>::ArbolPorDate(string date) { //No se como chota hacerlo
    if (date == fecha)
        throw 1;
    else if (date < fecha) { // va a la izq
}



#endif //MAILMANAGER_ARBOL_H
