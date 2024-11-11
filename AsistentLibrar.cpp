#include "AsistentLibrar.h"

 AsistentLibrar::AsistentLibrar(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalariu, const string sectiuneResponsabilitate, int oreSuplimentare) :
 Librar(id, aniVechime, nume, prenume, dataAngajarii, dataAngajarii, coefSalariu, sectiuneResponsabilitate), oreSuplimentare(oreSuplimentare) {}


void AsistentLibrar::afisare() const {
    cout << "Asistent ";
    Librar::afisare();
    cout << "Ore suplimentare: " << oreSuplimentare << "Suport clienti: ";
    
    cout << '\n';
}

double AsistentLibrar::calculSalariu() const {
        return (aniVechime * coefSalariu * 1500) + (oreSuplimentare * 20); 
}
