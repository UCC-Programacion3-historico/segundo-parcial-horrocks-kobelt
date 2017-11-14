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

    void remove(S clave, E valor);

    E buscar (S clave);

    vector<email> inorder();

    vector<email> getMails(S d);

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

template <class S, class E>
E Arbol::buscar(S clave) {

    if (raiz == NULL)
        throw  1;
    else {
        raiz->search(clave);
    }
}

vector<email> Arbol::inorder(){
    if (raiz != NULL){
        raiz->inorder();
    }else
        throw 404;

}
template <class S>
vector<email> Arbol::getMails(S d){
    vector <email> mails;
    if(raiz != NULL){
        mails = raiz.getmails();
    }
}



#endif //MAILMANAGER_ARBOL_H
