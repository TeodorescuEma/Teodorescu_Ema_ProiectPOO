#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Angajat {
    const int codAngajat;
    static int nrMaximOre;
    char* nume;
    int varsta;
    float salariu;
public:
    static int getNrMaximOre() {
        return nrMaximOre;
    }


    Angajat() : codAngajat(0) {
        this->nume = new char[strlen("X") + 1];
        strcpy(this->nume, "X");
        this->varsta = 0;
        this->salariu = 0;
    }



    Angajat(const char* nume, int varsta, float salariu) : codAngajat(0) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->varsta = varsta;
        this->salariu = salariu;
    }

    Angajat(int codAngajat, const char* nume, int varsta, float salariu) : codAngajat(codAngajat) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->varsta = varsta;
        this->salariu = salariu;
    }

    Angajat(const Angajat& a) :codAngajat(a.codAngajat) {
        this->nume = new char[strlen(a.nume) + 1];
        strcpy(this->nume, a.nume);
        this->varsta = a.varsta;
        this->salariu = a.salariu;
    }


    void afisareObj() {
        cout << "Cod Angajat: " << codAngajat << ", Nume: " << nume << ", Varsta: " << varsta << ", Salariu: " << salariu << endl;
    }

    ~Angajat() {
        if (this->nume != NULL) {
            delete[]this->nume;
        }
    }

    int getCodAngajat() {
        return codAngajat;
    }


    char* getNume() {
        return nume;
    }

    void setNume(const char* nume) {
        delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    int getVarsta() {
        return varsta;
    }

    void setVarsta(int varsta) {
        this->varsta = varsta;
    }

    float getSalariu() {
        return salariu;
    }

    void setSalariu(float salariu) {
        this->salariu = salariu;
    }

    friend float valoareBonusAnual(const Angajat& a);
};

int Angajat::nrMaximOre = 40;

float valoareBonusAnual(const Angajat& a) {
    return a.salariu * 1.5;
}



class Antena {
    const int serieAntena;
    static int nrAntene;
    char* numeAntena;
    string material;
    int nrSenzori;
    float* frecventaRadioPerSenzor;
public:
    static int getNrAntene() {
        return nrAntene;
    }

    Antena() : serieAntena(0) {
        this->numeAntena = new char[strlen("X") + 1];
        strcpy(this->numeAntena, "X");
        this->material = "N/A";
        this->nrSenzori = 0;
        this->frecventaRadioPerSenzor = NULL;
        nrAntene++;
    }


    Antena(const char* numeAntena, string material) : serieAntena(0) {
        this->numeAntena = new char[strlen(numeAntena) + 1];
        strcpy(this->numeAntena, numeAntena);
        this->material = material;
        this->nrSenzori = 0;
        this->frecventaRadioPerSenzor = NULL;
        nrAntene++;

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
        nrAntene++;

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

    Antena(const Antena& a) :serieAntena(a.serieAntena) {
        this->numeAntena = new char[strlen(a.numeAntena) + 1];
        strcpy(this->numeAntena, a.numeAntena);
        this->material = a.material;
        this->nrSenzori = a.nrSenzori;
        if (nrSenzori > 0) {
            this->frecventaRadioPerSenzor = new float[nrSenzori];
            for (int i = 0; i < nrSenzori; i++) {
                this->frecventaRadioPerSenzor[i] = a.frecventaRadioPerSenzor[i];
            }
        }
        else {
            this->frecventaRadioPerSenzor = NULL;
        }
    }

    int getSerieAntena() {
        return serieAntena;
    }

    const char* getNumeAntena() {
        return numeAntena;
    }

    void setNumeAntena(const char* numeAntena) {
        if (this->numeAntena) {
            delete[] this->numeAntena;
        }
        this->numeAntena = new char[strlen(numeAntena) + 1];
        strcpy(this->numeAntena, numeAntena);
    }

    string getMaterial() {
        return material;
    }

    void setMaterial(string material) {
        this->material = material;
    }

    int getNrSenzori() {
        return nrSenzori;
    }


    float* getFrecventaRadioPerSenzor() {
        return frecventaRadioPerSenzor;
    }

    void setFrecventaRadioPerSenzor(int nrSenzori, float* frecventaRadioPerSenzor) {
        this->nrSenzori = nrSenzori;
        if (this->frecventaRadioPerSenzor != NULL) {
            delete[]this->frecventaRadioPerSenzor;
        }
        this->frecventaRadioPerSenzor = new float[nrSenzori];
        for (int i = 0; i < this->nrSenzori; i++) {
            this->frecventaRadioPerSenzor[i] = frecventaRadioPerSenzor[i];
        }
    }

    ~Antena() {
        if (numeAntena != NULL) {
            delete[]this->numeAntena;
        }
        if (frecventaRadioPerSenzor != NULL) {
            delete[]this->frecventaRadioPerSenzor;
        }
    }

    friend float costRealizareSenzori(const Antena& a);
};

int Antena::nrAntene = 1;

float costRealizareSenzori(const Antena& a) {
    return a.nrSenzori * 150;
}

class Firma {
    const string codCAEN;
    static int nrFirme;
    char* denumireFirma;
    float profit;
    int anInfintare;

public:
    static int getNrFirme() {
        return nrFirme;
    }

