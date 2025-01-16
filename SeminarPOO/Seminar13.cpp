#include <iostream>
#include <map>
#include <list>
using namespace std;

class Aliment {
	string nume;
	float pret;
public:
	Aliment() {
		this->nume = "Aliment";
		this->pret = 0;
	}
	Aliment(string nume, float pret) {
		this->nume = nume;
		this->pret = pret;
	}

	Aliment(const Aliment &a) {
		this->nume = a.nume;
		this->pret = a.pret;
	}

	void afisareDescriere() {
		cout << nume << " => " << pret << endl;
	}
};

int main() {
	map<string, float> preturi; // sorteaza crescator pt cheie si in ordine alfabetica
	preturi.insert(pair<string, float>("Lapte", 23));
	preturi.insert(pair<string, float>("Paine", 7));
	preturi.insert(pair<string, float>("Oua", 16));
	preturi.insert(pair<string, float>("Lapte", 35)); // nu va fi adaugat, cheia trb sa fie unica

	preturi["Lapte"] = 67; // modif pretul pt cheia "Lapte"

	map<string, float>::iterator it; // iterator
	it = preturi.begin();
	int suma = 0;
	while (it != preturi.end()) {
		suma += it->second;
		it++; // deplasare la urm elem
	}

	cout << "Suma: " << suma << endl; // afisam suma preturilor 

	// it trebuie reinitializat
	it = preturi.begin();
	// afisarea preturilor
	while (it != preturi.end()) {
		cout << it->first << "=>" << it->second << endl;
		it++;
	}

	cout << endl << "Lista: " << endl;

	list <Aliment> alimente;
	alimente.push_back(Aliment());
	alimente.push_back(Aliment("Lapte", 20));
	alimente.push_front(Aliment("Paine", 10));
	alimente.push_front(Aliment("Oua", 16));

	list<Aliment>::iterator iter = alimente.begin();
	while (iter != alimente.end()) {
		iter->afisareDescriere();
		iter++;
	}
	
	return 0;
}