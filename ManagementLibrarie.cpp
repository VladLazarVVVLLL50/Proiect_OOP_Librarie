#include "ManagementLibrarie.h"

ManagementLibrarie::~ManagementLibrarie() {
    for (auto& carte : carti) {
        delete carte;
    }
    for (auto& angajat : angajati) {
        delete angajat;
    }
    
    while (!comenziInAsteptare.empty()) {
        delete comenziInAsteptare.front();
        comenziInAsteptare.pop();
    }
    for (auto& comanda : comenziProcesate) {
        delete comanda;
    }
}
 
void ManagementLibrarie::adaugaAngajat(Angajat* angajat) {
    
    auto it = find_if(angajati.begin(), angajati.end(), [&angajat](Angajat* a) {
        return angajat->getID() == a->getID();
    });

    if (it == angajati.end()) {
        int maxID = angajati.empty() ? 1 : angajati.back()->getID() + 1;
        angajat->setID(maxID);
        angajati.push_back(angajat);
        cout << "Angajat adaugat cu succes ! \n";
    } else {
        cout << "Angajatul adaugat se afla deja in lista librariei.\n";
    }
}


void ManagementLibrarie::stergeAngajat(const int& id) {
     auto it = find_if(angajati.begin(), angajati.end(), [id](Angajat* a){ return id == a->getID();});
     
     if(it != angajati.end()){
        angajati.erase(it);
        int new_id = 1;
        for(auto new_it : angajati) {
            new_it->setID(new_id);
            new_id++;
        }

    } else {
        cout << "Angajatul nu a putut fi gasit! \n";
    }
}
        
void ManagementLibrarie::afiseazaAngajati() const {
    for(auto& it : angajati) {
        it->afisare();
    }
}

void ManagementLibrarie::adaugaCarte(Carte* carte) {
    bool amGasitTipul = false; 

    for (auto& carteExistenta : carti) {
        if (carteExistenta->getISBN() == carte->getISBN()) {
            
            if (auto carteExistentaPrintata = dynamic_cast<CarteTiparita*>(carteExistenta)) {
                if (auto nouaPrintata = dynamic_cast<CarteTiparita*>(carte)) {
                    carteExistentaPrintata->plusNumarExemplare();
                    cout << "Cartea tiparită se afla deja în librărie și numărul de exemplare a fost crescut!\n";
                    amGasitTipul = true;
                    break;
                }
            }
            else if (auto carteExistentaAudio = dynamic_cast<CarteAudio*>(carteExistenta)) {
                if (dynamic_cast<CarteAudio*>(carte)) {
                    cout << "Cartea audio se află deja in librarie.\n";
                    amGasitTipul = true;
                    break;
                }
            }
            else if (auto carteExistentaEBook = dynamic_cast<EBook*>(carteExistenta)) {
                if (dynamic_cast<EBook*>(carte)) {
                    cout << "EBook-ul se află deja in librarie.\n";
                    amGasitTipul = true;
                    break;
                }
            }
        }
    }

    if (!amGasitTipul) {
        
        carti.push_back(carte);
        cout << "Cartea noua a fost adaugata cu succes!\n";
    }
}

void ManagementLibrarie::stergeCarte(Carte* carte) {
    bool amGasitCartea = false;
    
    for (auto it = carti.begin(); it != carti.end(); ++it) {
        if ((*it)->getISBN() == carte->getISBN()) {
            amGasitCartea = true;
            if (auto carteExistentaPrintata = dynamic_cast<CarteTiparita*>(*it)) {
                if (auto deScos = dynamic_cast<CarteTiparita*>(carte)) {
                    if (carteExistentaPrintata->getNumarExemplare() > 1) {
                        carteExistentaPrintata->minusNumarExemplare();
                        cout << "Numarul de exemplare tiparite a fost redus cu unul.\n";
                    } else {
                        carti.erase(it);
                        cout << "Ultimul exemplar tiparit a fost eliminat!\n";
                    }
                    return; 
                }
            }
            else if (auto carteExistentaAudio = dynamic_cast<CarteAudio*>(*it)) {
                if (dynamic_cast<CarteAudio*>(carte)) {
                    carti.erase(it);
                    cout << "Cartea audio a fost eliminata!\n";
                    return;
                }
            }
            else if (auto carteExistentaEBook = dynamic_cast<EBook*>(*it)) {
                if (dynamic_cast<EBook*>(carte)) {
                    carti.erase(it);
                    cout << "EBook-ul a fost eliminat!\n";
                    return;
                }
            }
        } 
    }

    if(!amGasitCartea) {
        cout << "Cartea dvs. nu a putut fi atersa deoarece nu se afla in librarie cu acest format!\n";
    }
}



void ManagementLibrarie::afiseazaCarti() const {
    for(auto& it : carti) {
        it->afisare();
    }

}

