#include <iostream>
#include "MailManager.h"

int main() {
    int eleccion;

    cout << "Bienvenido al super gestor de mails" << endl;
    cout << "Horrocks-Kobelt Corp." << endl;
    cout << "Seleccione dentro del siguiente menu que desea hacer: " << endl;
    cout << " 1 = cargar mail " << endl;
    cout << " 2 = borrar mail" << endl;
    cout << " 3 = obtener todos los mails por fecha" << endl;
    cout << " 4 = obtener todos los mails entre dos fechas" << endl;
    cout << " 5 = obtener todos los mails por destinatario" << endl;
    cout << " 6 = buscar mail por destinatario" << endl;
    cout << " 7 = buscar mail por palabra" << endl;

    cin >> eleccion;

    MailManager M;

    email p;

    switch (eleccion) {
        case 1:
            M.addMail(p);
            break;

        case 2:
            M.deleteMail(p);
            break;

        case 3:
            M.getSortedByDate();
            break;

        case 4: {
            string desde, hasta;
            cout << "Ingrese fechas: " << endl;
            cin >> desde >> hasta;
            M.getSortedByDate(desde, hasta);
            break;
        }
        case 5:
            M.getSortedByFrom();
            break;

        case 6: {
            string destinatario;
            cout << "ingrese destinatario" << endl;
            cin >> destinatario;
            M.getByFrom(destinatario);
            break;
        }
        case 7: {
            string palabra;
            cout << "ingrese palabra" << endl;
            cin >> palabra;
            M.getByQuery(palabra);
            break;
        }
        default:
            cout << "numero incorrecto " << endl;
    }
}