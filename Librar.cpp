#include "Librar.h"

Librar::Librar(int id, int aniVechime, const string nume, const string prenume, const string dataNasterii, const string dataAngajarii, double coefSalariu, const string sectiuneResponsabilitate) :
Angajat(id, aniVechime, nume, prenume, dataNasterii, dataAngajarii, coefSalariu), sectiuneResponsabilitate(sectiuneResponsabilitate) {}


Librar::~Librar() {
    for(auto& thread : threaduriActive) {
        if(thread.joinable()) {
            thread.join();
        }
    }
}

void Librar::afisare() const {
    cout << "Librar:" << '\n';
    Angajat::afisare();
    cout <<  "Responsabilitate: " << sectiuneResponsabilitate  << '\n';
    
    
}

double Librar::calculSalariu() const {
    return aniVechime * coefSalariu * 1500;
}

void Librar::setNrComenziGestionate(int nrComenziGestionate) {
    this->nrComenziGestionate = nrComenziGestionate;

}


int Librar::getNrComenziGestionate(){
    return nrComenziGestionate;

}

int Librar::getSumaComenziGestionate(){
    return sumaComenziGestionate;

}

int Librar::getNrComenziGestionateInOData(string Data){
    int nr = 0;
    for(auto& it : comenziGestionate) {
        if(Data == it->getDataComanada()) {
            nr ++;
        }
    }

    return nr;
}

void Librar::procesareComanda(Comanda* comanda) {
    auto process = [this, comanda]() {
         nrComenziGestionate++;
        cout << "Librarul cu ID-ul " << this->id << "a inceput sa proceseze comanda \n";
        this_thread::sleep_for(chrono::seconds(comanda->getMarimeComanda() * 10));
        cout << "Librarul cu ID-ul " << this->id << "a terminat de procesat comanda \n";

        lock_guard<mutex> lock(mutex);        
        nrComenziGestionate--;
        comenziGestionate.push_back(comanda);
    };
    lock_guard<mutex> lock(mutex);
    if(threaduriActive.size() < 3) {
        threaduriActive.emplace_back(process);
        joinThreaduriComplete();
    } else {
        cout << "Librarul cu ID-ul " << this->id << " a ajuns la limita maxima de comenzi gestionate in paralel. \n";
    }

}

 void Librar::joinThreaduriComplete() {
   for( auto it = threaduriActive.begin(); it != threaduriActive.end();){
        if(it->joinable()) {
            it->join();
            it = threaduriActive.erase(it);
        } else {
            ++it;
        }
   }

 }