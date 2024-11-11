#include "Comanda.h"

Comanda::Comanda(const vector<Carte*>& cartiComandate, const string dataComanda) : cartiComandate(cartiComandate),  dataComanda(dataComanda) {}



Comanda::~Comanda() {}



double Comanda::getValoareTotala() const {
    double vloareTotala = 0;
    for(vector<Carte*>::const_iterator it = cartiComandate.begin(); it != cartiComandate.end(); ++it) {
        vloareTotala += (*it)->calculPret();
    }
    return vloareTotala;
}

bool Comanda::esteComandaPreaMare() const {
    return cartiComandate.size() > 5;

}

string Comanda::getDataComanada() const {
    return dataComanda;
}

void Comanda::afisare() const {
    cout << "Comanda de la data: " << dataComanda <<'\n';
    for(const auto& it : cartiComandate){
        it->afisare();
    }

}

int Comanda::getMarimeComanda() const {
    return this->cartiComandate.size();
}

vector<Carte*> Comanda::getCartiComandate() const {
    return cartiComandate;
}