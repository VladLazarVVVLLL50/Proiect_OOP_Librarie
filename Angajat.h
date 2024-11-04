#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <iostream>
#include "string.h"
using namespace std;
#pragma once

class Angajat {
    protected:
        int id;
        char* nume;
        char* prenume;
        char* dataNasterii;
        char* dataAngajarii;
        double coefSalariu;

    public:
        Angajat(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii, double coefSalariu);
        
        Angajat(const Angajat& altAngajat);

        Angajat& operator=(const Angajat& altAngajat);

        virtual ~Angajat();

        virtual void afisare() const;

        virtual double calculSalariu(int aniVechime) const = 0; // Functie virtuala pentru calculul salariului ce va fi definita in clasele derivate.
};

#endif