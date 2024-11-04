#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <cstring>
using namespace std;
#pragma once

class Carte {
    protected:
        char* ISBN;
        char* titlu;
        char* numeAutor;
        int anPublicare;
        bool disponibilitate;
    
    public:
        Carte(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate);
        
        Carte(const Carte& altaCarte);

        Carte& operator=(const Carte& altaCarte);

        virtual ~Carte();
        // Metoda virtuala pentru calculul pretului a diferitelor tipuri de carti.
        virtual double calculPret() const = 0;

        virtual void afisare() const;

        const char* getTitlu() const;

        const char* getNumeAutor() const;
};

#endif