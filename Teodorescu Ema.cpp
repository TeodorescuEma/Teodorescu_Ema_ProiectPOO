#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//Teodorescu Ema- Domeniul ales este TElecomunicatii

class Angajat {
public:
    const int codAngajat;
    static int nrMaximOre;
    char* nume;
    int varsta;
    float salariu;

    int getNrMaximOre() {
        return this->nrMaximOre;
    }

    Angajat() : codAngajat(5643) {
        this->nume = new char[strlen("Matei Grigore") + 1];
        strcpy_s(this->nume, strlen("Matei Grigore") + 1, "Matei Grigore");
        this->varsta = 45;
        this->salariu = 5800;
    }



    Angajat(const char* nume, int varsta, float salariu) : codAngajat(3245) {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
        this->varsta = varsta;
        this->salariu = salariu;
    }

    Angajat(int codAngajat, const char* nume, int varsta, float salariu) : codAngajat(codAngajat) {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
        this->varsta = varsta;
        this->salariu = salariu;
    }


    void afisareObj() {
        cout << "Cod Angajat: " << codAngajat << ", Nume: " << nume << ", Varsta: " << varsta << ", Salariu: " << salariu << endl;
    }


};

int Angajat::nrMaximOre = 40;


class Antena {
public:
    const int serieAntena;
    static int nrAntena;
    char* numeAntena;
    string material;
    int nrSenzori;
    float* frecventaRadioPerSenzor;

    int getNrAntena() {
        return this->nrAntena;
    }

    Antena() : serieAntena(432) {
        this->numeAntena = new char[strlen("Antena Satelit") + 1];
        strcpy(this->numeAntena, "Antena Satelit");
        this->material = "Cupru";
        this->nrSenzori = 2;
        this->frecventaRadioPerSenzor = NULL;
        nrAntena++;
    }


    Antena(const char* numeAntena, string material) : serieAntena(212) {
        this->numeAntena = new char[strlen(numeAntena) + 1];
        strcpy(this->numeAntena, numeAntena);
        this->material = material;
        this->nrSenzori = 1;
        this->frecventaRadioPerSenzor = NULL;
        nrAntena++;

    }


    Antena(int serieAntena, const char* numeAntena, string material, int nrSenzori, float* frecventaRadioPerSenzor) : serieAntena(serieAntena) {
        this->numeAntena = new char[strlen(numeAntena) + 1];
        strcpy(this->numeAntena, numeAntena);
        this->material = material;
        this->nrSenzori = nrSenzori;
        if (nrSenzori > 0) {
            this->frecventaRadioPerSenzor = new float[nrSenzori];
            for (int i = 0; i < nrSenzori; i++) {
                this->frecventaRadioPerSenzor[i] = frecventaRadioPerSenzor[i];
            }
        }
        else {
            this->frecventaRadioPerSenzor = NULL;
        }
        nrAntena++;

    }

    void afisareObj() {
        cout << "Serie Antena: " << serieAntena << ", Nume Antena: " << numeAntena << ", Material: " << material << ", Numar Senzori: " << nrSenzori << endl;
        if (frecventaRadioPerSenzor) {
            cout << "Frecventa Radio pe Senzorii Antenei: ";
            for (int i = 0; i < nrSenzori; ++i) {
                cout << frecventaRadioPerSenzor[i] << " MHz ";
            }
            cout << endl;
        }
    }


};

int Antena::nrAntena = 0;


class Firma {
public:
    const string codCAEN;
    static int nrFirme;
    char* denumireFirma;
    float profit;
    int anInfintare;


    int getNrFirme() {
        return this->nrFirme;
    }

    Firma() : codCAEN("7911") {
        this->denumireFirma = new char[strlen("New Electro") + 1];
        strcpy_s(this->denumireFirma, strlen("New Electro") + 1, "New Electro");
        this->profit = 3456;
        this->anInfintare = 2003;
        nrFirme++;
    }

    Firma(string codCAEN, const char* denumireFirma, float profit, int anInfintare) : codCAEN(codCAEN) {
        this->denumireFirma = new char[strlen(denumireFirma) + 1];
        strcpy_s(this->denumireFirma, strlen(denumireFirma) + 1, denumireFirma);
        this->profit = profit;
        this->anInfintare = anInfintare;
        nrFirme++;

    }

    Firma(const char* denumireFirma, float profit, int anInfintare) : codCAEN("7688") {
        this->denumireFirma = new char[strlen(denumireFirma) + 1];
        strcpy_s(this->denumireFirma, strlen(denumireFirma) + 1, denumireFirma);
        this->profit = profit;
        this->anInfintare = anInfintare;
        nrFirme++;
    }

    void afisareObj() {
        cout << "Cod CAEN: " << codCAEN << ", Denumire Firma: " << denumireFirma << ", Profit: " << profit << ", An Infintare: " << anInfintare << endl;
    }


};

int Firma::nrFirme = 0;


void main() {

    Angajat angajat;
    angajat.afisareObj();
    cout << endl;

    Angajat angajat1("Alex Andrei", 28, 4500.0);
    angajat1.afisareObj();
    cout << endl;

    Angajat angajat2(1, "Anca Popescu", 30, 5000.0);
    angajat2.afisareObj();
    cout << endl;

    cout << "Nr. Maxim Ore pentru Angajati: " << angajat.getNrMaximOre() << endl;
 



    cout << endl << endl << "----------------------------------------------" << endl;


    Antena antena;
    antena.afisareObj();
    cout << endl;


    Antena antena1("Antena Wi-Fi", "Plastic");
    antena1.afisareObj();
    cout << endl;

    float frecventeSenzori[] = { 15, 18, 20 };
    Antena antena2(101, "Antena GSM", "Aluminiu", 3, frecventeSenzori);
    antena2.afisareObj();
    cout << endl;

    cout << "Nr. Antene: " << antena.getNrAntena() << endl;
  


    cout << endl << endl << "----------------------------------------------" << endl;
    Firma firma;
    firma.afisareObj();
    cout << endl;


    Firma firma1("Ema Electro", 120430, 1995);
    firma1.afisareObj();
    cout << endl;

    Firma firma2("1234", "T&E Electronic", 1000, 2000);
    firma2.afisareObj();
    cout << endl;



    cout << "Nr. Firme: " << firma.getNrFirme() << endl;


}