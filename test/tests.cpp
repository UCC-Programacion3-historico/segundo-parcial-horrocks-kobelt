#include "gtest/gtest.h"
#include <fstream>
#include <vector>
#include "../src/email.h"
#include "../src/MailManager.h"


vector<email> load_mm(string archivo);

vector<string> split(const string &s, char delim) {
    vector<std::string> elems;
    unsigned long pos = s.find(delim);
    if (pos == string::npos)
        elems.push_back(s);
    else {
        elems.push_back(s.substr(0, pos));
        elems.push_back(s.substr(pos + 1, string::npos));
    }
    return elems;
}
void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector) {
    TempBuff.resize(0);
    TotalVector = 0;
    int Nums = -1;
    int NumPos = -1;
    int ValorNum = 0;
    int TotalChars = 0;
    int TotalEspacios = Linea.length();
    string Valor;
    Cuenta(Linea, Separador, TotalChars);
    if (TotalChars != 0) {
        while (Nums < TotalChars) {
            Nums++;
            ValorNum = Linea.find(Separador, NumPos + 1);
            Valor = Linea.substr(NumPos + 1,ValorNum);
            Valor = Valor.substr(0, Valor.find_first_of(Separador));
            TempBuff.push_back(Valor);
            NumPos = ValorNum;
            TotalEspacios++;
        }
        TotalVector = TempBuff.size();
    }
    else {
        //TempBuff.push_back(Linea.substr(0, Linea.find_first_of(Separador)));
        TotalVector = 0;
    }
}

TEST(add_test, andaSplit) {
    vector<string> elems = split("HOLA:Mundo:chau", ':');
    EXPECT_EQ(elems[0], "HOLA");
    EXPECT_EQ(elems[1], "Mundo:chau");
}

TEST(add_test, carga2Mails) {
    vector<email> mails = load_mm("../../test/mails-2.txt");
    EXPECT_EQ(mails.size(), 2);
    EXPECT_EQ(mails[0].getFrom(), "juan@gmail.com");
    EXPECT_EQ(mails[1].getFrom(), "juanjose@gmail.com");
}

TEST(add_test, carga20Mails) {
    vector<email> mails = load_mm("../../test/mails-20.txt");
    EXPECT_EQ(mails.size(), 20);
    EXPECT_EQ(mails[0].getFrom(), "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[19].getFrom(), "javier---@gmail.com");
}

TEST(add_test, carga100Mails) {
    vector<email> mails = load_mm("../../test/mails-100.txt");
    EXPECT_EQ(mails.size(), 100);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[99].from, "t---@grulic.psi.unc.edu.ar");
}

TEST(add_test, carga1000Mails) {
    vector<email> mails = load_mm("../../test/mails-1000.txt");
    EXPECT_EQ(mails.size(), 1000);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[999].from, "girald---@gmail.com");
}

TEST(add_test, carga3001Mails) {
    vector<email> mails = load_mm("../../test/mails-3001.txt");
    EXPECT_EQ(mails.size(), 3001);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[3000].from, "sebas---@gmail.com");
}

TEST(add_test, testMM) {
    MailManager mm;
    vector<email> mails = load_mm("../../test/mails-3001.txt");
    for (auto const &m: mails) {
        mm.addMail(m);
    }
    /* std::cout << value; ... */
    EXPECT_EQ(mails.size(), 3001);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[3000].from, "sebas---@gmail.com");
}

string trim(string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<email> load_mm(string archivo) {
    string line;
    vector<email> mails;
    ifstream miArchivo(archivo);
    unsigned long indice = 0;
    vector<string> campos;
    email *mail = NULL;

    if (miArchivo.is_open()) {
        try {
            while (getline(miArchivo, line)) {
                campos = split(line, ':');
                if (campos.size() > 0) { // Es un dato completo
                    if (campos[0] == "-.-.-") {
                        if (mail != NULL)
                            mails.push_back(*mail);
                        mail = new email();
                        mail->getContent() = "";
                    } else if (campos[0] == "date") {
                        mail->getDate() = trim(campos[1]);
                    } else if (campos[0] == "from") {
                        mail->getFrom() = trim(campos[1]);
                    } else if (campos[0] == "to") {
                        mail->getTo() = trim(campos[1]);
                    } else if (campos[0] == "subject") {
                        mail->getSubject() = trim(campos[1]);
                    } else {
                        mail->getContent() += line + "\n";
                    }
                }
            }
        } catch (int e) {
            cout << "error cargando mail\n";
        }
    } else
        cout << "No se pudo leer el archivo.";
    return mails;
}