void ManagementLibrarie::plaseazaComanda(Comanda* comanda) {
    
    if (comanda->esteComandaPreaMare()) {
        cout << "Comanda este prea mare! MAXIM 5 carti! \n";
        return;
    }

    bool comandaPoateFiPlasata = true;

    
    for (auto& carteComandata : comanda->getCartiComandate()) {
        bool gasita = false; 

        for (auto& carteInStock : carti) {
            
            if (carteComandata->getISBN() == carteInStock->getISBN()) {
                
                
                if (auto tiparitaComandata = dynamic_cast<CarteTiparita*>(carteComandata)) {
                    if (auto tiparitaInStock = dynamic_cast<CarteTiparita*>(carteInStock)) {
                        
                        if (tiparitaInStock->getNumarExemplare() >= 1) {
                            gasita = true;
                            tiparitaInStock->minusNumarExemplare(); 
                            break;
                        } else {
                            cout << "Cartea \"" << tiparitaComandata->getTitlu() 
                                      << "\" nu este disponibila in format tiparit in numarul de exemplare dorit!\n";
                            comandaPoateFiPlasata = false;
                        }
                    }
                }
               
                else if (dynamic_cast<CarteAudio*>(carteComandata) && dynamic_cast<CarteAudio*>(carteInStock)) {
                    gasita = true;
                    break;
                }
                
                else if (dynamic_cast<EBook*>(carteComandata) && dynamic_cast<EBook*>(carteInStock)) {
                    gasita = true;
                    break;
                }
            }
        }

       
        if (!gasita) {
            cout << "Cartea \"" << carteComandata->getTitlu() 
                      << "\" nu este disponibila in librarie in formatul dorit!\n";
            comandaPoateFiPlasata = false;
        }
    }

   
    if (!comandaPoateFiPlasata) {
        cout << "Comanda nu poate fi procesată din cauza lipsei de stoc pentru unele carti.\n";
        return;
    }

    
    bool comandaProcesata = false;
    for (auto& angajat : angajati) {
        Librar* librar = dynamic_cast<Librar*>(angajat);
        if (librar && librar->getNrComenziGestionate() < 3) {
            librar->procesareComanda(comanda);
            comenziProcesate.push_back(comanda);
            comandaProcesata = true;
            cout << "Comanda a fost procesata de librarul cu ID: " << librar->getID() << '\n';
            break;
        }
    }

    
    if (!comandaProcesata) {
        cout << "Nu am gasit un librar disponibil, comanda a fost adaugată cozii de așteptare!\n";
        comenziInAsteptare.push(comanda);
    }
}


void ManagementLibrarie::proceseazaComenziInAsteptare() {
    while(!comenziInAsteptare.empty()){
        Comanda* comanda = comenziInAsteptare.front();
        bool comandaProcesata = false;

        for(auto& angajat : angajati){
            Librar* librar = dynamic_cast<Librar*>(angajat);
            if(librar && librar->getNrComenziGestionate() < 3) {
                librar->procesareComanda(comanda);
                comenziProcesate.push_back(comanda);
                comandaProcesata = true;
                cout << "Comanda a fost procesata de librarul cu ID:" << librar->getID() << '\n';
                break;
            }
        }
        if(comandaProcesata) {
            comenziInAsteptare.pop();
        } else {
            break;
        }

    }
}
        
void ManagementLibrarie::afiseazaComenziProcesate() const {
    cout << "Comenzi procesate: \n";
    for(auto& it : comenziProcesate) {
        it->afisare();
    }

}

void ManagementLibrarie::afiseazaComenziInAsteptare() const {
    cout << "Comenzi in asteptare: \n";
    queue <Comanda*> tempQueue = comenziInAsteptare;
    while(!tempQueue.empty()){
        Comanda* comanda = tempQueue.front();
        comanda->afisare();
        tempQueue.pop();
    }
}

void ManagementLibrarie::topTreiAngajati() {
    vector<Librar*> librari;
    for(auto& angajat : angajati) {
        Librar* librar = dynamic_cast<Librar*>(angajat);
        if(librar) {
            librari.push_back(librar);
        }

    }

    sort(librari.begin(), librari.end(), [](Librar* l1, Librar*l2){ return l1->getSumaComenziGestionate() > l2->getSumaComenziGestionate();});
    cout << "TOP CEI MAI PRODUCTIVI LIBRARI: \n";
    for(int i = 0; i < librari.size() && i < 3; ++i) {
        cout << i+1 << ": \n";
        librari[i]->afisare();
    }

}

void ManagementLibrarie::celMaiProductivAngajatInData(string Data) {
    vector<Librar*> librari;
    for(auto& angajat : angajati) {
        Librar* librar = dynamic_cast<Librar*>(angajat);
        if(librar) {
            librari.push_back(librar);
        }

    }
    int maxi = 0;
    Librar* bestLibrar;
    for(auto& librar : librari) {
        if(librar->getNrComenziGestionateInOData(Data) > maxi) {
            maxi = librar->getNrComenziGestionateInOData(Data);
            bestLibrar = librar;
        }
    }
    cout <<"Cel mai productiv librar in data: " << Data << " este: \n";
    bestLibrar->afisare();
}