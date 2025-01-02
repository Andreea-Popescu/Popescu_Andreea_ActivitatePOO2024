#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Bloc {
    string strada;
    int numar;
    int scari;
    int apartamente;
    int etaje;

    void citire() {
        cout << "Introduceti strada: ";
        getline(cin, strada);
        cout << "Introduceti numarul: ";
        cin >> numar;
        cout << "Introduceti numarul de scari: ";
        cin >> scari;
        cout << "Introduceti numarul de apartamente: ";
        cin >> apartamente;
        cout << "Introduceti numarul de etaje: ";
        cin >> etaje;
        cin.ignore(); 
    }

   
    void afisare() const {
        cout << "Blocul de pe strada " << strada
            << ", numarul " << numar
            << ", are " << scari << " scari, "
            << apartamente << " apartamente si "
            << etaje << " etaje." << endl;
    }
};

int main() {
    vector<Bloc*> blocuri(10);

    for (int i = 0; i < 10; ++i) {
        cout << "\nBlocul " << i + 1 << ":\n";
        blocuri[i] = new Bloc;
        blocuri[i]->citire();
    }

    cout << "\nAfisare informatii despre blocuri:\n";
    for (int i = 0; i < 10; ++i) {
        blocuri[i]->afisare();
    }

    for (int i = 0; i < 10; ++i) {
        delete blocuri[i];
    }

    return 0;
}
