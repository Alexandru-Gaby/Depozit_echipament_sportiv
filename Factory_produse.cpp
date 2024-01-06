#include <string>
#include <csv.hpp>
#include "Factory_produse.h"
#include "Produs.h"
#include "Furnizor.h"
#include "Echipament_Fotbal.h"
#include "Echipament_Baschet.h"
#include "Echipament_Tenis.h"


Produs *ProdusFactory::CitesteProdus(csv::CSVRow &row, ProdusFactory::TipEchipament tipEchipament)
{
    int id = std::stoi(row["ID_produs"].get<>());
    std::string nume = row["Nume_produs"].get<>();
    std::string marime = row["Marime"].get<>();
    int pret = std::stoi(row["Pret"].get<>());
    int stoc = std::stoi(row["Stoc_disponibil"].get<>());
    std::string numefurnizor = row["NumeFurnizor"].get<>();
    std::string adresa = row["Adresa"].get<>();

    Produs* produsPtr = nullptr;
    Furnizor furnizor(numefurnizor,adresa);


    switch (tipEchipament)
    {
        case Fotbal:
            produsPtr = new Echipament_Fotbal();
            break;
        case Baschet:
            produsPtr = new Echipament_Baschet();
            break;
        case Tenis:
            produsPtr = new Echipament_Tenis();
            break;


    }
    produsPtr->initializare(id, nume, marime, pret, stoc, numefurnizor, adresa);
    produsPtr->citire(row);



    return produsPtr;
}
