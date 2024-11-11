#include "EBook.h"

EBook::EBook(const string ISBN, const string titlu, const string numeAutor, int anPublicare, double dimensiuneFisier) : Carte(ISBN, titlu, numeAutor, anPublicare),  dimensiuneFisier(dimensiuneFisier) {}

double EBook::calculPret() const {
    return dimensiuneFisier * 1.5;
}

void EBook::afisare() const {
    
    Carte::afisare();
    cout << "Dimensiune Fisier: " << dimensiuneFisier  << "(MB)  , Pret: " << calculPret() << " lei \n";
}