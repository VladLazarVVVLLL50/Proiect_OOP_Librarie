#include "CarteTiparita.h"

CarteTiparita::CarteTiparita(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate, int nrPagini) : Carte(ISBN, titlu, numeAutor, anPublicare, disponibilitate), nrPagini(nrPagini) {}

double CarteTiparita::calculPret() const {
    return nrPagini * 0.2;
}

void CarteTiparita::afisare() const {
    Carte::afisare();
    cout << "Numar pagini: " << nrPagini  << ", Pret: " << calculPret() << " lei\n";
}