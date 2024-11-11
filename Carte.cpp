#include "Carte.h"

Carte::Carte(const string ISBN, const string titlu, const string numeAutor, int anPublicare) : 
ISBN(ISBN), titlu(titlu), numeAutor(numeAutor), anPublicare(anPublicare) {}
        


Carte::~Carte() {}


void Carte::afisare() const {
    cout << "ISBN: " << ISBN << ", Titlu: " << titlu << ", Autor: " << numeAutor  << ", An Publicare: " << anPublicare << "\n";
    
}



const string Carte::getTitlu() const {
    return titlu;
}

const string Carte::getNumeAutor() const {
    return numeAutor;

}

const string Carte::getISBN() const {
    return ISBN;
}