#ifndef ASISTENTLIBRAR_H
#define ASISTENTLIBRAR_H
#include "Librar.h"
#pragma once

class AsistentLibrar : public Librar {
    private:
        int oreSuplimentare;
        

    public:
        AsistentLibrar(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalariu, const string sectiuneResponsabilitate, int oreSuplimentare);

        void afisare() const;

        double calculSalariu() const;

};

#endif