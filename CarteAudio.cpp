#include "CarteAudio.h"

CarteAudio::CarteAudio(const string ISBN, const string titlu, const string numeAutor, int anPublicare, double durata) : Carte(ISBN, titlu, numeAutor, anPublicare), durata(durata) {}

double CarteAudio::calculPret() const {
    return durata * 10;
}

void CarteAudio::afisare() const {
    Carte::afisare();
    cout << "Durata cartii: " << durata << "(minute), Pret: " << calculPret() << " lei \n";
}