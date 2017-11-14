#include "MailManager.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "TemplateArgumentsIssues"


/**
 * Constructor
 */
MailManager::MailManager() {
    contador = 0;
}


/**
 * Agrega un mail al gestor
 * @param m mail a agregar
 */

void MailManager::addMail(email m) {

    m.setId(contador++);
    arbolFecha.put(m.getDate(), &m);
    arbolFrom.put(m.getFrom(), &m);



}


/**
 * Elimina un mail del gestor
 * @param id identificador del mail a borrar
 */
void MailManager::deleteMail(email m) {

        arbolFrom.remove(m.getFrom(), &m);
        arbolFecha.remove(m.getDate(), &m);


}


/**
 * Devuelve una lista de mails ordenados por fecha
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate() {

    vector<email> ret;
    ret = arbolFecha.inorder();
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

    vector<email> ret;
    return ret;
}


/**
 * Devuelve una lista de mails ordenados por Remitente
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByFrom() {

    vector<email> ret;
    ret = arbolFrom.inorder();
    return ret;
}


/**
 * Devuelve una lista de mails de un determinado remitente
 * @param from String con direccion del remitente
 * @return lista de mails del remitente
 */
vector<email> MailManager::getByFrom(string from) {

    vector<email> ret;
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