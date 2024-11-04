#include "CarteAudio.h"

CarteAudio::CarteAudio(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate, double durata) : Carte(ISBN, titlu, numeAutor, anPublicare, disponibilitate), durata(durata) {}

double CarteAudio::calculPret() const {
    return durata * 10;
}

void CarteAudio::afisare() const {
    Carte::afisare();
    cout << "Durata filmului: " << durata  << "(minute)  , Pret: " << calculPret() << " lei\n";
}