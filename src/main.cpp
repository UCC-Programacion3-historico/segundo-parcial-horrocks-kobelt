#include <iostream>
#include "MailManager.h"
#include <vector>

using namespace std;

int main() {

    vector<email> ema;
    MailManager M;

    email p1 ("juan@", "carlos@", "2018-10-2", "hola", "hola todo bien?");
    email p2("pedro", "horacio", "2017-10-1", "que haces", "que se cuenta");
    email p3("esteban", "juan", "2017-08-20", "que haces", "que se cuenta");


    M.addMail(p1);
    M.addMail(p2);
    M.addMail(p3);


    ema = M.getSortedByDate();
    for (unsigned i=0; i<ema.size(); i++){
        ema[i].print();
    }

    cout<<"----1---"<<endl;

    ema = M.getSortedByFrom();
    for(unsigned i=0; i<ema.size(); i++){
        ema[i].print();
            }

    cout<<"----2---"<<endl;

    M.deleteMail(p1);

    cout<<"----3---"<<endl;

    ema = M.getSortedByDate("2017-09-1", "2017-11-1");
    for (unsigned i=0; i<ema.size(); i++){
        ema[i].print();
            }

    cout<<"----4---"<<endl;

    ema = M.getByFrom("pedro");
    ema[0].print();

    cout<<"----5---"<<endl;




    }
