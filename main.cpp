#include <iostream>
#include <vector>
#include <string>
#include <csv.hpp>
#include "Produs.h"
#include "ComenziAchizitii.h"
#include "Depozit.h"
#include "Echipament_Baschet.h"


using namespace csv;


int main()
{
    std::ifstream file("date.csv");
    CSVFormat format;
    format.delimiter(';');
    CSVReader reader(file, format);

    std::vector<Produs*> produse;
    Depozit depozit;

    for (csv::CSVRow &row: reader)
    {
        std::unique_ptr<Produs> produsPtr = Produs::CitesteProduseDinFisier(row);
        produse.push_back(produsPtr.release());
        depozit.Adauga_produs(*produsPtr);

        std::cout << "Nume Furnizor: " << produsPtr -> GetFurnizor().GetNume() << std::endl;
        std::cout << "Adresa Furnizor: " << produsPtr -> GetFurnizor().GetAdresa() << std::endl;
    }


    ComenziAchizitii comanda(100, "02/11/2023");

    Furnizor furnizor1("Nike", "Adresa1");
    Furnizor furnizor2("New Balance", "Adresa2");


    Produs produs1(1, "NumeProdus1", "Marime1", 50, 10, furnizor1);
    Produs produs2(2, "NumeProdus2", "Marime2", 60, 15, furnizor2);


    comanda.AdaugaProdus(produs1);
    comanda.AdaugaProdus(produs2);

    depozit.ActualizarePret(1, 100);


    //Produs * p = new Echipament_Baschet;
    std::cout << "Detalii produse dupa actualizare:\n" << std::endl;

    depozit.Sortare_produse_dupa_pret();
    depozit.AfiseazaProduse();
    //Produs::Afisare_Produse(produse);

    return 0;
}


