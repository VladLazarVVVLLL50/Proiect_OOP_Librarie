#include "EBook.h"

EBook::EBook(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate, double dimensiuneFisier) : Carte(ISBN, titlu, numeAutor, anPublicare, disponibilitate), dimensiuneFisier(dimensiuneFisier) {}

double EBook::calculPret() const {
    return dimensiuneFisier * 1.5;
}

void EBook::afisare() const {
    Carte::afisare();
    cout << "Dimensiune Fisier: " << dimensiuneFisier  << "(MB)  , Pret: " << calculPret() << " lei\n";
}