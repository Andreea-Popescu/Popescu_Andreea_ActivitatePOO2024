#include <iostream>
using namespace std;

class Cofetarie {
private:
	string denumire;
	int nrAngajati;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;
	float* salarii;
public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->denumire = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string denumire, int nrAngajati, bool esteVegana, int anDeschidere, float adaos) :anDeschidere(anDeschidere) {
		this->denumire = denumire;
		this->nrAngajati = nrAngajati;
		this->esteVegana = esteVegana;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}

	Cofetarie(const Cofetarie &c): anDeschidere(c.anDeschidere) {
		this->denumire = c.denumire;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	// ^ Constr. de copiere

	~Cofetarie() {
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->denumire;
	}

	void setNume(string denumire) {
		if (denumire.length() > 2) {
			this->denumire = denumire;
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
			for (int i = 0; i < this->nrAngajati;i++) {
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

	void afisare() {
		cout << "Nume: " << this->denumire << endl;
		cout << "Nr angajati: " << this->nrAngajati << endl;
		cout << "Este vegana?  " << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << Cofetarie::TVA << endl; 
	}

	static void modificaTVA(int noulTVA) 
	{
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA; 
		}
	}

	static int calculeazaTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}

	
};

int Cofetarie::TVA = 9; 


int main() {

	Cofetarie c;
	cout << c.getNume() << endl;
	c.setNume("");
	cout << c.getNume() << endl;
	c.setNume("Alt nume");
	cout << c.getNume() << endl;

	c.setNrAngajati(4, new float[4] {2,6,4,9});

	Cofetarie c2("Minimal", 3, false, 2020, 10);
	cout << c2.getSalarii()[1] << endl;
	// Exterior ^ Interior v
	cout << c2.getSalariu(1) << endl;

	c2.setNrAngajati(5, new float[5] {1,2,3,4,5}); 
	cout << c2.getSalariu(4);

	Cofetarie c3 = c2; // Apelare constr. de copiere
}