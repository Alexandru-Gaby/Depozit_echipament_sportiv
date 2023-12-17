//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#include "Echipament_Tenis.h"
#include <csv.hpp>


float Echipament_Tenis::AplicareDiscount()
{
    if (GetTipSport() == "Tenis")
    {
        float discount = 0.2;
        float valoareDiscount = GetPret() * discount;
        SetPret(GetPret() - static_cast<int>(valoareDiscount));
        std::cout << "Discount aplicat pentru Echipament_Tenis " << valoareDiscount << " RON" << std::endl;

        return static_cast<float>(GetPret());
    }else
    {
        std::cout << "Nu se aplică discount pentru acest tip de echipament." << std::endl;
        return static_cast<float>(GetPret());
    }
}
