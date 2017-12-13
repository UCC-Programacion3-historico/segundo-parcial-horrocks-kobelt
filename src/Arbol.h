#ifndef MAILMANAGER_ARBOL_H
#define MAILMANAGER_ARBOL_H

#include <iostream>
#include "nodoArbol.h"


class Arbol {
private:
    nodoArbol *raiz;

public:
    Arbol();

    ~Arbol();

    void putF(email &m);

    void putD(email &m);

    void removeFec(email &m);

    void removeDe(email &m);

    void buscar (vector<email> &resultado, string palabra);

    void inorder(vector<email> &resultado);




};


#endif //MAILMANAGER_ARBOL_H
