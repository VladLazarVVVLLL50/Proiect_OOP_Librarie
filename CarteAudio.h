#ifndef CARTEAUDIO_H
#define CARTEAUDIO_H
#include "Carte.h"
#pragma once

class CarteAudio : public Carte {
    private:
        double durata;
    public:
        CarteAudio(const char* ISBN, const char* titlu, const char* numeAutor, int anPublicare, bool disponibilitate, double durata);

        double calculPret() const;

        void afisare() const;
};

#endif