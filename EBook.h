#ifndef EBOOK_H
#define EBOOK_H
#include "Carte.h"
#pragma once

class EBook : public Carte {
    private:
        double dimensiuneFisier;
        

    public:
        EBook(const string ISBN, const string titlu, const string numeAutor, int anPublicare, double dimensiuneFisier);

        double calculPret() const;

        void afisare() const;
};

#endif