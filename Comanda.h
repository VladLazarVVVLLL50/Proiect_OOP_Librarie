#ifndef COMANDA_H
#define COMANDA_H
#include <vector>
#include <cstring>
#include "Carte.h"
#include "Angajat.h"

#pragma once

class Comanda {
    private:
        vector <Carte*> cartiComandate;
        string dataComanda;

    public:
        Comanda(const vector<Carte*>& cartiComandate, const string dataComanda);

        ~Comanda();

        double getValoareTotala() const;

        bool esteComandaPreaMare() const; //Restrictie maxim 5 carti per comanda

        string getDataComanada() const;

        void afisare() const;

        int getMarimeComanda() const;

        vector<Carte*> getCartiComandate() const;

};

#endif