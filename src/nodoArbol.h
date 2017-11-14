#ifndef MAILMANAGER_NODOARBOL_H
#define MAILMANAGER_NODOARBOL_H

#include <iostream>
#include "Lista.h"
#include "email.h"
#include <vector>

using namespace std;

template<class S, class E>
class nodoArbol {
private:

    nodoArbol *izq, *der;
    S dato;
    Lista<E> valores;
    vector<email>listaInorder;

public:

    nodoArbol(S dato, E mail);

    S getDato() const;

    void put(S d, E mail );

    void put(nodoArbol<S, E> *nodo);

    nodoArbol<S,E> *remover(S param, E mail);

    Lista<E> nodoArbol<S, E>::getMails();

    E search (S d);

    void borrarUno(unsigned int identif, S param, E mail);

    vector<email> inorder();
};

template<class S, class E>
nodoArbol<S, E>::nodoArbol(S dato, E mail) {
    valores.insertarPrimero(mail);
    izq = NULL;
    der = NULL;
}


template <class S, class E>
void nodoArbol::put(S d, E mail ) {

    if (d == dato){
        valores.insertarPrimero(mail);
        throw 1;// que pasa cuando son duplicados
    } else if (d < dato) { // va a la izq
        if (izq == NULL)
            izq = new nodoArbol<S, E>(d, mail);
        else
            izq->put(d, mail);
    } else { // va a la der
        if (der == NULL)
            der = new nodoArbol<S, E>(d, mail);
        else
            der->put(d, mail);
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
            izq->put(nodo);
    } else { // va a la der
        if (der == NULL)
            der = dato;
        else
            der->put(nodo);
    }
}

template<class S, class E>
nodoArbol<S,E> *nodoArbol<S, E>::remover(S param, E mail) {
    nodoArbol<S, E> *aux;
    if (param == dato) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    } else if (param < dato) {
        if (izq == NULL)
            throw 3;
        else {
            aux = izq;
            izq = izq->remover(param, mail);
            if (izq != aux) {
                valores.remover(mail.getid());
                delete aux;
            }

        }
    } else {
        if (der == NULL)
            throw 3;
        else {
            aux = der;
            der = der->remover(param, mail);
            if (der != aux){
                valores.remover(mail.getid());
                delete aux;
            }

        }
    }
    return this;
}

template<class S, class E>
S  nodoArbol<S, E>::getDato() const {
    return dato;
}

template<class S, class E>
Lista<E> nodoArbol<S, E>::getMails() {
    return valores;
}

template <class S, class E>
E nodoArbol<S, E>::search(S d) {
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
/*
template <class S, class E>
void nodoArbol::borrarUno(unsigned int identif, S param, E mail) {
    if (param == dato) {
        valores.remover(identif);
        return dato;
    } else if (param < dato) {
        if (param == NULL)
            throw 3;
        else
            return izq->search(param);
    } else {
        if (der == NULL)
            throw 3;
        else
            return der->search(param);
    }
}
 */
 // No se si es necesario (carita pensativa)

template <class S, class E>
vector<email> nodoArbol::inorder() {
    if (izq != NULL) izq->inorder();
    listaInorder = dato;
    if (der != NULL) der->inorder();
    return listaInorder;
}

#endif //MAILMANAGER_NODOARBOL_H
