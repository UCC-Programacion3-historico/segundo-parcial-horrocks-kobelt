#include "nodoArbol.h"

nodoArbol::nodoArbol(email m) {
    valores.insertar(m);
    izq = NULL;
    der = NULL;

}

void nodoArbol::putDate(email m) {

    if (m.getFrom() == valores.getDato(0).getFrom())

        valores.insertar(m);

    else if (m.getFrom() < valores.getDato(0).getFrom()) {

        if (izq == NULL) {
            izq = new nodoArbol(m);

        } else
            izq->putDate(m);

    } else {

        if (der == NULL) {
            der = new nodoArbol(m);

        } else
            der->putDate(m);
    }
}

void nodoArbol::putFrom(email m) {
    if (m.getDate() == valores.getDato(0).getDate())

        valores.insertar(m);

    else if (m.getDate() < valores.getDato(0).getDate()) {
        if (izq == NULL) {
            izq = new nodoArbol(m);

        } else
            izq->putFrom(m);

    } else {
        if (der == NULL) {
            der = new nodoArbol(m);

        } else
            der->putFrom(m);
    }
}

void nodoArbol::inorder(vector<email> &resultado) {

    if (izq != NULL) izq->inorder(resultado);

    for (unsigned i = 0; i < valores.getTamanio(); i++)
        resultado.push_back(valores.getDato(i));

    if (der != NULL) der->inorder(resultado);
}

void nodoArbol::search(vector<email> &resultado, string palabra) {

    if (valores.getDato(0).getFrom() == palabra) {

        for (int i = 0 ; i < valores.getTamanio() ; i++)
            resultado.push_back(valores.getDato(i));

    } else if (palabra < valores.getDato(0).getFrom()) {
        if (izq == NULL)
            throw 3;

        else
            izq->search(resultado, palabra);

    } else {
        if (der == NULL)
            throw 3;

        else
            der->search(resultado, palabra);
    }
}

