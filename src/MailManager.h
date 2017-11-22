#include <string>
#include <vector>
//#include "email.h"
#include "Arbol.h"
//#include "Lista.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

using namespace std;


class MailManager {
private:

    Arbol *arbolFecha;
    Arbol *arbolFrom;
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
