#include "CarteTiparita.h"

CarteTiparita::CarteTiparita(const string ISBN, const string titlu, const string numeAutor, int anPublicare, int nrPagini, int numarExemplare) : Carte(ISBN, titlu, numeAutor, anPublicare), nrPagini(nrPagini), numarExemplare(numarExemplare) {}

double CarteTiparita::calculPret() const {
    return nrPagini * 0.2;
}

void CarteTiparita::afisare() const {
    Carte::afisare();
    cout << "Numar pagini: " << nrPagini <<", Numar exemplare: " << numarExemplare << ", Pret: " << calculPret() << " lei\n";
}

void CarteTiparita::plusNumarExemplare() {
    numarExemplare ++;
}

void CarteTiparita::minusNumarExemplare() {
    numarExemplare --;
}

int CarteTiparita::getNumarExemplare() {
    return numarExemplare;
}