    Firma() : codCAEN("0000") {
        this->denumireFirma = new char[strlen("X") + 1];
        strcpy(this->denumireFirma, "X");
        this->profit = 0;
        this->anInfintare = 0;
        nrFirme++;
    }

    Firma(string codCAEN, const char* denumireFirma, float profit, int anInfintare) : codCAEN(codCAEN) {
        this->denumireFirma = new char[strlen(denumireFirma) + 1];
        strcpy(this->denumireFirma, denumireFirma);
        this->profit = profit;
        this->anInfintare = anInfintare;
        nrFirme++;

    }

    Firma(const char* denumireFirma, float profit, int anInfintare) : codCAEN("0000") {
        this->denumireFirma = new char[strlen(denumireFirma) + 1];
        strcpy(this->denumireFirma, denumireFirma);
        this->profit = profit;
        this->anInfintare = anInfintare;
        nrFirme++;
    }

    Firma(const Firma& f) :codCAEN(f.codCAEN) {
        this->denumireFirma = new char[strlen(f.denumireFirma) + 1];
        strcpy(this->denumireFirma, f.denumireFirma);
        this->profit = f.profit;
        this->anInfintare = f.anInfintare;
        nrFirme++;
    }

    void afisareObj() {
        cout << "Cod CAEN: " << codCAEN << ", Denumire Firma: " << denumireFirma << ", Profit: " << profit << ", An Infintare: " << anInfintare << endl;
    }


    const string& getCodCAEN() {
        return this->codCAEN;
    }

    const char* getDenumireFirma() {
        return this->denumireFirma;
    }

    void setDenumireFirma(const char* denumireFirma) {
        if (this->denumireFirma) {
            delete[] this->denumireFirma;
        }
        this->denumireFirma = new char[strlen(denumireFirma) + 1];
        strcpy(this->denumireFirma, denumireFirma);
    }

    float getProfit() {
        return this->profit;
    }

    void setProfit(float profit) {
        this->profit = profit;
    }

    int getAnInfintare() {
        return this->anInfintare;
    }

    void setAnInfintare(int anInfintare) {
        this->anInfintare = anInfintare;
    }

    ~Firma() {
        if (this->denumireFirma) {
            delete[] this->denumireFirma;
        }
    }

};

int Firma::nrFirme = 50;


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


    cout << "Nr. Maxim Ore pentru Angajati: " << Angajat::getNrMaximOre() << endl;



    cout << endl << endl;


    Antena antena;
    antena.afisareObj();
    cout << endl;


    Antena antena1("Antena Wi-Fi", "Plastic");
    antena1.afisareObj();
    cout << endl;

    float* frecventeSenzori = new float[3] { 15, 18, 20 };
    Antena antena2(101, "Antena GSM", "Aluminiu", 3, frecventeSenzori);
    antena2.afisareObj();
    cout << endl;


