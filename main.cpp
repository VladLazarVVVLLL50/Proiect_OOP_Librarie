#include <iostream>
#include <vector>
#include "ManagementLibrarie.h"
#include "CarteTiparita.h"
#include "CarteAudio.h"
#include "EBook.h"
#include "Comanda.h"
#include "Librar.h"
#include "Manager.h"

int main() {
    ManagementLibrarie librarie;

    
    Librar* librar1 = new Librar(1, 5, "Ion", "Popescu", "1980-01-01", "2010-05-10", 1.2, "Fictiune");
    Librar* librar2 = new Librar(2, 3, "Maria", "Ionescu", "1985-02-02", "2012-07-15", 1.1, "Istorie");
    Librar* librar3 = new Librar(4, 7, "George", "Marinescu", "1987-04-05", "2015-08-20", 1.3, "Stiinta");
    Manager* manager = new Manager(3, 10, "Elena", "Vasilescu", "1975-03-03", "2005-08-20", 1.5, "General", 3, 600);

    librarie.adaugaAngajat(librar1);
    librarie.adaugaAngajat(librar2);
    librarie.adaugaAngajat(librar3);
    librarie.adaugaAngajat(manager);

    cout << "\n--- Angajati adaugati ---\n";
    librarie.afiseazaAngajati();

    
    CarteTiparita* book1 = new CarteTiparita("123", "O lume noua", "A. Autor", 2003, 100, 5);
    CarteAudio* book2 = new CarteAudio("124", "Asculta istoria", "B. Autor", 2012, 90);
    EBook* book3 = new EBook("125", "Programare pentru toti", "C. Autor", 2020, 10);
    CarteTiparita* book4 = new CarteTiparita("126", "Enciclopedia Stiintei", "D. Autor", 2019, 300, 2);
    EBook* book5 = new EBook("127", "Povesti Nemuritoare", "E. Autor", 2018, 15);

    librarie.adaugaCarte(book1);
    librarie.adaugaCarte(book2);
    librarie.adaugaCarte(book3);
    librarie.adaugaCarte(book4);
    librarie.adaugaCarte(book5);

    cout << "\n--- Carti adaugate ---\n";
    librarie.afiseazaCarti();

    
    vector<Carte*> cartiComandate1 = {book1, book2}; 
    Comanda* comanda1 = new Comanda(cartiComandate1, "2024-11-10");

    vector<Carte*> cartiComandate2 = {book1, book4, book3}; 
    Comanda* comanda2 = new Comanda(cartiComandate2, "2024-11-11");

    vector<Carte*> cartiComandate3 = {book1, book1, book4, book4}; 
    Comanda* comanda3 = new Comanda(cartiComandate3, "2024-11-12");

    vector<Carte*> cartiComandate4 = {book3, book5, book5}; 
    Comanda* comanda4 = new Comanda(cartiComandate4, "2024-11-13");

    vector<Carte*> cartiComandate5 = {book1, book1, book1, book1, book1, book1}; 
    Comanda* comanda5 = new Comanda(cartiComandate5, "2024-11-14");

    librarie.plaseazaComanda(comanda1);
    librarie.plaseazaComanda(comanda2);
    librarie.plaseazaComanda(comanda3);
    librarie.plaseazaComanda(comanda4);
    librarie.plaseazaComanda(comanda5); 

    cout << "\n--- Comenzi plasate ---\n";
    librarie.afiseazaComenziProcesate();
    librarie.afiseazaComenziInAsteptare();

    
    cout << "\n--- Procesare comenzi in asteptare ---\n";
    librarie.proceseazaComenziInAsteptare();
    librarie.afiseazaComenziProcesate();
    librarie.afiseazaComenziInAsteptare();

    
    cout << "\n--- Top 3 Angajati Productivi ---\n";
    librarie.topTreiAngajati();

    
    string dateToCheck = "2024-11-10";
    cout << "\n--- Cel Mai Productiv Angajat in Data: " << dateToCheck << " ---\n";
    librarie.celMaiProductivAngajatInData(dateToCheck);

    

    return 0;
}
