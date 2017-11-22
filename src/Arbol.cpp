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
        throw "El arbol esta vacio";

}

void Arbol::buscar(vector<email> &resultado, string palabra) {
    if (raiz == NULL)
        throw 1;
    else {
        raiz->search(resultado, palabra);
    }
}