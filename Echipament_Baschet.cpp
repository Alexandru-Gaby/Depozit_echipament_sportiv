#include <cmath>
#include <csv.hpp>
#include "Echipament_Baschet.h"
#include "EroareProdus.h"

Echipament_Baschet::Echipament_Baschet(const Echipament_Baschet &eb) :Produs(eb),taraProductie(eb.taraProductie){}

float Echipament_Baschet::AplicareDiscount()
{
    float Discount = 0.0;
    float pretInitial = static_cast<float>(GetPret());

    if(taraProductie == ITALIA)
    {
        Discount = 3 * pow(pretInitial, 0.7);
    }
    else if (taraProductie == SUA)
    {
        Discount = 4.5 * pow(pretInitial, 0.5);
    }else if (taraProductie == VIETNAM)
    {
        Discount = 5.2 * pow(pretInitial, 0.5);

    }
    float pretFinal = pretInitial - Discount;

    SetPret(static_cast<int>(pretFinal));


    return pretFinal;
}


Echipament_Baschet *Echipament_Baschet::clone() const
{
    return new Echipament_Baschet(*this);

}

void Echipament_Baschet::citire(const csv::CSVRow &row)
{
    std::string col = row["Tara productie"].get<std::string>();
    if (col == "ITALIA")
    {
        taraProductie = ITALIA;
    }else if (col == "SUA")
    {
        taraProductie = SUA;
    }else if(col == "VIETNAM")
    {
        taraProductie = VIETNAM;
    }else throw EroareProprietateProdus("Tara productie", col);

}
