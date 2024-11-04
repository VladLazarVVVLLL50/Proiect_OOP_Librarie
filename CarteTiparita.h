#ifndef CARTETIPARITA_H
#define CARTETIPARITA_H
#include "Carte.h"
#pragma once

class CarteTiparita : Carte {
    private: 
        int nrPagini;
    
    public:
        CarteTiparita(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate, int nrPagini);

        double calculPret() const;

        void afisare() const;
};

#endif