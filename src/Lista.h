#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */

template<class T>
class Lista {
private:
    nodo<T> *inicio;

public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();
    nodo<T> *getInicio(){return inicio;}
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = NULL;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {
    nodo<T> *aux = inicio;
    nodo<T> *ant = inicio;

    while (aux != NULL) {
        ant = aux;
        aux = aux->getNext();
        delete ant;

    }
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T>
bool Lista<T>::esVacia() {
    return inicio == NULL;
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    nodo<T> *aux = inicio;
    int count=0;
    while(aux!=NULL){
        count++;
        aux = aux->getNext();
    }
    return count;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    int cont = 0;
    nodo<T> *aux=inicio;

    if (pos==0){
        nodo<T> *nn = new nodo<T>(dato, inicio);
        inicio = nn;
        return;
    }

    while(cont < pos-1 && aux != NULL){
        cont++;
        aux = aux->getNext();
    }
    if (aux == NULL )
        throw 1;

    nodo<T> *nn = new nodo<T>(dato, aux ->getNext());
    aux->setNext(nn);
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    nodo <T> *nm = new nodo<T>(dato, inicio);

}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    nodo<T> *aux=inicio;
    int count=0;
    while (aux!=NULL){
        count++;
        aux = aux->getNext();
    }
    Lista<T>::insertar(count, dato);

}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    nodo<T> *aux = inicio;
    int count=0;

    if (pos == 0){
        if (inicio==NULL)
            throw 1;

        inicio = inicio->getNext();
        delete aux;
        return;
    }

    while (count < pos-1 && aux->getNext() != NULL){
        count++;
        aux=aux -> getNext();
    }
    if (aux->getNext() == NULL )
        throw 1;

    nodo<T> *tmp = aux->getNext();
    aux->setNext(aux->getNext()->getNext());
    delete tmp;
}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    unsigned i=0;
    nodo<T> *aux = inicio;

    while (i < pos && aux != NULL){
        aux = aux->getNext();
        i++;
    }
    if(aux == NULL)
        throw 3;

    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    unsigned i=0;
    nodo<T> *aux = inicio;

    while (i < pos && aux != NULL){
        aux = aux->getNext();
        i++;
    }
    if(aux == NULL)
        throw 3;

    aux->setDato(dato);
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {}


#endif //LISTA_H