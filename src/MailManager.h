#include <string>
#include <vector>
#include "email.h"
#include "Arbol.h"
#include "Lista.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

using namespace std;

template <class S, class E>
class MailManager {
private:

    Arbol<string, email*> arbolFecha;
    Arbol<string, email*> arbolFrom;
    Arbol<string, email*> arbolPalabra;
    unsigned int contador;

public:

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
