#ifndef EBOOK_H
#define EBOOK_H
#include "Carte.h"
#pragma once

class EBook : public Carte {
    private:
        double dimensiuneFisier;

    public:
        EBook(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate, double dimensiuneFisier);

        double calculPret() const;

        void afisare() const;
};

#endif