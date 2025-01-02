#include <iostream>
#include <string>
using namespace std;

class Telefon {
private:
    string model;
    int nrTelefoane;
    string* variante;
    const string producator;
    static int TVA;
    float pret;
public:
    Telefon() : producator("Samsung") {
        this->model = "Z7";
        this->nrTelefoane = 0;
        this->variante = nullptr;
        this->pret = 0;
    }

    Telefon(string mod, int nrTel, string prod, float p) : producator(prod) {
        model = mod;
        nrTelefoane = nrTel;
        pret = p;
        if (nrTelefoane > 0) {
            variante = new string[nrTelefoane];
            for (int i = 0; i < nrTelefoane; i++) {
                variante[i] = "a";
            }
        }
        else {
            variante = nullptr;
        }
    }

    Telefon(string mod, string prod) : producator(prod) {
        model = mod;
        nrTelefoane = 0;
        variante = nullptr;
        pret = 0;
    }

    Telefon(const Telefon& t) : producator(t.producator) {
        this->model = t.model;
        this->nrTelefoane = t.nrTelefoane;
        if (t.nrTelefoane > 0) {
            this->variante = new string[t.nrTelefoane];
            for (int i = 0; i < t.nrTelefoane; i++) {
                this->variante[i] = t.variante[i];
            }
        }
        else {
            this->variante = nullptr;
        }
        this->pret = t.pret;
    }

    ~Telefon() {
        delete[] variante;
    }

    static float calculeazaPretFinal(float pret) {
        return pret + (pret * TVA / 100);
    }

    string getModel() const { return model; }
    void setModel(const string& mod) { model = mod; }

    int getNrTelefoane() const { return nrTelefoane; }
    void setNrTelefoane(int nrTel) { nrTelefoane = nrTel; }

    float getPret() const { return pret; }
    void setPret(float p) { pret = p; }

    static int getTVA() { return TVA; }
    static void setTVA(int tva) { TVA = tva; }
};

int Telefon::TVA = 2;

class Laptop {
private:
    string denumire;
    float* preturiVariante;
    static int TVAlaptop;
    const int anFabricatie;
    bool SOinclus;
public:
    Laptop() : anFabricatie(2023) {
        denumire = "Laptop Generic";
        preturiVariante = nullptr;
        SOinclus = false;
    }

    Laptop(string den, int an, bool so, int nrVariante, float pretInitial) : anFabricatie(an) {
        denumire = den;
        SOinclus = so;
        if (nrVariante > 0) {
            preturiVariante = new float[nrVariante];
            for (int i = 0; i < nrVariante; i++) {
                preturiVariante[i] = pretInitial;
            }
        }
        else {
            preturiVariante = nullptr;
        }
    }

    Laptop(string den, int an) : anFabricatie(an) {
        denumire = den;
        preturiVariante = nullptr;
        SOinclus = false;
    }

    Laptop(const Laptop& l) : anFabricatie(l.anFabricatie) {
        denumire = l.denumire;
        SOinclus = l.SOinclus;
        if (l.preturiVariante != nullptr) {
            preturiVariante = new float[sizeof(l.preturiVariante) / sizeof(float)];
            for (int i = 0; i < sizeof(l.preturiVariante) / sizeof(float); i++) {
                preturiVariante[i] = l.preturiVariante[i];
            }
        }
        else {
            preturiVariante = nullptr;
        }
    }

    ~Laptop() {
        delete[] preturiVariante;
    }

    static float calculeazaPretFinal(float pret) {
        return pret + (pret * TVAlaptop / 100);
    }

    string getDenumire() const { return denumire; }
    void setDenumire(const string& den) { denumire = den; }

    bool getSOinclus() const { return SOinclus; }
    void setSOinclus(bool so) { SOinclus = so; }

    static int getTVAlaptop() { return TVAlaptop; }
    static void setTVAlaptop(int tva) { TVAlaptop = tva; }
};

int Laptop::TVAlaptop = 4;

class PC {
private:
    string nume;
    static int TVAPC;
    const string placaVideo;
    int memRAM;
    int* spatiuStocare;
public:
    PC() : placaVideo("Generic GPU") {
        nume = "PC Generic";
        memRAM = 8;
        spatiuStocare = nullptr;
    }

    PC(string num, string gpu, int ram, int nrDiscuri, int capacitate) : placaVideo(gpu) {
        nume = num;
        memRAM = ram;
        if (nrDiscuri > 0) {
            spatiuStocare = new int[nrDiscuri];
            for (int i = 0; i < nrDiscuri; i++) {
                spatiuStocare[i] = capacitate;
            }
        }
        else {
            spatiuStocare = nullptr;
        }
    }

    PC(string num, string gpu) : placaVideo(gpu) {
        nume = num;
        memRAM = 8;
        spatiuStocare = nullptr;
    }

    PC(const PC& p) : placaVideo(p.placaVideo) {
        nume = p.nume;
        memRAM = p.memRAM;
        if (p.spatiuStocare != nullptr) {
            spatiuStocare = new int[sizeof(p.spatiuStocare) / sizeof(int)];
            for (int i = 0; i < sizeof(p.spatiuStocare) / sizeof(int); i++) {
                spatiuStocare[i] = p.spatiuStocare[i];
            }
        }
        else {
            spatiuStocare = nullptr;
        }
    }

    ~PC() {
        delete[] spatiuStocare;
    }

    static float calculeazaPretFinal(float pret) {
        return pret + (pret * TVAPC / 100);
    }

    string getNume() const { return nume; }
    void setNume(const string& num) { nume = num; }

    int getMemRAM() const { return memRAM; }
    void setMemRAM(int ram) { memRAM = ram; }

    static int getTVAPC() { return TVAPC; }
    static void setTVAPC(int tva) { TVAPC = tva; }
};

int PC::TVAPC = 6;

float calculeazaTVAMedie(const Telefon& t, const Laptop& l) {
    return (t.calculeazaPretFinal(1000) + l.calculeazaPretFinal(1500)) / 2;
}

void afiseazaDetaliiPC(const PC& pc) {
    cout << "PC: " << pc.getNume() << ", RAM: " << pc.getMemRAM() << " GB, TVA: " << PC::getTVAPC() << "%" << endl;
}

int main() {
    // Testare get-eri si set-eri
    Telefon t1;
    t1.setModel("Alpha");
    cout << t1.getModel() << endl;

    Laptop l1;
    l1.setSOinclus(0);
    cout << l1.getSOinclus() << endl;

    PC p1;
    p1.setMemRAM(64);
    cout << p1.getMemRAM() << endl;

    // Testare functii statice
    p1.setTVAPC(10);
    cout << p1.getTVAPC() << endl;

    // Testare functii globale
    calculeazaTVAMedie(t1, l1);
    afiseazaDetaliiPC(p1);
}