//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#include "Echipament_Baschet.h"

Echipament_Baschet::Echipament_Baschet(int id, std::string nume, std::string marime, int pret, int stoc,
                                       std::string tip_sport, const Furnizor furnizor) : Produs(id,nume,marime,pret,stoc,tip_sport,furnizor){}

float Echipament_Baschet::AplicareDiscount()
{
    if (GetTipSport() == "Baschet")
    {
        float discount = 0.25;
        float valoareDiscount = GetPret() * discount;
        SetPret(GetPret() - static_cast<int>(valoareDiscount));
        std::cout << "Discount aplicat pentru Echipament_Baschet " << valoareDiscount << " RON" << std::endl;

        return static_cast<float>(GetPret());
    }else{
        std::cout << "Nu se aplică discount pentru acest tip de echipament." << std::endl;
        return static_cast<float>(GetPret());
    }
}

Echipament_Baschet::Echipament_Baschet(const Echipament_Baschet& ec): Produs(ec), culoare(ec.culoare){}