#ifndef MAILMANAGER_NODOARBOL_H
#define MAILMANAGER_NODOARBOL_H

#include <iostream>
using namespace std;

template<class S, class E>
class nodoArbol {
private:

    nodoArbol *izq, *der;
    S dato;
    LinkedList<E> valores;

public:

    nodoArbol(S dato, E mail);

    S getDato() const;

    void setDato(S dato, E mail);

    void put(S d, E mail);

    void put(nodoArbol nodo);

    S search(S d);

    nodoArbol *remover(S param, E mail);

    void preorder();

    void inorder();

    void postorder();
};

template<class S, class E>
nodoArbol<S, E>::nodoArbol(S dato, E *mail) : dato(dato) {
    izq = NULL;
    der = NULL;
}


template<class S, class E>
void nodoArbol<S, E>::put(S d, E e) {

    if (d == dato){
        valores.addPrimero(e);
        throw 1;// que pasa cuando son duplicados
    } else if (d < dato) { // va a la izq
        if (izq == NULL)
            izq = new nodoArbol<S, E>(d, e);
        else
            izq->put(d, e);
    } else { // va a la der
        if (der == NULL)
            der = new nodoArbol<S, E>(d, e);
        else
            der->put(d, e);
    }
}

template<class S, class E>
void nodoArbol<S, E>::put(nodoArbol<S, E> *nodo) {

    if (nodo->getDato() == dato)
        throw 1;
    else if (nodo->getDato() < dato) { // va a la izq
        if (izq == NULL)
            izq = dato;
        else
            izq->put(dato, *mail);
    } else { // va a la der
        if (der == NULL)
            der = dato;
        else
            der->put(dato, *mail);
    }
}

template<class T>
T NodoArbol<T>::search(T d) {
    if (d == dato) {
        return dato;
    } else if (d < dato) {
        if (izq == NULL)
            throw 3;
        else
            return izq->search(d);
    } else {
        if (der == NULL)
            throw 3;
        else
            return der->search(d);
    }
}

template<class S, class E>
nodoArbol<S, E>::*remover(S param, E *mail) {
    nodoArbol<S, E> *aux;
    if (param == dato) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    } else if (d < dato) {
        if (izq == NULL)
            throw 3;
        else {
            aux = izq;
            izq = izq->remover(d);
            if (izq != aux)
                delete aux;
        }
    } else {
        if (der == NULL)
            throw 3;
        else {
            aux = der;
            der = der->remover(d);
            if (der != aux)
                delete aux;
        }
    }
    return this;
}

template<class S, class E>
S nodoArbol<S, E>::getDato() const {
    return dato;
}

template<class S, class E>
void nodoArbol<S, E>::setDato(S dato, E *mail) {
    nodoArbol::dato = dato;
    nodoArbol::mail = mail;
}


#endif //MAILMANAGER_NODOARBOL_H
