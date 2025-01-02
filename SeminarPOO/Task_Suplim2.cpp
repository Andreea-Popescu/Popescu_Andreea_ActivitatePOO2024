#include <iostream>
#include <string>
using namespace std;

class Telefon {
public:
    string model;
    int nrTelefoane;
    string* variante;
    const string producator;
    static int TVA;
    float pret;

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

    static float calculeazaPretFinal(float pret) {
        return pret + (pret * TVA / 100);
    }
};

int Telefon::TVA = 2;

class Laptop {
public:
    string denumire;
    float* preturiVariante;
    static int TVAlaptop;
    const int anFabricatie;
    bool SOinclus;

    Laptop() : anFabricatie(2023) {
        denumire = "Laptop oarecare";
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

    static float calculeazaPretFinal(float pret) {
        return pret + (pret * TVAlaptop / 100);
    }
};

int Laptop::TVAlaptop = 4;

class PC {
public:
    string nume;
    static int TVAPC;
    const string placaVideo;
    int memRAM;
    int* spatiuStocare;

    PC() : placaVideo("GPU") {
        nume = "PC oarecare";
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

    static float calculeazaPretFinal(float pret) {
        return pret + (pret * TVAPC / 100);
    }
};

int PC::TVAPC = 6;

int main() {
    // Testare constructori prima clasa
    Telefon t1;
    cout << "Constructor implicit Telefon: " << t1.model << ", " << t1.producator << endl;

    Telefon t2("iPhone 14", 3, "Apple", 999.99);
    cout << "Constructor parametrizat Telefon: " << t2.model << ", " << t2.producator << ", pret: " << t2.pret << endl;

    Telefon t4("Pixel", "Google");
    cout << "Constructor parametrizat 2 Telefon: " << t4.model << ", " << t4.producator << endl;

    Telefon t3(t2);
    cout << "Constructor de copiere Telefon: " << t3.model << ", " << t3.producator << ", pret: " << t3.pret << endl;

    // Testare constructori a doua clasa
    Laptop l1;
    cout << "Constructor implicit Laptop: " << l1.denumire << ", " << l1.anFabricatie << endl;

    Laptop l2("Dell XPS", 2022, true, 2, 1499.99);
    cout << "Constructor parametrizat Laptop: " << l2.denumire << ", " << l2.anFabricatie << endl;

    Laptop l4("MacBook Pro", 2023);
    cout << "Constructor parametrizat 2 Laptop: " << l4.denumire << ", " << l4.anFabricatie << endl;

    Laptop l3(l2);
    cout << "Constructor de copiere Laptop: " << l3.denumire << ", " << l3.anFabricatie << endl;

    // Testare constructori a treia clasa
    PC p1;
    cout << "Constructor implicit PC: " << p1.nume << ", " << p1.placaVideo << endl;

    PC p2("Gaming PC", "RTX 4070 Ti", 16, 2, 1000);
    cout << "Constructor parametrizat PC: " << p2.nume << ", " << p2.placaVideo << ", RAM: " << p2.memRAM << endl;

    PC p4("Office PC", "Intel UHD Graphics");
    cout << "Constructor parametrizat 2 PC: " << p4.nume << ", " << p4.placaVideo << endl;

    PC p3(p2);
    cout << "Constructor de copiere PC: " << p3.nume << ", " << p3.placaVideo << endl;

    return 0;
}