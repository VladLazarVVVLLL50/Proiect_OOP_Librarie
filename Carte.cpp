#include "Carte.h"

Carte::Carte(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate) : anPublicare(anPublicare), disponibilitate(disponibilitate) {
    this->ISBN = new char[strlen(ISBN) + 1];
    strcpy(this->ISBN, ISBN);

    this->titlu = new char[strlen(titlu) + 1];
    strcpy(this->titlu, titlu);

    this->numeAutor = new char[strlen(numeAutor) + 1];
    strcpy(this->numeAutor, numeAutor);

}
        
Carte::Carte(const Carte& altaCarte) : anPublicare(altaCarte.anPublicare), disponibilitate(altaCarte.disponibilitate) {
    this->ISBN = new char[strlen(altaCarte.ISBN) + 1];
    strcpy(this->ISBN, altaCarte.ISBN);

    this->titlu = new char[strlen(altaCarte.titlu) + 1];
    strcpy(this->titlu, altaCarte.titlu);

    this->numeAutor = new char[strlen(altaCarte.numeAutor) + 1];
    strcpy(this->numeAutor, altaCarte.numeAutor);

}

Carte& Carte::operator=(const Carte& altaCarte) {
    if(this != &altaCarte) {
        this->anPublicare = altaCarte.anPublicare;
        this->disponibilitate = altaCarte.disponibilitate;

        delete[] ISBN;
        delete[] titlu;
        delete[] numeAutor;

        this->ISBN = new char[strlen(altaCarte.ISBN) + 1];
        strcpy(this->ISBN, altaCarte.ISBN);

        this->titlu = new char[strlen(altaCarte.titlu) + 1];
        strcpy(this->titlu, altaCarte.titlu);

        this->numeAutor = new char[strlen(altaCarte.numeAutor) + 1];
        strcpy(this->numeAutor, altaCarte.numeAutor);

    }
    return *this;
}

Carte::~Carte() {
    delete[] ISBN;
    delete[] titlu;
    delete[] numeAutor;
}


void Carte::afisare() const {
    cout << "ISBN: " << ISBN << ", Titlu: " << titlu << ", Autor: " << numeAutor  << ", An Publicare: " << anPublicare  << ", Disponibilitate: " << (disponibilitate ? "In stoc" : "Indisponibil") << "\n";
    
}



const char* Carte::getTitlu() const {
    return titlu;
}

const char* Carte::getNumeAutor() const {
    return numeAutor;

}