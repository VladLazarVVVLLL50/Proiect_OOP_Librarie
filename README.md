
# Proiect OOP: Librarie Digitala
**Implementare:** Lazar Vlad-Andrei

## Descrierea proiectului:
Acest proiect consta intr-un sistem de gestionare a unei librarii, bazat pe consola, dezvoltat in C++ pentru un curs de OOP destinat studentilor din anul II.

Sistemul gestioneaza angajatii, cartile si comenzile clientilor, folosind principiile programarii orientate pe obiecte (OOP) si include atat operatii de baza, cat si generarea de rapoarte pentru monitorizarea performantei angajatilor.

### Structura librariei:

Libraria include trei tipuri de angajati:
- Fiecare angajat are urmatoarele atribute: ID unic, experienta in ani, nume, prenume, data angajarii, data nasterii si coeficientul de salariu.
- Managerul are in plus campurile: departament, numarul de angajati supravegheati si un bonus care se adauga la salariu.
- Librarul are in plus campurile: sectiunea de responsabilitate.
- Asistentul librar are, pe langa campurile librarului atributul ore suplimentare ce se adauga la salariu +20 per ora.

Salariul angajatilor se calculeaza dupa formula:
- **Salariu** = (ani de vechime * coeficient salariu * 1500) + bonus (pentru manager) + 20 * numar ore suplimentare (pentru asistent librar)
- Coeficientii sunt: 3 pentru manager, 2 pentru librar si 1.5 pentru asistent librar.

Libraria gestioneaza trei tipuri de carti:
- Fiecare carte are urmatoarele atribute: ISBN, titlu, numele autorului, anul publicarii si numarul de exemplare disponibile.
  - **Carte tiparita**: are in plus numarul de pagini; pretul se calculeaza ca: nr. pagini * 0.2.
  - **EBook**: are in plus dimensiunea fisierului; pretul se calculeaza ca: dimensiune fisier * 1.5.
  - **Audiobook**: are in plus durata in ore; pretul se calculeaza ca: durata * 10.

## Functionalitati obligatorii:

### 1. Gestiunea angajatilor:
Aplicatia permite gestionarea angajatilor prin:
- **Adaugarea angajatilor**: Posibilitatea de a adauga angajati noi (Librar, Asistent Librar si Manager), fiecare cu atribute specifice, si incrementarea ID-ului.
- **Stergerea angajatilor**: Posibilitatea de a sterge un angajat pe baza unui ID unic si decrementarea ID-ului.
- **Afisarea angajatilor**: Posibilitatea de a lista toti angajatii din librarie, afisand informatiile relevante.

#### Restrictii:
- Fiecare angajat poate gestiona maximum 3 comenzi simultan.
- Managerii nu gestioneaza comenzi.

### 2. Gestiunea cartilor:
Aplicatia permite gestionarea cartilor din biblioteca prin:
- **Adaugarea cartilor**: Posibilitatea de a adauga carti noi, inclusiv tipuri de carti precum Carte Audio, EBook si Carte Tiparita.
- **Stergerea cartilor**: Posibilitatea de a sterge carti pe baza unui ISBN unic.
- **Afisarea cartilor**: Posibilitatea de a lista toate cartile disponibile in biblioteca, inclusiv detalii precum titlul, autorul si tipul cartii.

#### Restrictii:
- Fiecare carte va avea un pret stabilit in functie de tipul sau, calculat printr-o metoda specifica (calculPret).

### 3. Gestiunea comenzilor:
Aplicatia permite gestionarea comenzilor clientilor conform urmatoarelor cerinte:
- **Plasarea comenzilor**: Posibilitatea de a plasa comenzi care includ pana la 5 carti per comanda.
- **Alocarea comenzilor catre angajati**: Comenzile vor fi alocate automat angajatilor disponibili. Daca toti angajatii sunt ocupati, comenzile vor fi plasate intr-o coada de asteptare.
- **Procesarea comenzilor din coada de asteptare**: Cand un angajat devine disponibil, comanda din coada este alocata acestuia.

#### Restrictii:
- O comanda nu poate contine mai mult de 5 carti.
- Daca toti angajatii sunt ocupati, comenzile vor fi adaugate intr-o coada de asteptare si vor fi procesate pe masura ce angajatii devin disponibili.

### 4. Generarea de rapoarte:
Aplicatia include functionalitati de raportare pentru monitorizarea activitatilor si performantei angajatilor:
- **Raport zilnic**: Generarea unui raport care identifica angajatul cu cele mai multe comenzi procesate intr-o anumita zi.
- **Top 3 angajati pe baza valorii comenzilor**: Generarea unui raport care afiseaza top 3 angajati care au gestionat cele mai valoroase comenzi, in functie de valoarea totala a cartilor vandute.



## Optimizare si implementare de functionalitati suplimentare:
- Am adaugat **functii de procesare paralela a comenzilor**, astfel incat fiecare angajat proceseaza comenzi in paralel, cu un timp de procesare pentru fiecare functie. Acest lucru ajuta la simularea unei librarii in care comenzile sunt gestionate mai rapid si eficient.



