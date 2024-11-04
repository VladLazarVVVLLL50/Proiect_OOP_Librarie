#include "Manager.h"

Manager::Manager(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii, double coefSalaru, const char* departament, int numarAngajatiSupervizati, double bonus) : Angajat(id, nume, prenume, dataNasterii, dataAngajarii, 3.0), numarAngajatiSupervizati(numarAngajatiSupervizati), bonus(bonus) {
    this->departament = new char[strlen(departament) + 1];
    strcpy(this->departament, departament);

} 

Manager::Manager(const Manager& altManager) : Angajat(altManager.id, altManager.nume, altManager.prenume, altManager.dataNasterii, altManager.dataAngajarii, 3.0), numarAngajatiSupervizati(altManager.numarAngajatiSupervizati), bonus(altManager.bonus) {
    this->departament = new char[strlen(altManager.departament) + 1];
    strcpy(this->departament, altManager.departament);

}

Manager& Manager::operator=(const Manager& altManager){
    if(this != &altManager){
        delete[] this->departament;
        this->departament = new char[strlen(departament) + 1];
        strcpy(this->departament, altManager.departament);
        this->numarAngajatiSupervizati = altManager.numarAngajatiSupervizati;
        this->bonus = altManager.bonus;
        Angajat::operator=(altManager);
    }
    return *this;
}

Manager::~Manager() {
    delete[] departament;
}

void Manager::afisare() const {
    cout << "Manager: " << '\n';
    Angajat::afisare();
    cout << "Departament: " << departament <<", Numar angajat supervizati: " << numarAngajatiSupervizati <<", Bonus:  " << bonus << '\n';
}

double Manager::calculSalariu(int aniVechime) const {
    return (aniVechime * coefSalariu * 1500) + bonus;
}