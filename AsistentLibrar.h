#ifndef ASISTENTLIBRAR_H
#define ASISTENTLIBRAR_H
#include "Librar.h"
#pragma once

class AsistentLibrar : public Librar {
    private:
        int oreSuplimentare;
        int numarCartiAranjatePeZi;
        bool suportClienti;

    public:
        AsistentLibrar(int id, const char* nume, const char* prenume, const char* dataNasterii, const char* dataAngajarii, double coefSalariu, const char* sectiuneResponsabilitate, int experientaAni, int oreSuplimentare, int numarCartiAranjatePeZi, bool suportClienti);

        void afisare() const;

        double calculSalariu(int aniVechime) const;

};

#endif