#include "Manager.h"

Manager::Manager(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalaru, const string departament, int numarAngajatiSupervizati, double bonus) : 
Angajat(id, aniVechime, nume, prenume, dataNasterii, dataAngajarii, 3.0), departament(departament), numarAngajatiSupervizati(numarAngajatiSupervizati), bonus(bonus) {} 

Manager::~Manager() {}

void Manager::afisare() const {
    cout << "Manager: " << '\n';
    Angajat::afisare();
    cout << "Departament: " << departament <<", Numar angajat supervizati: " << numarAngajatiSupervizati <<", Bonus:  " << bonus << '\n';
}

double Manager::calculSalariu() const {
    return (aniVechime * coefSalariu * 1500) + bonus;
}