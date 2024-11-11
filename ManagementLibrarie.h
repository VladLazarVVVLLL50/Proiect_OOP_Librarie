#ifndef MANAGEMENTLIBRARIE_H
#define MANAGEMENTLIBRARIE_H
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Angajat.h"
#include "Librar.h"
#include "Carte.h"
#include "CarteTiparita.h"
#include "CarteAudio.h"
#include "EBook.h"
#include "Comanda.h"

#pragma once

class ManagementLibrarie {
    private:
        vector<Carte*> carti;
        vector<Angajat*> angajati;
        vector<Comanda*> comenziProcesate;
        queue<Comanda*> comenziInAsteptare;

    public:
        ManagementLibrarie() = default;
        ~ManagementLibrarie();

        //Metode pentru a manipula angajati
        void adaugaAngajat(Angajat* angajat);
        void stergeAngajat(const int& id);
        void afiseazaAngajati() const;

        // Metode pentru a manipula carti
        void adaugaCarte(Carte* carte);
        void stergeCarte(Carte* carte);
        void afiseazaCarti() const; 

        //Metode pentru manipulare comenzi:
        void plaseazaComanda(Comanda* comanda);
        void proceseazaComenziInAsteptare();
        void afiseazaComenziProcesate() const;
        void afiseazaComenziInAsteptare() const;

        //Rapoarte:

        void topTreiAngajati();
        void celMaiProductivAngajatInData(string Data);


    
};

#endif