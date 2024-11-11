#ifndef CARTETIPARITA_H
#define CARTETIPARITA_H
#include "Carte.h"
#pragma once

class CarteTiparita : public Carte {
    private: 
        int nrPagini;
        int numarExemplare;
    
    public:
        CarteTiparita(const string ISBN, const string titlu, const string numeAutor, int anPublicare, int nrPagini, int numarExemplare);

        double calculPret() const;

        void afisare() const;

        void plusNumarExemplare();

        void minusNumarExemplare();

        int getNumarExemplare();

};

#endif