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

    static int getNrMaximOre() {
        return nrMaximOre;
    }

    static void setNrMaximOre(int ore) {
        nrMaximOre = ore;
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

    friend float valoareBonusAnual(Angajat a);

    Angajat& operator=(const Angajat& a) {
        if (this == &a) {
            return *this;
        }

        if (nume != nullptr) {
            delete[] nume;
        }

        nume = new char[strlen(a.nume) + 1];
        strcpy(nume, a.nume);

        varsta = a.varsta;
        salariu = a.salariu;

        return *this;
    }

    float operator()() {
        return this->salariu * 12;
    }

    Angajat& operator+=(const Angajat& a) {
        this->salariu += a.salariu;
        return *this;
    }

    bool operator==(const Angajat& a) {
        return (varsta == a.varsta && salariu == a.salariu);
    }

    friend ostream& operator<<(ostream& out, const Angajat& a) {
        out << "Cod Angajat: " << a.codAngajat << ", Nume: " << a.nume << ", Varsta: " << a.varsta << ", Salariu: " << a.salariu;
        return out;
    }
};

int Angajat::nrMaximOre = 40;

float valoareBonusAnual(Angajat a) {
    return a.salariu * 1.5;
}



class Antena {
    const int serieAntena;
    static int nrAntena;
    char* numeAntena;
    string material;
    int nrSenzori;
    float* frecventaRadioPerSenzor;
public:

    Antena() : serieAntena(0) {
        this->numeAntena = new char[strlen("X") + 1];
        strcpy(this->numeAntena, "X");
        this->material = "N/A";
        this->nrSenzori = 0;
        this->frecventaRadioPerSenzor = NULL;
        nrAntena++;
    }


