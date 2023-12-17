//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#include "Echipament_Fotbal.h"

Echipament_Fotbal::Echipament_Fotbal(int id, std::string nume,
                                     std::string marime, int pret, int stoc, std::string tip_sport,
                                     const Furnizor &furnizor, std::string culoare_) : Produs(id, nume, marime, pret, stoc, tip_sport, furnizor) {}


float Echipament_Fotbal::AplicareDiscount()
{
    if (GetTipSport() == "Fotbal")
    {
        float discount = 0.3;
        float valoareDiscount = GetPret() * discount;
        SetPret(GetPret() - static_cast<int>(valoareDiscount));
        std::cout << "Discount aplicat pentru Echipament_fotbal " << valoareDiscount << " RON" << std::endl;

        return static_cast<float>(GetPret());
    }else{
        std::cout << "Nu se aplică discount pentru acest tip de echipament." << std::endl;
        return static_cast<float>(GetPret());
    }
}
