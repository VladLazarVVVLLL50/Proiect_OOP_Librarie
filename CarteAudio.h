#ifndef CARTEAUDIO_H
#define CARTEAUDIO_H
#include "Carte.h"
#pragma once

class CarteAudio : public Carte {
    private:
        double durata;
        
    public:
        CarteAudio(const string ISBN, const string titlu, const string numeAutor, int anPublicare, double durata);

        double calculPret() const;

        void afisare() const;
};

#endif