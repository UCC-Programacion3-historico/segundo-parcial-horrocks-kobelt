#ifndef MAILMANAGER_NODOARBOL_H
#define MAILMANAGER_NODOARBOL_H

#include <iostream>
#include "Lista.h"
#include "email.h"
#include <vector>

using namespace std;


class nodoArbol {
private:

    nodoArbol *izq, *der;
    Lista<email> valores;

public:

    nodoArbol(email m);

    void putFrom(email m);

    void putDate(email m);

    void search (vector<email> &resultado, string palabra);

    void inorder(vector<email> &resultado);

    nodoArbol *removerFecha(email m);

    nodoArbol *removerFrom(email m);


};



#endif //MAILMANAGER_NODOARBOL_H
