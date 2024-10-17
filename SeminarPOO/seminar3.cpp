#include <iostream>
using namespace std;

class Cofetarie {
public:
	string denumire;
	int nrAngajati;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

	/*
	Cofetarie(string denumire = "Delice", int nrAngajati = 3, bool esteVegana = true, int anDeschidere = 2024, float adaos = 30) : 
	denumire(denumire), nrAngajati(nrAngajati), esteVegana(esteVegana), anDeschidere(anDeschidere), adaos(adaos) {};
	????
	*/

	Cofetarie(): adaos(30), anDeschidere(2024) { 
		this->denumire = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;
		
	}

	Cofetarie(string denumire, int nrAngajati, bool esteVegana, int anDeschidere, float adaos):anDeschidere(anDeschidere) {
		this->denumire = denumire;
		this->nrAngajati = nrAngajati;
		this->esteVegana = esteVegana;
		this->adaos = adaos;

	}

	void afisare() {
		cout << "Nume: " << this->denumire << endl;
		cout << "Nr angajati: " << this->nrAngajati << endl;
		cout << "Este vegana?  " << (this->esteVegana?"DA":"NU") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << Cofetarie::TVA << endl; // sau this->TVA
	}

	static void modificaTVA(int noulTVA) // daca era doar void era METODA, si foloseam pointerul this->!!!!
	{
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA; // Atribut STATIC, deci il accesam prin intermediul CLASEI
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

int Cofetarie::TVA = 9; // declarat global


int main() {

	Cofetarie c1;
	c1.afisare();

	Cofetarie::modificaTVA(19);

	Cofetarie c2("DolceVita", 6, false, 2019, 10);
	c2.afisare();

	Cofetarie* pointer;
	pointer = new Cofetarie("Ana State", 3, false, 2020, 20);
	pointer->afisare(); // -> - Dereferentiere + Accesare
						// [] - Deplasare + Dereferentiere
	delete pointer;

	int nrCofetarii = 3;

	Cofetarie* vector;
	vector = new Cofetarie[nrCofetarii]; // bloc de memorie, pt cele 3 cofetarii

	for (int i = 0; i < nrCofetarii; i++) {
		vector[i].afisare();
	}

	cout << "Numar total angajati: " << Cofetarie::calculeazaTotalAngajati(nrCofetarii, vector);
	delete[]vector;
	return 0;
}