#include "AsistentLibrar.h"

AsistentLibrar::AsistentLibrar(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii, double coefSalariu, const char* sectiuneResponsabilitate, int experientaAni, int oreSuplimentare, int numarCartiAranjatePeZi, bool suportClienti) : Librar(id,nume,prenume,dataNasterii,dataAngajarii,coefSalariu,sectiuneResponsabilitate,experientaAni), oreSuplimentare(oreSuplimentare), numarCartiAranjatePeZi(numarCartiAranjatePeZi), suportClienti(suportClienti){
    this->coefSalariu = 1.5;
}

void AsistentLibrar::afisare() const {
    cout << "Asistent ";
    Librar::afisare();
    cout << "Ore suplimentare: " << oreSuplimentare <<", Numar carti aranjate pe zi:" << numarCartiAranjatePeZi << "Suport clienti: ";
    if(suportClienti){
        cout << "Da";
    } else {
        cout << "Nu";
    }
    cout << '\n';
}

double AsistentLibrar::calculSalariu(int aniVechime) const {
        return (aniVechime * coefSalariu * 1500) + (oreSuplimentare * 20); 
}
