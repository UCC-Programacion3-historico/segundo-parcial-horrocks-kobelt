#include <iostream>
#include "MailManager.h"
#include <vector>

using namespace std;

int main() {

    vector<email> ema, temporal;
    MailManager M;

    email p1("juan", "carlos", "2018-10-02", "hola", "hola todo bien?");
    email p2("pedro", "horacio", "2018-01-01", "que", "que se cuenta");
    email p3("esteban", "juan", "2017-08-20", "que haces", "que se cuenta");
    email p4("carlos", "josesito", "2017-03-05", "que haces", "morocho");
    email p5("miguel", "juan", "2017-05-12", "hola pibe cantina", "que se cuenta");
    email p6("pedro", "juan", "2016-11-04", "que haces", "que se morocho");


    int salida = 0;

    while (salida == 0) {

        int opcion;
        cout << "'El Chasqui Mails'" << endl;
        cout << "Seleccione lo que desee hacer: " << endl;
        cout << "1 = cargar mail" << endl;
        cout << "2 = borrar mail" << endl;
        cout << "3 = ordenar por fecha " << endl;
        cout << "4 = buscar rango de fechas " << endl;
        cout << "5 = buscar por destinatario " << endl;
        cout << "6 = buscar por palabra" << endl;
        cout << "7 = salir" << endl;

        cin >> opcion;

        switch (opcion) {
            case 1: {
                string palabra;
                email j;

                cout << "remitente:" << endl;
                cin >> palabra;
                j.setFrom(palabra);
                cout << "destinatario: " << endl;
                cin >> palabra;
                j.setTo(palabra);
                cout << " fecha: " << endl;
                cin >> palabra;
                j.setDate(palabra);
                cout << "asunto: " << endl;
                cin >> palabra;
                j.setSubject(palabra);
                cout << " contenido" << endl;
                cin >> palabra;
                j.setContent(palabra);

                M.addMail(j);
                temporal.push_back(j);

                break;
            }
            case 2: {
                cout << "ingrese id" << endl;
                int id, i = 0;
                cin >> id;

                while (temporal.size() > i && temporal[i].getId() == id) {
                    i++;
                }

                M.deleteMail(temporal[i]);
                break;
            }
            case 3: {
                ema = M.getSortedByDate();
                for (unsigned i = 0; i < ema.size(); i++) {
                    ema[i].print();
                }
                break;
            }

            case 4: {
                string desde, hasta;
                cout << "ingrese fechas " << endl;
                cin >> desde >> hasta;
                ema = M.getSortedByDate(desde, hasta);
                for (unsigned i = 0; i < ema.size(); i++) {
                    ema[i].print();
                }
                break;
            }
            case 5: {
                string dest;
                cout << "ingrese nombre" << endl;
                cin >> dest;
                ema = M.getByFrom(dest);
                for (int i = 0; i < ema.size(); i++) {
                    ema[i].print();
                }
                break;
            }
            case 6: {
                string pal;
                cout << "ingrese palabra" << endl;
                cin >> pal;
                ema = M.getByQuery(pal);
                for (int i = 0; i < ema.size(); i++) {
                    ema[i].print();
                }
                break;
            }
            case 7: {
                salida = 1;
                break;
            }
            default: {
                cout << "Numero invalido" << endl;
                break;
            }
        }
    }
}
