#ifndef LIBRAR_H
#define LIBRAR_H
#include "Angajat.h"
#include "Comanda.h"
#include <thread>
#include <chrono>
#include <mutex>
#pragma once

class Librar : public Angajat {
    protected:
        string sectiuneResponsabilitate;

        int nrComenziGestionate;
        int sumaComenziGestionate;
        vector<Comanda*> comenziGestionate;
        vector <thread> threaduriActive;
        mutex mtx;

        
        
        
    
    public:
        Librar(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalariu, const string sectiuneResponsabilitate);

        ~Librar();

        void afisare() const;

        double calculSalariu() const;

        void setNrComenziGestionate(int nrComenziGestionate);

        int getNrComenziGestionate();

        int getSumaComenziGestionate();

        int getNrComenziGestionateInOData(string Data);

        void procesareComanda(Comanda* comanda);

        void joinThreaduriComplete();

   


};

#endif