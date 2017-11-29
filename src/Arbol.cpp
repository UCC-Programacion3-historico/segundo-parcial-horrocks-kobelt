#include "Arbol.h"


Arbol::Arbol() {
    raiz = NULL;
}

Arbol::~Arbol() {

}

void Arbol::putF(email m){
    if (raiz == NULL) {
        raiz = new nodoArbol(m);
    } else {
        raiz->putFrom(m);
    }
}

void Arbol::putD(email m) {
    if (raiz == NULL) {
        raiz = new nodoArbol(m);
    } else {
        raiz->putDate(m);
    }
}

void Arbol::inorder(vector<email> &resultado){
    if (raiz != NULL){
        raiz->inorder(resultado);
    }else
        throw 3;

}

void Arbol::buscar(vector<email> &resultado, string palabra) {
    if (raiz == NULL)
        throw 1;
    else {
        raiz->search(resultado, palabra);
    }
}

void Arbol::removeDe(email m) {
    if (raiz == NULL)
        throw 3;
    else {
        raiz->removerFrom(m);
    }
}

void Arbol::removeFec(email m) {
    if (raiz == NULL)
        throw 4;
    else {
        raiz->removerFecha(m);
        }


}