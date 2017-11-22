#include <cstring>
#include "MailManager.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "TemplateArgumentsIssues"


MailManager::MailManager() {
    contador = 0;
}


void MailManager::addMail(email m) {

    m.setId(contador++);
    arbolFecha->putD(m);
    arbolFrom->putF(m);

//
//    string word;
//    char limite = ' ';
//    word = m.getSubject();
//    char *temp = strtok((char *) word.c_str(), &limite);
//    while (temp != NULL) {
//        arbolPalabra.put(temp, &m);
//        temp = strtok(NULL, &limite);
//    }


}


void MailManager::deleteMail(email m) {


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
    return ret;
}

#pragma clang diagnostic pop