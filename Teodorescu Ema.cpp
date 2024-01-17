#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CalculSalariu {

public:
    virtual float salariuLunar() = 0;
};

class FunctieInCampulMuncii {
public:
    virtual string recunoasteGrad() = 0;
};

class Angajat : public CalculSalariu, public FunctieInCampulMuncii {
private:
    const int codAngajat;
    static int nrMaximOre;
    char* nume;
    int varsta;
    float salariu;
public:

    Angajat() : codAngajat(0) {
        this->nume = new char[strlen("Andrei") + 1];
        strcpy(this->nume, "Andrei");
        this->varsta = 27;
        this->salariu = 4500;
    }

    string recunoasteGrad() {
        return "Angajat";
    }
    float salariuLunar() {
        return salariu;
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
        if (this != &a) {

            if (nume != nullptr) {
                delete[] nume;
            }

            nume = new char[strlen(a.nume) + 1];
            strcpy(nume, a.nume);

            varsta = a.varsta;
            salariu = a.salariu;
        }
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
        out << "Cod Angajat: " << a.codAngajat << ", Nume: " << a.nume << ", Varsta: " << a.varsta << " ani, Salariu: " << a.salariu << " lei";
        return out;
    }

    friend istream& operator>>(istream& in, Angajat& a) {

        cout << "Introduceti numele: ";
        char aux[100];
        in >> aux;
        delete[] a.nume;

        a.nume = new char[strlen(aux) + 1];
        strcpy(a.nume, aux);

        cout << "Introduceti varsta: ";
        in >> a.varsta;

        cout << "Introduceti salariul: ";
        in >> a.salariu;
        return in;
    }
    void scriereInFisBin(string numeFisier) {
        ofstream a(numeFisier, ios::out | ios::binary);
        int lungime = strlen(this->nume);
        a.write((char*)&lungime, sizeof(int));
        a.write((char*)this->nume, lungime + 1);
        a.write((char*)&this->varsta, sizeof(int));
        a.write((char*)&this->salariu, sizeof(float));
        a.close();
    }
    void citireInFisBin(string numeFisier) {
        ifstream a(numeFisier, ios::in | ios::binary);

        if (this->nume != NULL) {
            delete[]this->nume;
        }
        int lungime;
        a.read((char*)&lungime, sizeof(int));
        this->nume = new char[lungime + 1];
        a.read(this->nume, lungime + 1);
        a.read((char*)&this->varsta, sizeof(int));
        a.read((char*)&this->salariu, sizeof(float));
        a.close();
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
        this->numeAntena = new char[strlen("Satelit") + 1];
        strcpy(this->numeAntena, "Satelit");
        this->material = "Metal";
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
        if (this != &an) {



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

    friend istream& operator>>(istream& in, Antena& a) {

        cout << "Introduceti numele antenei: ";
        char aux[100];
        in >> aux;

        if (a.numeAntena != NULL) {
            delete[] a.numeAntena;
        }

        a.numeAntena = new char[strlen(aux) + 1];
        strcpy(a.numeAntena, aux);
        cout << "Introduceti materialul antenei: ";
        in >> a.material;

        cout << "Introduceti numarul de senzori: ";
        in >> a.nrSenzori;

        if (a.frecventaRadioPerSenzor != NULL) {
            delete[] a.frecventaRadioPerSenzor;
        }
        a.frecventaRadioPerSenzor = new float[a.nrSenzori];

        cout << "Introduceti frecventele radio per senzor: ";

        for (int i = 0; i < a.nrSenzori; ++i) {
            in >> a.frecventaRadioPerSenzor[i];
        }

        return in;
    }
    friend ifstream& operator>>(ifstream& in, Antena& a) {
        char buffer[100];
        in >> ws;
        in.getline(buffer, 99);
        if (a.numeAntena != NULL) {
            delete[] a.numeAntena;
        }
        a.numeAntena = new char[strlen(buffer) + 1];
        strcpy_s(a.numeAntena, strlen(buffer) + 1, buffer);
        in >> a.material;
        in >> a.nrSenzori;

        if (a.frecventaRadioPerSenzor != NULL) {
            delete[] a.frecventaRadioPerSenzor;
        }
        a.frecventaRadioPerSenzor = new float[a.nrSenzori];
        for (int i = 0; i < a.nrSenzori; ++i) {
            in >> a.frecventaRadioPerSenzor[i];
        }
        return in;
    }

    friend ofstream& operator<<(ofstream& out, const Antena& antena) {
        out << antena.numeAntena << endl;
        out << antena.material << endl;
        out << antena.nrSenzori << endl;
        if (antena.frecventaRadioPerSenzor != NULL && antena.nrSenzori > 0) {
            for (int i = 0; i < antena.nrSenzori; ++i) {
                out << antena.frecventaRadioPerSenzor[i] << "  ";
            }
        }
        return out;
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
        this->denumireFirma = new char[strlen("Star Elect") + 1];
        strcpy(this->denumireFirma, "Star Elect");
        this->profit = 2365;
        this->anInfintare = 1997;
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
        if (this != &f) {


            if (denumireFirma != nullptr) {
                delete[] denumireFirma;
            }

            denumireFirma = new char[strlen(f.denumireFirma) + 1];
            strcpy(denumireFirma, f.denumireFirma);

            profit = f.profit;
            anInfintare = f.anInfintare;
        }
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

    friend istream& operator>>(istream& in, Firma& f) {
        cout << "Introduceti denumirea firmei: ";
        char aux[100];
        in >> aux;

        if (f.denumireFirma != nullptr) {
            delete[] f.denumireFirma;
        }

        f.denumireFirma = new char[strlen(aux) + 1];
        strcpy(f.denumireFirma, aux);

        cout << "Introduceti profitul firmei: ";
        in >> f.profit;

        cout << "Introduceti anul infiintarii firmei: ";
        in >> f.anInfintare;
        return in;
    }
    void scriereInFisBin(string numeFisier) {
        ofstream f(numeFisier, ios::out | ios::binary);
        int lungime = strlen(this->denumireFirma);
        f.write((char*)&lungime, sizeof(int));
        f.write((char*)this->denumireFirma, lungime + 1);
        f.write((char*)&this->anInfintare, sizeof(int));
        f.write((char*)&this->profit, sizeof(float));
        f.close();
    }
    void citireInFisBin(string numeFisier) {
        ifstream f(numeFisier, ios::in | ios::binary);

        if (this->denumireFirma != NULL) {
            delete[]this->denumireFirma;
        }
        int lungime;
        f.read((char*)&lungime, sizeof(int));
        this->denumireFirma = new char[lungime + 1];
        f.read(this->denumireFirma, lungime + 1);
        f.read((char*)&this->anInfintare, sizeof(int));
        f.read((char*)&this->profit, sizeof(float));
        f.close();
    }
};

int Firma::nrFirme = 50;


class Satelit {
    string denumire;
    float greutate;
    float pretFabricare;
    int nrAntene;
    Antena** antene;
    bool areCamera;

public:
    Satelit() {
        this->denumire = "Neptun";
        this->greutate = 36.5;
        this->pretFabricare = 3.21;
        this->nrAntene = 0;
        this->antene = nullptr;
        this->areCamera = false;
    }

    // Constructor cu parametri
    Satelit(string denumire, float greutate, float pretFabricare, int nrAntene, Antena** antene, bool areCamera) {
        this->denumire = denumire;
        this->greutate = greutate;
        this->pretFabricare = pretFabricare;
        this->nrAntene = nrAntene;
        if (nrAntene > 0) {
            this->antene = new Antena * [nrAntene];
            for (int i = 0; i < nrAntene; ++i) {
                this->antene[i] = new Antena(*antene[i]);
            }
        }
        else {
            this->antene = NULL;
        }
        this->areCamera = areCamera;

    }

    // Constructor de copiere
    Satelit(const Satelit& s) {
        this->denumire = s.denumire;
        this->greutate = s.greutate;
        this->pretFabricare = s.pretFabricare;
        this->nrAntene = s.nrAntene;
        if (s.nrAntene > 0) {
            this->antene = new Antena * [nrAntene];
            for (int i = 0; i < nrAntene; ++i) {
                this->antene[i] = new Antena(*s.antene[i]);
            }
        }
        else {
            this->antene = NULL;
        }
        this->areCamera = s.areCamera;
    }


    Satelit& operator=(const Satelit& s) {
        if (this != &s) {
            if (this->antene != NULL) {
                for (int i = 0; i < this->nrAntene; i++) {
                    delete this->antene[i];
                }
                delete[] this->antene;
            }
            this->denumire = s.denumire;
            this->greutate = s.greutate;
            this->pretFabricare = s.pretFabricare;
            this->nrAntene = s.nrAntene;
            if (s.nrAntene > 0) {
                this->antene = new Antena * [nrAntene];
                for (int i = 0; i < nrAntene; ++i) {
                    this->antene[i] = new Antena(*s.antene[i]);
                }
            }
            else {
                this->antene = NULL;
            }
            this->areCamera = s.areCamera;
        }
        return *this;
    }

    ~Satelit() {
        if (this->antene != NULL) {
            for (int i = 0; i < this->nrAntene; i++) {
                delete this->antene[i];
            }
            delete[] this->antene;
        }

    }

    string getDenumire() {
        return denumire;
    }

    void setDenumire(string denumire) {
        this->denumire = denumire;
    }

    float getGreutate() {
        return greutate;
    }

    void setGreutate(float greutate) {
        this->greutate = greutate;
    }

    float getPretFabricare() {
        return pretFabricare;
    }

    void setPretFabricare(float pretFabricare) {
        this->pretFabricare = pretFabricare;
    }

    int getNrAntene() {
        return nrAntene;
    }

    Antena** getAntene() {
        return this->antene;
    }

    void setAntene(int nrAntene, Antena** antene) {
        if (nrAntene > 0 && antene != NULL) {
            this->nrAntene = nrAntene;
            if (this->antene != NULL) {
                for (int i = 0; i < this->nrAntene; i++) {
                    delete this->antene[i];
                }
                delete[] this->antene;
            }
            this->antene = new Antena * [nrAntene];
            for (int i = 0; i < nrAntene; ++i) {
                this->antene[i] = new Antena(*antene[i]);
            }
        }

    }

    bool getAreCamera() {
        return areCamera;
    }

    void setAreCamera(bool areCamera) {
        this->areCamera = areCamera;
    }

    friend ostream& operator<<(ostream& out, const Satelit& s) {
        out << "Denumire satelit: " << s.denumire << endl;
        out << "Greutate: " << s.greutate << endl;
        out << "Pret fabricare: " << s.pretFabricare << endl;
        out << "Numar antene: " << s.nrAntene << endl;
        out << "Antene:" << endl;
        for (int i = 0; i < s.nrAntene; i++) {
            out << *s.antene[i] << endl;
        }
        out << endl;
        out << "Are camera: " << s.areCamera << endl;
        return out;
    }

    //cantitate din tone in kg
    float operator()() {
        return this->greutate * 1000;
    }

    explicit operator float() {
        return this->pretFabricare;
    }

    Satelit operator +(float valoare) {
        Satelit copie = *this;
        copie.greutate += valoare;
        copie.pretFabricare += valoare;
        return copie;
    }

    friend Satelit operator-(float val, Satelit s) {
        Satelit copie = s;
        if (s.pretFabricare > val) {
            copie.pretFabricare -= val;
        }
        return copie;
    }
    friend istream& operator>>(istream& in, Satelit& s) {
        cout << "Introduceti denumirea satelitului: ";
        in >> s.denumire;
        cout << "Introduceti greutatea: ";
        in >> s.greutate;
        cout << "Introduceti pretul de fabricare: ";
        in >> s.pretFabricare;
        cout << "Introduceti numarul de antene: ";
        in >> s.nrAntene;
        if (s.nrAntene > 0) {
            if (s.antene != NULL) {
                for (int i = 0; i < s.nrAntene; i++) {
                    delete[]s.antene[i];
                }
                delete[]s.antene;
            }
            s.antene = new Antena * [s.nrAntene];
            for (int i = 0; i < s.nrAntene; i++) {
                cout << "Introduceti antena de pe pozitia [" << i + 1 << "]: ";

                in >> *s.antene[i];
            }
        }
        else {
            s.antene = NULL;
        }
        return in;
    }
    friend ofstream& operator<<(ofstream& out, const Satelit& s) {
        out << s.denumire << endl;
        out << s.greutate << endl;
        out << s.pretFabricare << endl;
        out << s.nrAntene << endl;
        if (s.nrAntene > 0) {
            for (int i = 0; i < s.nrAntene; i++) {
                out << *s.antene[i];
            }
        }
        out << s.areCamera << endl;
        return out;

    }
    friend ifstream& operator>>(ifstream& in, Satelit& s) {
        in >> s.denumire;
        in >> s.greutate;
        in >> s.pretFabricare;
        in >> s.nrAntene;
        if (s.nrAntene > 0) {
            if (s.antene != NULL) {
                for (int i = 0; i < s.nrAntene; i++) {
                    delete[]s.antene[i];
                }
                delete[]s.antene;
            }
            s.antene = new Antena * [s.nrAntene];
            for (int i = 0; i < s.nrAntene; i++) {
                Antena aux;
                in >> aux;
                s.antene[i] = new Antena(aux);
            }
        }
        else {
            s.antene = NULL;
        }
        return in;
    }
};

class Inginer : public Angajat {
    string departament;
    int vechimeInDomeniu;
    bool areFacultateTerminata;

public:
    Inginer() : Angajat() {
        this->departament = "Mecanica";
        this->vechimeInDomeniu = 7;
        this->areFacultateTerminata = true;
    }

    Inginer(const char* nume, int varsta, float salariu, string departament, int vechime, bool facultateTerminata)
        : Angajat(nume, varsta, salariu) {
        this->departament = departament;
        this->vechimeInDomeniu = vechime;
        this->areFacultateTerminata = facultateTerminata;
    }

    Inginer(int codAngajat, const char* nume, int varsta, float salariu, string departament, int vechime, bool facultateTerminata)
        : Angajat(codAngajat, nume, varsta, salariu) {
        this->departament = departament;
        this->vechimeInDomeniu = vechime;
        this->areFacultateTerminata = facultateTerminata;
    }

    Inginer(const Inginer& ing) : Angajat(ing) {
        this->departament = ing.departament;
        this->vechimeInDomeniu = ing.vechimeInDomeniu;
        this->areFacultateTerminata = ing.areFacultateTerminata;
    }

    string getDepartament() {
        return departament;
    }

    void setDepartament(string departament) {
        departament = departament;
    }

    int getVechimeInDomeniu() {
        return vechimeInDomeniu;
    }

    void setVechimeInDomeniu(int vechimeInDomeniu) {
        vechimeInDomeniu = vechimeInDomeniu;
    }

    bool getAreFacultateTerminata() {
        return areFacultateTerminata;
    }

    void setAreFacultateTerminata(bool facultateTerminata) {
        areFacultateTerminata = facultateTerminata;
    }

    Inginer& operator=(const Inginer& ing) {
        if (this != &ing) {
            Angajat::operator=(ing);
            this->departament = ing.departament;
            this->vechimeInDomeniu = ing.vechimeInDomeniu;
            this->areFacultateTerminata = ing.areFacultateTerminata;
        }
        return *this;
    }

    friend ostream& operator << (ostream& out, const Inginer& ing) {
        out << (Angajat&)ing;
        out << ", Departament: " << ing.departament << ", Vechime in Domeniu: " << ing.vechimeInDomeniu
            << "ani, Facultate Terminata: " << (ing.areFacultateTerminata ? "Da" : "Nu") << endl;
        return out;
    }

    ~Inginer() {

    }

    string recunoasteGrad() {
        return "Inginer";
    }
    float salariuLunar() {
        return getSalariu() + 500;
    }
};

class Manager : public Angajat {
    string departamentManageriat;
    int aniFunctie;
    int nrSubordonati;

public:
    Manager() : Angajat() {
        this->departamentManageriat = "Resurse Umane";
        this->aniFunctie = 4;
        this->nrSubordonati = 56;
    }

    Manager(const char* nume, int varsta, float salariu, string departamentManageriat, int aniFunctie, int nrSubordonati)
        : Angajat(nume, varsta, salariu) {
        this->departamentManageriat = departamentManageriat;
        this->aniFunctie = aniFunctie;
        this->nrSubordonati = nrSubordonati;
    }

    Manager(int codAngajat, const char* nume, int varsta, float salariu, string departamentManageriat, int aniFunctie, int nrSubordonati)
        : Angajat(codAngajat, nume, varsta, salariu) {
        this->departamentManageriat = departamentManageriat;
        this->aniFunctie = aniFunctie;
        this->nrSubordonati = nrSubordonati;
    }


    string getDepartamentManageriat() {
        return departamentManageriat;
    }

    void setDepartamentManageriat(string departamentManageriat) {
        this->departamentManageriat = departamentManageriat;
    }

    int getAniFunctie() {
        return aniFunctie;
    }

    void setAniFunctie(int aniFunctie) {
        this->aniFunctie = aniFunctie;
    }

    int getNrSubordonati() {
        return nrSubordonati;
    }

    void setNrSubordonati(int nrSubordonati) {
        this->nrSubordonati = nrSubordonati;
    }

    Manager(const Manager& manager) : Angajat(manager) {
        this->departamentManageriat = manager.departamentManageriat;
        this->aniFunctie = manager.aniFunctie;
        this->nrSubordonati = manager.nrSubordonati;
    }

    ~Manager() {

    }

    Manager& operator=(const Manager& manager) {
        if (this != &manager) {
            Angajat::operator=(manager);
            this->departamentManageriat = manager.departamentManageriat;
            this->aniFunctie = manager.aniFunctie;
            this->nrSubordonati = manager.nrSubordonati;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Manager& manager) {
        out << (Angajat&)manager;
        out << ", Departament Manageriat: " << manager.departamentManageriat << ", Ani in Functie: " << manager.aniFunctie
            << " ani, Numar Subordonati: " << manager.nrSubordonati << " angajati" << endl;
        return out;
    }


    string recunoasteGrad() {
        return "Manager";
    }
    float salariuLunar() {
        return getSalariu() + 2000;
    }
};


void main() {


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
    antena3.setFrecventaRadioPerSenzor(4, new float[4] { 22, 155, 45, 11 });
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

    cout << endl << endl << endl << endl;

    Angajat* vectAngajat = new Angajat[2];
    Antena* vectAntena = new Antena[2];
    Firma* vectFirma = new Firma[2];

    for (int i = 0; i < 2; i++) {
        cin >> vectAngajat[i];
    }
    cout << endl << endl;
    for (int i = 0; i < 2; i++) {
        cout << vectAngajat[i] << endl;
    }


    cout << endl << endl << endl << endl;

    for (int i = 0; i < 2; i++) {
        cin >> vectAntena[i];
    }
    cout << endl << endl;
    for (int i = 0; i < 2; i++) {
        cout << vectAntena[i] << endl;
    }

    cout << endl << endl << endl << endl;

    for (int i = 0; i < 2; i++) {
        cin >> vectFirma[i];
    }
    cout << endl << endl;
    for (int i = 0; i < 2; i++) {
        cout << vectFirma[i] << endl;
    }

    cout << endl << endl << endl << endl;

    int nrRanduri = 2;
    int nrColoane = 2;
    Angajat matriceAngajati[2][2];
    for (int i = 0; i < nrRanduri; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            cout << "Introduceti informatii pentru angajatul [" << i << "][" << j << "]:\n";
            cin >> matriceAngajati[i][j];
        }
    }

    for (int i = 0; i < nrRanduri; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            cout << "Informatii angajat [" << i << "][" << j << "]:\n" << matriceAngajati[i][j] << "\n\n";
        }
    }

    cout << "==================================================================================" << endl << endl;

    vectAntena[0] = antena2;
    vectAntena[1] = antena3;

    Antena* vectPointeriAntene[3];
    vectPointeriAntene[0] = &antena1;
    vectPointeriAntene[1] = &antena2;
    vectPointeriAntene[2] = &antena3;
    Satelit s;
    cout << s.getDenumire() << endl;
    cout << s.getPretFabricare() << endl;
    cout << s.getGreutate() << endl;
    cout << s.getNrAntene() << endl;
    for (int i = 0; i < s.getNrAntene(); i++) {
        cout << *s.getAntene()[i] << endl;
    }
    cout << s.getAreCamera() << endl;

    s.setDenumire("Saturn");
    s.setGreutate(45.13);
    s.setPretFabricare(2.1);
    s.setAreCamera(1);
    s.setAntene(1, vectPointeriAntene);

    cout << endl << endl;;
    cout << s.getDenumire() << endl;
    cout << s.getPretFabricare() << endl;
    cout << s.getGreutate() << endl;
    cout << s.getNrAntene() << endl;
    for (int i = 0; i < s.getNrAntene(); i++) {
        cout << *s.getAntene()[i] << endl;
    }
    cout << s.getAreCamera() << endl;
    cout << endl << endl;;


    Satelit s1("Magnum", 4.5, 11.11, 2, vectPointeriAntene, 1);
    cout << s1 << endl;

    Satelit s2 = s;
    Satelit s3 = s1;

    cout << s2 << endl;
    cout << s3 << endl;

    cout << endl;

    s = s1;

    cout << s << endl;

    cout << endl << endl;

    cout << s1() << endl;
    cout << (float)s1 << endl;
    cout << s1 << endl;
    cout << endl << endl;


    Satelit s4 = s1 + 5000;
    cout << s1 << endl;
    cout << s4 << endl;

    cout << endl << endl;


    Satelit s5 = 2000 - s4;
    cout << s4 << endl;
    cout << s5 << endl;
    cin >> s1;
    cout << s1 << endl;

     cout << "Fisiere text:" << endl;
     cout << endl;
     ofstream fisAntena("antene.txt", ios::out);
     fisAntena << antena2;
     fisAntena.close();
     cout << endl;
     Antena a1;
     ifstream fisAnt("antene.txt", ios::in);
     fisAnt >> a1;
     cout << a1 << endl;;
     fisAnt.close();

     ofstream fisSatelit("satelit.txt", ios::out);
     fisSatelit << s4;
     fisSatelit.close();
     cout << endl;
     Satelit satelit1;
     ifstream fisSat("satelit.txt", ios::in);
     fisSat >> satelit1;
     cout << satelit1 << endl;;
     fisSat.close();
     cout << endl;

     cout << "Fisere binare: " << endl;
     cout << endl;
     angajat3.scriereInFisBin("angajati.bin");
     Angajat an1;
     an1.citireInFisBin("angajati.bin");
     cout << an1 << endl;
     cout << endl;
     firma2.scriereInFisBin("firme.bin");
     Firma fi1;
     fi1.scriereInFisBin("firme.bin");
     cout << fi1 << endl;


     cout << endl << endl << "====================================================================" << endl;
     cout << "MOSTENIRE" << endl << endl;
     Inginer ing;
     cout << ing.getDepartament() << endl;
     cout << ing.getVechimeInDomeniu() << endl;
     cout << ing.getAreFacultateTerminata() << endl;
     ing.setDepartament("ElectroTehnic");
     ing.setVechimeInDomeniu(3);
     ing.setAreFacultateTerminata(1);
     cout << ing << endl;

     Inginer ing1(41, "Mircea Alexandru", 28, 4500, "Magnetica", 4, 1);
     cout << ing1 << endl;

     Inginer ing2 = ing;
     cout << ing2 << endl;

     ing2 = ing1;
     cout << ing2 << endl;


     cout << "--------------------------------------------" << endl;
     cout << "--------------------------------------------" << endl;
     cout << "--------------------------------------------" << endl;
     cout << "MOSTENIRE" << endl << endl;
     Manager m;

     cout << m.getDepartamentManageriat() << endl;
     cout << m.getAniFunctie() << endl;
     cout << m.getNrSubordonati() << endl;

     m.setDepartamentManageriat("Marketing");
     m.setAniFunctie(2);
     m.setNrSubordonati(100);

     cout << m << endl;

     Manager m1(54, "Teodorescu Ema", 22, 8240, "IT", 3, 450);
     cout << m1 << endl;

     Manager m2 = m;
     cout << m2 << endl;

     m2 = m1;

     cout << m2 << endl;


     cout << "--------------------------------------------" << endl;
     cout << "--------------------------------------------" << endl;
     cout << "--------------------------------------------" << endl;
     CalculSalariu** vec = new CalculSalariu * [10];
     vec[0] = &angajat;
     vec[1] = &angajat1;
     vec[2] = &angajat2;
     vec[3] = &ing;
     vec[4] = &ing1;
     vec[5] = &ing2;
     vec[6] = &m;
     vec[7] = &m1;
     vec[8] = &m2;
     vec[9] = &angajat3;
     for (int i = 0; i < 10; i++) {
         cout << vec[i]->salariuLunar() << " lei" << endl;
     }
     cout << endl;

     FunctieInCampulMuncii** vecFunctii = new FunctieInCampulMuncii * [10];
     vecFunctii[0] = &angajat;
     vecFunctii[1] = &angajat1;
     vecFunctii[2] = &angajat2;
     vecFunctii[3] = &ing;
     vecFunctii[4] = &ing1;
     vecFunctii[5] = &ing2;
     vecFunctii[6] = &m;
     vecFunctii[7] = &m1;
     vecFunctii[8] = &m2;
     vecFunctii[9] = &angajat3;
     for (int i = 0; i < 10; i++) {
         cout << vecFunctii[i]->recunoasteGrad() << endl;
     }

 
}