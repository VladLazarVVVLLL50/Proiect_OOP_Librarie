#ifndef LIBRAR_H
#define LIBRAR_H
#include "Angajat.h"
#pragma once

class Librar : public Angajat {
    protected:
        char* sectiuneResponsabilitate;
        int experientaAni;
    
    public:
        Librar(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii, double coefSalariu, const char* sectiuneResponsabilitate, int experientaAni);

        Librar(const Librar& altManager);

        Librar& operator=(const Librar& altManager);

        ~Librar();

        void afisare() const;

        double calculSalariu(int aniVechime) const;

   


};

#endif