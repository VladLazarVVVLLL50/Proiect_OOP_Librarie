#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <string>
using namespace std;
#pragma once

class Carte {
    protected:
        string ISBN;
        string titlu;
        string numeAutor;
        int anPublicare;
        
        
    public:
        Carte(const string ISBN, const string titlu, const string numeAutor, int anPublicare);
        
        virtual ~Carte();
        // Metoda virtuala pentru calculul pretului a diferitelor tipuri de carti.
        virtual double calculPret() const = 0;

        virtual void afisare() const;

        const string getTitlu() const;

        const string getNumeAutor() const;

        const string getISBN() const;
};

#endif