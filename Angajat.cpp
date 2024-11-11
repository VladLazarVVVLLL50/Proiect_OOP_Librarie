#include "Angajat.h"


        
Angajat::Angajat(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalariu) :
id(id), aniVechime(aniVechime), nume(nume), prenume(prenume), dataNasterii(dataNasterii), dataAngajarii(dataAngajarii), coefSalariu(coefSalariu) {}

Angajat::~Angajat(){ }

void Angajat::afisare() const {
    cout << "ID: " << id <<", Ani vechime: " << aniVechime << ", Nume: " << nume << ", Prenume: " << prenume << '\n';
    cout << "Data nasterii: " << dataNasterii << '\n';
    cout << "Data angajarii: " << dataAngajarii << '\n';
}

void Angajat::setID(int ID) {
    this->id = ID;
}     

int Angajat::getID() {
    return this->id;
}