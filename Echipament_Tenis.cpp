//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#include "Echipament_Tenis.h"
#include "EroareProdus.h"
#include <cmath>
#include <csv.hpp>


Echipament_Tenis::Echipament_Tenis(const Echipament_Tenis &et) :
        Produs(et),dificultate(PROFESIONIST){}


float Echipament_Tenis::AplicareDiscount()
{
    float discount = 0.0;
    float pret = static_cast<float>(GetPret());

    if (dificultate == INCEPATOR)
    {
        discount = 8.1 * log(pret);
    }
    else if (dificultate == AVANSAT)
    {
        discount = 5.2 * log(pret);
    }
    else if (dificultate == PROFESIONIST)
    {
        discount = 4.3 * log(pret);
    }


    float pretFinal = pret - discount;

    SetPret(static_cast<int>(pretFinal));


    return pretFinal;
}


void Echipament_Tenis:: citire(const csv::CSVRow &row)
{

    std::string col = row["Experienta"].get<std::string>();
    if (col == "INCEPATOR")
    {
        dificultate = INCEPATOR;
    }else if (col == "AVANSAT")
    {
        dificultate = AVANSAT;
    }else if(col == "PROFESIONIST")
    {
        dificultate = PROFESIONIST;
    }else throw EroareProprietateProdus("Experienta",col);
}

Produs *Echipament_Tenis::clone() const
{
    return new Echipament_Tenis(*this);
}
