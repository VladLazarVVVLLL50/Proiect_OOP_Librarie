#ifndef MANAGER_H
#define MANAGER_H
#include "Angajat.h"
#pragma once

class Manager : public Angajat {
    private:
        string departament;
        int numarAngajatiSupervizati;
        double bonus;
    public:
        Manager(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalariu, const string departament, int numarAngajatiSupervizati, double bonus);

        ~Manager();

        void afisare() const;

        double calculSalariu() const;

        

};

#endif