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
    const Lista<email> &getValores() const;

    void setValores(const Lista<email> &valores);

    nodoArbol *getIzq() const;

    void setIzq(nodoArbol *izq);

    nodoArbol *getDer() const;

    void setDer(nodoArbol *der);

    nodoArbol(email m);

    void putFrom(email m);

    void putDate(email m);

    void search (vector<email> &resultado, string palabra);

    void inorder(vector<email> &resultado);

    nodoArbol *removerFecha(email m);

    nodoArbol *removerFrom(email m);


};



#endif //MAILMANAGER_NODOARBOL_H
