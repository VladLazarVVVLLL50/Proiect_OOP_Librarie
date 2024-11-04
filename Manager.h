#ifndef MANAGER_H
#define MANAGER_H
#include "Angajat.h"
#pragma once

class Manager : public Angajat {
    private:
        char* departament;
        int numarAngajatiSupervizati;
        double bonus;
    public:
        Manager(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii,double coefSalariu, const char* departament, int numarAngajatiSupervizati, double bonus);

        Manager(const Manager& altManager);

        Manager& operator=(const Manager& altManager);

        ~Manager();

        void afisare() const;

        double calculSalariu(int aniVechime) const;

};

#endif