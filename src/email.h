#include <string>

#ifndef EMAIL_H
#define EMAIL_H

using namespace std;

/**
 * Clase con los datos del mail
 */
class email {
private:
    unsigned long id;
    string from;
    string to;
    string date;
    string subject;
    string content;

public:
    unsigned long getId() const;

    void setId(unsigned long id);

    const string &getFrom() const;

    void setFrom(const string &from);

    const string &getTo() const;

    void setTo(const string &to);

    const string &getDate() const;

    void setDate(const string &date);

    const string &getSubject() const;

    void setSubject(const string &subject);

    const string &getContent() const;

    void setContent(const string &content);

};


#endif // EMAIL_H
