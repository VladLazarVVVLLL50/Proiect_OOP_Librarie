#include "Librar.h"

Librar::Librar(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii, double coefSalariu, const char* sectiuneResponsabilitate, int experientaAni) : Angajat(id, nume, prenume, dataNasterii, dataAngajarii, 2.0), experientaAni(experientaAni) {
    this->sectiuneResponsabilitate = new char[strlen(sectiuneResponsabilitate) + 1];
    strcpy(this->sectiuneResponsabilitate, sectiuneResponsabilitate);
}

Librar::Librar(const Librar& altManager) : Angajat(altManager.id, altManager.nume, altManager.prenume, altManager.dataNasterii, altManager.dataAngajarii, 2.0), experientaAni(altManager.experientaAni) {
    this->sectiuneResponsabilitate = new char[strlen(altManager.sectiuneResponsabilitate) + 1];
    strcpy(this->sectiuneResponsabilitate, altManager.sectiuneResponsabilitate);
}

Librar& Librar::operator=(const Librar& altManager) {
    if(this != &altManager){
        delete[] sectiuneResponsabilitate;
        this->sectiuneResponsabilitate = new char[strlen(altManager.sectiuneResponsabilitate) + 1];
        strcpy(this->sectiuneResponsabilitate, altManager.sectiuneResponsabilitate);
        this->experientaAni = altManager.experientaAni;
        Angajat::operator=(altManager);
    }
    return *this;
}

Librar::~Librar(){
    delete[] sectiuneResponsabilitate;
}

void Librar::afisare() const {
    cout << "Librar:" << '\n';
    Angajat::afisare();
    cout <<  "Responsabilitate: " << sectiuneResponsabilitate << ", Experienta (ani): " << experientaAni << '\n';
}

double Librar::calculSalariu(int aniVechime) const {
    return aniVechime * coefSalariu * 1500;
}