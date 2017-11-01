#include "email.h"
#include <string.h>


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

email::email(string de; string para; string fecha; string asunto; string contenido){
    from = de;
    to = para;
    date = fecha;
    subject = asunto;
    content = contenido;

}