    Antena(const char* numeAntena, string material) : serieAntena(0) {
        this->numeAntena = new char[strlen(numeAntena) + 1];
        strcpy(this->numeAntena, numeAntena);
        this->material = material;
        this->nrSenzori = 0;
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
        if (frecventaRadioPerSenzor != NULL && nrSenzori > 0) {
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

    static int getNrAntena() {
        return nrAntena;
    }

    static void setNrAntena(int nr) {
        nrAntena = nr;
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

    friend float costRealizareSenzori(Antena a);


    Antena& operator=(const Antena& an) {
        if (this == &an) {
            return *this;
        }

        if (numeAntena != nullptr) {
            delete[] numeAntena;
        }

        numeAntena = new char[strlen(an.numeAntena) + 1];
        strcpy(numeAntena, an.numeAntena);

        material = an.material;
        nrSenzori = an.nrSenzori;

        if (frecventaRadioPerSenzor != nullptr) {
            delete[] frecventaRadioPerSenzor;
        }

        frecventaRadioPerSenzor = new float[nrSenzori];
        for (int i = 0; i < nrSenzori; i++) {
            frecventaRadioPerSenzor[i] = an.frecventaRadioPerSenzor[i];
        }

        return *this;
    }

    friend ostream& operator<<(ostream& out, const Antena& antena) {
        out << "Serie Antena: " << antena.serieAntena << ", Nume Antena: " << antena.numeAntena << ", Material: " << antena.material << ", Numar Senzori: " << antena.nrSenzori;
        if (antena.frecventaRadioPerSenzor != NULL && antena.nrSenzori > 0) {
            out << ", Frecventa Radio pe Senzorii Antenei: ";
            for (int i = 0; i < antena.nrSenzori; ++i) {
                out << antena.frecventaRadioPerSenzor[i] << " MHz ";
            }
        }
        return out;
    }

    bool operator>(const Antena& an) {
        return nrSenzori > an.nrSenzori;
    }


    explicit operator string() {
        return this->material;
    }

    bool operator!=(const Antena& an) {
        return this->serieAntena != an.serieAntena;
    }
};

int Antena::nrAntena = 1;

float costRealizareSenzori(Antena a) {
    return a.nrSenzori * 150;
}

class Firma {
    const string codCAEN;
    static int nrFirme;
    char* denumireFirma;
    float profit;
    int anInfintare;

public:

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

    static int getNrFirme() {
        return nrFirme;
    }

    static void setNrFirme(int nr) {
        nrFirme = nr;
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

    Firma& operator=(const Firma& f) {
        if (this == &f) {
            return *this;
        }

        if (denumireFirma != nullptr) {
            delete[] denumireFirma;
        }

        denumireFirma = new char[strlen(f.denumireFirma) + 1];
        strcpy(denumireFirma, f.denumireFirma);

        profit = f.profit;
        anInfintare = f.anInfintare;

        return *this;
    }

    friend ostream& operator<<(ostream& out, const Firma& firma) {
        out << "Cod CAEN: " << firma.codCAEN << ", Denumire Firma: " << firma.denumireFirma << ", Profit: " << firma.profit << ", An Infintare: " << firma.anInfintare;
        return out;
    }

    Firma& operator++() {
        profit++;
        return *this;
    }

    Firma operator++(int) {
        Firma aux = *this;
        profit++;
        return aux;
    }

    explicit operator float() {
        return this->profit;
    }
};

int Firma::nrFirme = 50;


int main() {

    Angajat angajat;
    angajat.afisareObj();
    cout << endl;

    Angajat angajat1("Alex Andrei", 28, 4500.0);
    angajat1.afisareObj();
    cout << endl;

    Angajat angajat2(54, "Anca Popescu", 30, 5000.0);
    angajat2.afisareObj();
    cout << endl;

    cout << "Nr. Maxim Ore pentru Angajati: " << angajat.getNrMaximOre() << endl;
    cout << "Nr. Maxim Ore pentru Angajati: " << angajat1.getNrMaximOre() << endl;
    cout << "Nr. Maxim Ore pentru Angajati: " << angajat2.getNrMaximOre() << endl;



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
    cout << "Nr. Antene: " << antena1.getNrAntena() << endl;
    cout << "Nr. Antene: " << antena2.getNrAntena() << endl;


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
    cout << "Nr. Firme: " << firma1.getNrFirme() << endl;
    cout << "Nr. Firme: " << firma2.getNrFirme() << endl;
    cout << endl << endl << "----------------------------------------------" << endl;
    cout << endl << endl << "----------------------------------------------" << endl;
    cout << endl << endl << "----------------------------------------------" << endl;
    cout << endl << endl << "----------------------------------------------" << endl;
    cout << endl << endl << "----------------------------------------------" << endl;
    cout << "Getteri si Setteri: " << endl << endl;
    Angajat angajat3 = angajat2;
    angajat3.afisareObj();
    cout << endl << endl;

    cout << angajat1.getCodAngajat() << endl;
    cout << angajat1.getNume() << endl;
    cout << angajat1.getSalariu() << endl;
    cout << angajat1.getVarsta() << endl;
    cout << angajat1.getNrMaximOre() << endl;
    cout << valoareBonusAnual(angajat1) << endl;

    angajat1.setNrMaximOre(60);
    angajat1.setNume("Ema Teo");
    angajat1.setSalariu(5000);
    angajat1.setVarsta(22);


    cout << endl << endl;
    cout << angajat1.getCodAngajat() << endl;
    cout << angajat1.getNume() << endl;
    cout << angajat1.getSalariu() << endl;
    cout << angajat1.getVarsta() << endl;
    cout << angajat1.getNrMaximOre() << endl;
    cout << valoareBonusAnual(angajat1) << endl;

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
    cout << antena3.getNrAntena() << endl;
    cout << costRealizareSenzori(antena3) << endl;


    antena3.setNumeAntena("Antena Wi-fi Helicopter");
    antena3.setMaterial("Carbon");
    antena3.setFrecventaRadioPerSenzor(4, new float[4] {22, 155, 45, 11});
    antena3.setNrAntena(546);
    cout << endl << endl;

    cout << antena3.getSerieAntena() << endl;
    cout << antena3.getNumeAntena() << endl;
    cout << antena3.getMaterial() << endl;
    cout << antena3.getNrSenzori() << endl;
    for (int i = 0; i < antena3.getNrSenzori(); i++) {
        cout << antena3.getFrecventaRadioPerSenzor()[i] << ", ";
    }
    cout << endl;
    cout << antena3.getNrAntena() << endl;
    cout << costRealizareSenzori(antena3) << endl;

    cout << "=============================================" << endl << endl;
    Firma firma3 = firma2;
    firma3.afisareObj();
    cout << endl << endl;
    cout << firma3.getCodCAEN() << endl;
    cout << firma3.getDenumireFirma() << endl;
    cout << firma3.getProfit() << endl;
    cout << firma3.getAnInfintare() << endl;
    cout << firma3.getNrFirme() << endl;

    firma3.setDenumireFirma("T&E Association");
    firma3.setProfit(15000.0);
    firma3.setAnInfintare(1995);
    firma3.setNrFirme(111);


    cout << endl << endl;
    cout << firma3.getCodCAEN() << endl;
    cout << firma3.getDenumireFirma() << endl;
    cout << firma3.getProfit() << endl;
    cout << firma3.getAnInfintare() << endl;
    cout << firma3.getNrFirme() << endl;


    cout << "OPERATORI" << endl << endl << endl;
    cout << angajat << endl;
    cout << angajat1 << endl;
    cout << angajat2 << endl;
    Angajat ang;
    ang = angajat2;
    cout << ang << endl;

    cout << endl;
    cout << ang() << endl;
    cout << angajat1() << endl;
    cout << endl;

    cout << endl;
    angajat1 += angajat2;
    cout << angajat1 << endl;
    cout << angajat2 << endl;
    cout << endl;

    cout << "Angajat1 are aceeasi varsta cu Angajat2? " << ((angajat1 == angajat2) ? "Da" : "Nu") << endl;
    cout << "Ang are aceeasi varsta cu Angajat2? " << ((angajat == angajat2) ? "Da" : "Nu") << endl;

    cout << endl << endl << endl << endl;


    Antena ant;
    ant = antena1;
    cout << ant << endl;
    cout << antena1 << endl;
    cout << antena2 << endl;
    cout << endl;

    cout << "Antena2 are mai multi senzori decat Antena1? " << ((antena2 > antena1) ? "Da" : "Nu") << endl;
    cout << "Antena1 are mai multi senzori decat Antena2? " << ((antena1 > antena2) ? "Da" : "Nu") << endl;
    cout << endl;

    cout << (string)antena2 << endl;
    cout << (string)antena1 << endl;
    cout << endl;

    cout << "Antena2 are seria diferita de Antena1? " << ((antena2 != antena1) ? "Da" : "Nu") << endl;
    cout << "Antena2 are seria diferita de Ant? " << ((antena2 != ant) ? "Da" : "Nu") << endl;
    cout << "Antena are seria diferita de Ant? " << ((ant != antena) ? "Da" : "Nu") << endl;


    cout << endl << endl << endl << endl;

    Firma f;
    cout << f << endl;
    cout << endl;

    f = firma1++;
    cout << f << endl;
    cout << firma1 << endl;

    cout << endl;

    Firma f1 = ++firma1;
    cout << f1 << endl;
    cout << firma1 << endl;
    cout << endl;

    cout << (float)f1 << endl;



}