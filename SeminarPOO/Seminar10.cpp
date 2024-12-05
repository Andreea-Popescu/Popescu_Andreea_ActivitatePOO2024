#include<iostream>
#include <string>
#include <fstream>
using namespace std;

class Cofetarie {
private:
	string nume;
	int nrAngajati;
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	Cofetarie operator=(const Cofetarie& c) {
		if (&c != this) {
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}

	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Cofetarie operator+(Cofetarie c)const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Cofetarie& operator+=(Cofetarie c) {
		*this = *this + c;
		return *this;
	}

	Cofetarie operator+(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	friend Cofetarie operator+(float salariu, Cofetarie c) {
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Are produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Adaos:" << this->adaos << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}
	// ! Citire si scriere in fisiere
	friend ofstream& operator<<(ofstream& out, Cofetarie cofetarie) {
		out << cofetarie.nume << endl;
		out << cofetarie.nrAngajati << endl;
		for (int i = 0; i < cofetarie.nrAngajati; i++) {
			out << cofetarie.salarii[i] << " ";
		}
		out << endl;
		out << (cofetarie.esteVegana ? "DA" : "NU") << endl;
		out << cofetarie.anDeschidere << endl;
		out << cofetarie.adaos << endl;

		return out;
	}
	friend ifstream& operator>>(ifstream& in, Cofetarie cofetarie) {

		in >> cofetarie.nume;
		in >> cofetarie.nrAngajati;
		if (cofetarie.salarii != NULL) {
			delete[] cofetarie.salarii;
		}
		cofetarie.salarii = new float[cofetarie.nrAngajati];
		for (int i = 0; i < cofetarie.nrAngajati; i++) {
			in >> cofetarie.salarii[i];
		}
		int an = 2016;
		in >> cofetarie.esteVegana;
		in >> an;
		in >> cofetarie.adaos;

		return in;
	}

	friend ostream& operator<<(ostream& out, const Cofetarie& cofetarie) {
		out << "Nume: " << cofetarie.nume << endl;
		out << "Nr angajati: " << cofetarie.nrAngajati << endl;
		out << "Salarii: ";
		for (int i = 0; i < cofetarie.nrAngajati; i++) {
			out << cofetarie.salarii[i] << " ";
		}
		out << endl;
		out << "Este vegana: " << (cofetarie.esteVegana ? "DA" : "NU") << endl;
		out << "An deschidere: " << cofetarie.anDeschidere << endl;
		out << "Adaos: " << cofetarie.adaos << endl;
		out << "TVA: " << cofetarie.TVA << endl;

		return out;
	}

	friend istream& operator>>(istream& in, Cofetarie& cofetarie) {
		cout << "Introduceti nume: " << endl;
		getline(in, cofetarie.nume);

		cout << "Introduceti nr angajati: " << endl;
		in >> cofetarie.nrAngajati;

		if (cofetarie.salarii != NULL) {
			delete[] cofetarie.salarii;
		}
		cofetarie.salarii = new float[cofetarie.nrAngajati];

		cout << "Introduceti salarii: " << endl;
		for (int i = 0; i < cofetarie.nrAngajati; i++) {
			cout << "Salariul " << i + 1 << " : ";
			in >> cofetarie.salarii[i];
		}
		cout << "Este vegana?  " << endl;
		in >> cofetarie.esteVegana;

		cout << "Introduceti adaos: " << endl;
		in >> cofetarie.adaos;

		return in;
	}

	explicit operator int() {
		return this->nrAngajati;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}


	bool operator<(Cofetarie c) {
		return this->nrAngajati < c.nrAngajati;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "Indexul este in afara limitelor";
		}
	}

};
int Cofetarie::TVA = 9;
class CofetarieOnline :public Cofetarie {
	char* site;
	int nrColaboratori;
public:
	CofetarieOnline() : Cofetarie() {
		this->site = NULL;
		this->nrColaboratori = 0;
	}


	CofetarieOnline(const char* site, int nrColaboratori, string nume, int nrAngajati, float* salarii, bool esteVegana, const int anDeschidere, float adaos)
		: Cofetarie(nume, nrAngajati, esteVegana, anDeschidere, adaos)
	{
		this->site = new char[strlen(site) + 1];
		strcpy_s(this->site, strlen(site) + 1, site);
		this->nrColaboratori = nrColaboratori;
		this->setNrAngajati(nrAngajati, salarii);
	}
	~CofetarieOnline() {
		if (this->site != NULL) {
			delete[] this->site;
		}
	}
	explicit operator int() {
		return this->nrColaboratori;
	}

	float getNrMediuAngajatiPerColaborator() {
		return (float)this->getNrAngajati() / this->nrColaboratori;
	}

	CofetarieOnline(const CofetarieOnline& co) : Cofetarie(co) {
		this->site = new char[strlen(co.site) + 1];
		strcpy_s(this->site, strlen(co.site) + 1, co.site);
		this->nrColaboratori = co.nrColaboratori;
	}

	CofetarieOnline operator=(const CofetarieOnline& co) {
		if (this != &co) {
			Cofetarie::operator=(co);
			if (this->site != NULL) {
				delete[] this->site;
			}
			this->site = new char[strlen(co.site) + 1];
			strcpy_s(this->site, strlen(co.site) + 1, co.site);
			this->nrColaboratori = co.nrColaboratori;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const CofetarieOnline& co) {
		out << (Cofetarie)co;
		out << "Site-ul cofetariei: " << co.site << endl;
		out << "Nr colaboratori: " << co.nrColaboratori << endl;
		return out;
	}
};
int main() {
	//ofstream fisier("Fisier.txt", ios::app); // app - adauga ob c1 langa celalalt
	////Cofetarie c("Delicii", 4, 1, 2004, 10);
	//float* vector = new float[4] {1000, 2000, 3000, 4000};
	////c.setNrAngajati(4, vector);
	////fisier << c; // scriere in fisier
	//Cofetarie c1("AnaPan", 5, 0, 2012, 5);
	//fisier << c1;
	//fisier.close(); // inchidere fisier
	ifstream fisier2("Fisier.txt", ios::in);
	Cofetarie c2;
	fisier2 >> c2;
	cout << c2;
	fisier2 >> c2;
	cout << c2;
}