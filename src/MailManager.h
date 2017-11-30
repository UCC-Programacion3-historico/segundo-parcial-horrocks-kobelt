#include <string>
#include <vector>
#include <sstream>
#include "email.h"
#include "Arbol.h"
#include "Lista.h"
#include "HashMap.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

using namespace std;


class MailManager {
private:

    Arbol *arbolFecha;
    Arbol *arbolFrom;
    HashMap<string, email> *tabla;
    unsigned int contador;

public:

    static unsigned int hashFunc(string clave);


    MailManager();

    void addMail(email m);

    void deleteMail(email m);

    vector<email> getSortedByDate();

    vector<email> getSortedByDate(string desde, string hasta);

    vector<email> getSortedByFrom();

    vector<email> getByFrom(string from);

    vector<email> getByQuery(string query);

};


#endif // MAILMANAGER_H
