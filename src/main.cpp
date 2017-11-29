#include <iostream>
#include "MailManager.h"
#include <vector>

using namespace std;

int main() {

    vector<email> ema;
    MailManager M;

    email p1 ("juan", "carlos", "2018-10-02", "hola", "hola todo bien?");
    email p2("pedro", "horacio", "2018-01-01", "que haces", "que se cuenta");
    email p3("esteban", "juan", "2017-08-20", "que haces", "que se cuenta");
    email p4("carlos", "juan", "2017-03-05", "que haces", "que se cuenta");
    email p5("miguel", "juan", "2017-05-12", "que haces", "que se cuenta");
    email p6("pedro", "juan", "2016-11-04", "que haces", "que se cuenta");


    M.addMail(p1);
    M.addMail(p2);
    M.addMail(p3);
    M.addMail(p4);
    M.addMail(p5);
    M.addMail(p6);

    cout<<"----0---"<<endl;


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

    ema = M.getSortedByDate("2017-01-1", "2017-11-1");
    for (unsigned i=0; i<ema.size(); i++){
        ema[i].print();
            }

    cout<<"----4---"<<endl;

    ema = M.getByFrom("pedro");
    for(int i=0; i<ema.size(); i++) {
        ema[i].print();
    }
    cout<<"----5---"<<endl;




    }
