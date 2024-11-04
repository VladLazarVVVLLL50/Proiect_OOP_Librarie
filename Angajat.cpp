#include "Angajat.h"

Angajat::Angajat(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii, double coefSalariu) : id(id), coefSalariu(coefSalariu) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);

    this->dataNasterii = new char[strlen(dataNasterii) + 1];
    strcpy(this->dataNasterii, dataNasterii);

    this->dataAngajarii = new char[strlen(dataAngajarii) + 1];
    strcpy(this->dataAngajarii, dataAngajarii);
}
        
Angajat::Angajat(const Angajat& altAngajat) : id(altAngajat.id), coefSalariu(altAngajat.coefSalariu) {
    this->nume = new char[strlen(altAngajat.nume) + 1];
    strcpy(this->nume, altAngajat.nume);

    this->prenume = new char[strlen(altAngajat.prenume) + 1];
    strcpy(this->prenume, altAngajat.prenume);

    this->dataNasterii = new char[strlen(altAngajat.dataNasterii) + 1];
    strcpy(this->dataNasterii, altAngajat.dataNasterii);

    this->dataAngajarii = new char[strlen(altAngajat.dataAngajarii) + 1];
    strcpy(this->dataAngajarii, altAngajat.dataAngajarii);
}

Angajat& Angajat::operator=(const Angajat& altAngajat) {
    

    if(this != &altAngajat){
        this->id = altAngajat.id;
        this->coefSalariu = altAngajat.coefSalariu;
       
        delete[] this->nume;
        delete[] this->prenume;
        delete[] this->dataNasterii;
        delete[] this->dataAngajarii;

        this->nume = new char[strlen(altAngajat.nume) + 1];
        strcpy(this->nume, altAngajat.nume);
        
        this->prenume = new char[strlen(altAngajat.prenume) + 1];
        strcpy(this->prenume, altAngajat.prenume);
        
        this->dataNasterii = new char[strlen(altAngajat.dataNasterii) + 1];
        strcpy(this->dataNasterii, altAngajat.dataNasterii);
        
        this->dataAngajarii = new char[strlen(altAngajat.dataAngajarii) + 1];
        strcpy(this->dataAngajarii, altAngajat.dataAngajarii);

    }
    return *this;

}

Angajat::~Angajat(){
    delete[] this->nume;
    delete[] this->prenume;
    delete[] this->dataNasterii;
    delete[] this->dataAngajarii;

}
void Angajat::afisare() const {
    cout << "ID: " << id << ", Nume: " << nume << ", Prenume: " << prenume << '\n';
    cout << "Data nasterii: " << dataNasterii << '\n';
    cout << "Data angajarii: " << dataAngajarii << '\n';
}

        