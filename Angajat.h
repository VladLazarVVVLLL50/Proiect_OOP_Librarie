#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <iostream>
#include <string>
using namespace std;
#pragma once

class Angajat {
    protected:
        int id;
        int aniVechime;
        string nume;
        string prenume;
        string dataNasterii;
        string dataAngajarii;
        double coefSalariu;

    public:
        Angajat(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalariu);
        
        
        void setID(int ID);

        int getID();

        virtual ~Angajat();

        virtual void afisare() const;

        virtual double calculSalariu() const = 0; // Functie virtuala pentru calculul salariului ce va fi definita in clasele derivate.
};

#endif