#include "email.h"



//constructor
email::email(string de, string para, string fecha, string asunto, string contenido) {
    from = de;
    to = para;
    date = fecha;
    subject = asunto;
    content = contenido;
}
//constructor por copia
email::email(email *&pEmail) {
    this->date = pEmail->date;
    this->from = pEmail->from;
    this->to = pEmail->to;
    this->subject = pEmail->subject;
    this->content = pEmail->content;
}

void email::print() {
    cout<<"ID: "<<id<<endl;
    cout<<"From: "<<from<<endl;
    cout<<"To: "<<to<<endl;
    cout<<"Date: "<<date<<endl;
    cout<<"Subject: "<<subject<<endl;
    cout<<"Content: "<<content<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
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





