#include <cstring>
#include "MailManager.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "TemplateArgumentsIssues"



MailManager::MailManager() {

    arbolFecha = new Arbol();
    arbolFrom = new Arbol();
    tabla = new HashMap<string, email>(4330, hashFunc);
    contador = 0;
}


void MailManager::addMail(email m) {

    m.setId(contador++);
    arbolFecha->putD(m);
    arbolFrom->putF(m);

    //cargo por contenido
    string word = m.content;
    istringstream iss(word);
    do
    {
        string subs;
        iss >> subs;
        tabla->put(subs,m);
    } while (iss);

    //cargo por asunto
    word = m.subject;
    istringstream iss(word);
    do{
        string subs;
        iss >> subs;
        tabla->put(subs, m);

    }while(iss);


}


void MailManager::deleteMail(email m) {

    arbolFrom->removeDe(m);
    arbolFecha->removeFec(m);

    cout<<"El mail de " << m.getFrom() << " fue eliminado correctamente." << endl;


}


vector<email> MailManager::getSortedByDate() {

    vector<email> ret;
    arbolFecha->inorder(ret);
    return ret;
}


/**
 * Devuelve una lista de mails oredenados por fecha que estan en el rango
 * desde - hasta
 * @param desde Fecha desde donde buscar
 * @param hasta Fecha hasta donde buscar
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate(string desde, string hasta) {

    vector<email> ret, temporal;
    arbolFecha->inorder(temporal);

    for (unsigned int i = 0; i < temporal.size(); i++) {

        if (temporal[i].date >= desde && temporal[i].date <= hasta) {
            ret.push_back(temporal[i]);
        }
    }
    return ret;
}



/**
 * Devuelve una lista de mails ordenados por Remitente
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByFrom() {

    vector<email> ret;
    arbolFrom->inorder(ret);
    return ret;
}


/**
 * Devuelve una lista de mails de un determinado remitente
 * @param from String con direccion del remitente
 * @return lista de mails del remitente
 */
vector<email> MailManager::getByFrom(string from) {

    vector<email> ret;
    arbolFrom->buscar(ret, from);
    return ret;
}


/**
 * Devuelve una lista de mails que contengan las palabras de 'query'
 * en su asunto o en su contenido
 * @param query String con palabra/s a buscar
 * @return lista de mails que contienen dicha/s palabra/s
 */
vector<email> MailManager::getByQuery(string query) {

    vector<email> ret;
    ret.push_back(tabla.get(query));
    return ret;
}

unsigned int MailManager::hashFunc(string clave) {
    unsigned int sum=0;
    for (int i=0; i<clave.size(); i++){
        sum += clave[i] * clave[i];
    }
    return sum;
}

#pragma clang diagnostic pop