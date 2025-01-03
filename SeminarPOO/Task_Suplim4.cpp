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
    // Cei 4 operatori
    Telefon operator=(const Telefon& t) {
        if (&t != this) {
            this->model = t.model;
            this->nrTelefoane = t.nrTelefoane;
            if (this->variante != nullptr) {
                delete[] this->variante;
            }
            this->variante = new string[t.nrTelefoane];
            for (int i = 0; i < t.nrTelefoane; i++) {
                this->variante[i] = t.variante[i];
            }
            this->pret = t.pret;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Telefon& tel) {
        cout << "Introduceti model: " << endl;
        cin >> tel.model;

        cout << "Introduceti nr telefoane: " << endl;
        in >> tel.nrTelefoane;

        if (tel.variante != nullptr) {
            delete[] tel.variante;
        }
        tel.variante = new string[tel.nrTelefoane];

        cout << "Introduceti variante: " << endl;
        for (int i = 0; i < tel.nrTelefoane; i++) {
            cout << "Varianta " << i + 1 << " : ";
            in >> tel.variante[i];
        }
        cout << "Introduceti pret: " << endl;
        in >> tel.pret;

        return in;
    }

    friend ostream& operator<<(ostream& out, const Telefon& tel) {
        out << "Model: " << tel.model << endl;
        out << "Nr telefoane: " << tel.nrTelefoane << endl;
        out << "Variante: ";
        for (int i = 0; i < tel.nrTelefoane; i++) {
            out << tel.variante[i] << " ";
        }
        out << endl;
        out << "Producator: " << tel.producator << endl;
        out << "TVA: " << tel.TVA << endl;

        return out;
    }

    explicit operator int() {
        return this->nrTelefoane;
    }
    //
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
    int nrVariante;
public:
    Laptop() : anFabricatie(2023) {
        denumire = "Laptop Generic";
        preturiVariante = nullptr;
        SOinclus = false;
        nrVariante = 0;
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
        nrVariante = 0;
    }

    Laptop(const Laptop& l) : anFabricatie(l.anFabricatie) {
        denumire = l.denumire;
        SOinclus = l.SOinclus;
        nrVariante = l.nrVariante;
        if (l.preturiVariante != nullptr) {
            preturiVariante = new float[l.nrVariante];
            for (int i = 0; i < l.nrVariante; i++) {
                preturiVariante[i] = l.preturiVariante[i];
            }
        }
        else {
            preturiVariante = nullptr;
        }
    }
    // Cei 4 operatori
    Laptop operator=(const Laptop& l) {
        if (this != NULL) {
            this->denumire = l.denumire;
            this->nrVariante = l.nrVariante;
            if (this->preturiVariante != nullptr) {
                delete[] this->preturiVariante;
            }
            this->preturiVariante = new float[l.nrVariante];
            for (int i = 0; i < l.nrVariante; i++) {
                this->preturiVariante[i] = l.preturiVariante[i];
            }
            this->SOinclus = l.SOinclus;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Laptop& lap) {
        cout << "Introduceti denumire: " << endl;
        cin >> lap.denumire;

        cout << "Introduceti nr variante: " << endl;
        in >> lap.nrVariante;

        if (lap.preturiVariante != nullptr) {
            delete[] lap.preturiVariante;
        }
        lap.preturiVariante = new float[lap.nrVariante];

        cout << "Introduceti Preturile: " << endl;
        for (int i = 0; i < lap.nrVariante; i++) {
            cout << "Pretul " << i + 1 << " : ";
            in >> lap.preturiVariante[i];
        }
        cout << "SO inclus (0 sau 1): " << endl;
        in >> lap.SOinclus;

        return in;
    }

    friend ostream& operator<<(ostream& out, const Laptop& lap) {
        out << "Denumire: " << lap.denumire << endl;
        out << "Nr variante: " << lap.nrVariante << endl;
        out << "Preturi: ";
        for (int i = 0; i < lap.nrVariante; i++) {
            out << lap.preturiVariante[i] << " ";
        }
        out << endl;
        out << "TVA: " << lap.TVAlaptop << endl;
        out << "SO inclus: " << (lap.SOinclus?"DA":"NU") << endl;
        out << "An fabricatie: " << lap.anFabricatie << endl;

        return out;
    }

    explicit operator float() {
        float s = 0;
        for (int i = 0; i < this->nrVariante; i++) {
            s += this->preturiVariante[i];
        }
        return s;
    }
    //
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
    int nrDispozitiveStocare;
public:
    PC() : placaVideo("Generic GPU") {
        nume = "PC Generic";
        memRAM = 8;
        spatiuStocare = nullptr;
        nrDispozitiveStocare = 1;
    }

    PC(string num, string gpu, int ram, int capacitate, int nrDispoz) : placaVideo(gpu) {
        nume = num;
        memRAM = ram;
        nrDispozitiveStocare = nrDispoz;
        if (nrDispoz > 0) {
            spatiuStocare = new int[nrDispoz];
            for (int i = 0; i < nrDispoz; i++) {
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
        nrDispozitiveStocare = 1;
    }

    PC(const PC& p) : placaVideo(p.placaVideo) {
        nume = p.nume;
        memRAM = p.memRAM;
        nrDispozitiveStocare = p.nrDispozitiveStocare;
        if (p.spatiuStocare != nullptr) {
            spatiuStocare = new int[p.nrDispozitiveStocare];
            for (int i = 0; i < p.nrDispozitiveStocare; i++) {
                spatiuStocare[i] = p.spatiuStocare[i];
            }
        }
        else {
            spatiuStocare = nullptr;
        }
    }
    // Cei 4 operatori
    PC operator=(const PC& p) {
        if (this != NULL) {
            this->nume = p.nume;
            this->memRAM = p.memRAM;
            this->nrDispozitiveStocare = p.nrDispozitiveStocare;
            if (this->spatiuStocare != nullptr) {
                delete[] this->spatiuStocare;
            }
            this->spatiuStocare = new int[p.nrDispozitiveStocare];
            for (int i = 0; i < p.nrDispozitiveStocare; i++) {
                this->spatiuStocare[i] = p.spatiuStocare[i];
            }
        }
        return *this;
    }

    bool operator<(PC p) {
        return this->memRAM < p.memRAM;
    }

    friend PC operator+(int spatiu, PC p) {
        PC temp = p;
        if (temp.spatiuStocare != nullptr) {
            delete[]temp.spatiuStocare;
        }
        temp.spatiuStocare = new int[temp.nrDispozitiveStocare + 1];
        for (int i = 0; i < p.nrDispozitiveStocare; i++) {
            temp.spatiuStocare[i] = p.spatiuStocare[i];
        }
        temp.spatiuStocare[temp.nrDispozitiveStocare] = spatiu;
        temp.nrDispozitiveStocare++;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const PC& p) {
        out << "Nume: " << p.nume << endl;
        out << "TVA PC: " << p.TVAPC << endl;
        out << "Spatiu stocare: ";
        if (p.spatiuStocare != nullptr && p.nrDispozitiveStocare > 0) {
            for (int i = 0; i < p.nrDispozitiveStocare; i++) {
                out << p.spatiuStocare[i] << " ";
            }
        }
        else {
            out << "N/A";
        }
        out << endl;
        out << "Placa Video: " << p.placaVideo << endl;
        out << "Memorie RAM: " << p.memRAM << " GB" << endl;

        return out;
    }

    //
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
    Telefon t1;
    cin >> t1;
    cout << t1;
    Telefon t2 = t1;
    cout << endl << t2;

    PC p1;
    cout << p1;

    Laptop l1;
    cin >> l1;
    cout << l1;

    float preturitotale = (float)l1;
    return 0;
}