    cout << "Nr. Antene: " << Antena::getNrAntene() << endl;


    cout << endl << endl;
    Firma firma;
    firma.afisareObj();
    cout << endl;


    Firma firma1("Ema Electro", 120430, 1995);
    firma1.afisareObj();
    cout << endl;

    Firma firma2("1234", "T&E Electronic", 1000, 2000);
    firma2.afisareObj();
    cout << endl;
    cout << "Numar total de fime este:" << Firma::getNrFirme() << endl;
    cout << endl << endl;
    cout << "Getteri si Setteri: " << endl << endl;
    Angajat angajat3 = angajat2;
    angajat3.afisareObj();
    cout << endl << endl;

    cout << angajat1.getCodAngajat() << endl;
    cout << angajat1.getNume() << endl;
    cout << angajat1.getSalariu() << endl;
    cout << angajat1.getVarsta() << endl;
    cout << angajat1.getNrMaximOre() << endl;
    cout << "Valoarea bonsului este de:" << valoareBonusAnual(angajat1) << endl;

    angajat1.setNume("Ema Teo");
    angajat1.setSalariu(5000);
    angajat1.setVarsta(22);
    cout << endl;
    angajat1.afisareObj();

    cout << endl << endl;
    cout << angajat1.getCodAngajat() << endl;
    cout << angajat1.getNume() << endl;
    cout << angajat1.getSalariu() << endl;
    cout << angajat1.getVarsta() << endl;
    cout << angajat1.getNrMaximOre() << endl;
    cout << "Valoarea bonusului este de: " << valoareBonusAnual(angajat1) << endl;

    cout << "=============================================" << endl << endl;
    Antena antena3 = antena2;
    antena3.afisareObj();
    cout << endl << endl;

    cout << antena3.getSerieAntena() << endl;
    cout << antena3.getNumeAntena() << endl;
    cout << antena3.getMaterial() << endl;
    cout << antena3.getNrSenzori() << endl;
    for (int i = 0; i < antena3.getNrSenzori(); i++) {
        cout << antena3.getFrecventaRadioPerSenzor()[i] << ", ";
    }
    cout << endl;
    cout << "Costul de realizare al antenei este: " << costRealizareSenzori(antena3) << " lei." << endl;


    antena3.setNumeAntena("Antena Wi-fi Helicopter");
    antena3.setMaterial("Carbon");
    float* frecvPerSenzor = new float [4] {22, 155, 45, 11};
    antena3.setFrecventaRadioPerSenzor(4, frecvPerSenzor);
    cout << endl;
    antena3.afisareObj();
    cout << endl << endl;

    cout << antena3.getSerieAntena() << endl;
    cout << antena3.getNumeAntena() << endl;
    cout << antena3.getMaterial() << endl;
    cout << antena3.getNrSenzori() << endl;
    for (int i = 0; i < antena3.getNrSenzori(); i++) {
        cout << antena3.getFrecventaRadioPerSenzor()[i] << ", ";
    }
    cout << endl;
    cout << "Costul de realizare al antenei este: " << costRealizareSenzori(antena3) << " lei." << endl;

    cout << "=============================================" << endl << endl;
    Firma firma3 = firma2;
    firma3.afisareObj();
    cout << endl << endl;
    cout << firma3.getCodCAEN() << endl;
    cout << firma3.getDenumireFirma() << endl;
    cout << firma3.getProfit() << endl;
    cout << firma3.getAnInfintare() << endl;

    firma3.setDenumireFirma("T&E Association");
    firma3.setProfit(15000.0);
    firma3.setAnInfintare(1995);
    cout << endl;
    firma3.afisareObj();


    cout << endl << endl;
    cout << firma3.getCodCAEN() << endl;
    cout << firma3.getDenumireFirma() << endl;
    cout << firma3.getProfit() << endl;
    cout << firma3.getAnInfintare() << endl;


    delete[]frecvPerSenzor;
    delete[]frecventeSenzori;
}