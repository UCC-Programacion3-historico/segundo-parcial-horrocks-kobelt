#include "email.h"

//funcion cargar mail en el nodo
void putMail (string fecha, string de, string para, string asunto, string texto){
    if (fecha == date)
        throw 1;
    else if (fecha < date) { // va a la izq
        if (left == NULL)
            left = new email<string> (fecha, de, para, asunto, texto);
        else
            left->putMail(fecha, de, para, asunto, texto);
    } else { // va a la der
        if (right == NULL)
            right = new email<string> (fecha, de, para, asunto, texto);
        else
            right->putMail(fecha, de, para, asunto, texto);
    }
}

unsigned long email::getId() const {
    return id;
}

void email::setId(unsigned long id) {
    email::id = id;
}

const string &email::getFrom() const {
    return from;
}

void email::setFrom(const string &from) {
    email::from = from;
}

const string &email::getTo() const {
    return to;
}

void email::setTo(const string &to) {
    email::to = to;
}

const string &email::getDate() const {
    return date;
}

void email::setDate(const string &date) {
    email::date = date;
}

const string &email::getSubject() const {
    return subject;
}

void email::setSubject(const string &subject) {
    email::subject = subject;
}

const string &email::getContent() const {
    return content;
}

void email::setContent(const string &content) {
    email::content = content;
}

email *email::getLeft() const {
    return left;
}

void email::setLeft(email *left) {
    email::left = left;
}

email *email::getRight() const {
    return right;
}

void email::setRight(email *right) {
    email::right = right;
}
