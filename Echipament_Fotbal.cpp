#include <csv.hpp>
#include "Echipament_Fotbal.h"
#include "cmath"
#include "EroareProdus.h"


Echipament_Fotbal::Echipament_Fotbal(const Echipament_Fotbal &ef):
Produs(ef), culoare(ROSU) {}

float Echipament_Fotbal::AplicareDiscount()
{
    float Discount = 0.0;
    float pretInitial = static_cast<float>(GetPret());

    if(culoare == ROSU)
    {
        Discount = 6.2 * sqrt(pretInitial);
    }
    else if (culoare == ALBASTRU)
    {
        Discount = 6.5 * sqrt(pretInitial);
    }else if (culoare == ALB)
    {
        Discount = 7.3 * sqrt(pretInitial);
    }
    float pretFinal = pretInitial - Discount;

    SetPret(static_cast<int>(pretFinal));

    return pretFinal;
}

void Echipament_Fotbal::citire(const csv::CSVRow &row)
{
    std::string col = row["Culoare"].get<std::string>();
    if (col == "ROSU")
    {
        culoare = ROSU;
    }else if (col == "ALBASTRU")
    {
        culoare = ALBASTRU;
    }else if(col == "ALB")
    {
        culoare = ALB;
    }else throw EroareProprietateProdus("Culoare",col);

}

Echipament_Fotbal *Echipament_Fotbal::clone() const
{
    return new Echipament_Fotbal(*this);
}
