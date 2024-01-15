//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#include "ComenziAchizitii.h"
#include <iostream>


[[maybe_unused]] ComenziAchizitii::ComenziAchizitii(int numar, std::string data)
        : NumarComanda(numar), DataComanda(std::move(data)) {}

ComenziAchizitii::ComenziAchizitii(const ComenziAchizitii &other)
        : NumarComanda(other.NumarComanda),DataComanda(other.DataComanda)
    {
    for (const auto &produs : other.produseComandate)
        {
            produseComandate.push_back(std::shared_ptr <Produs> (produs->clone()));
        }
    }




ComenziAchizitii &ComenziAchizitii::operator=(const ComenziAchizitii &other)
{
    if (this != &other)
    {
        NumarComanda = other.NumarComanda;
        DataComanda = other.DataComanda;

        produseComandate.clear();


        for (const auto &produs : other.produseComandate)
        {
            produseComandate.push_back(std::shared_ptr <Produs> (produs->clone()));
        }
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const ComenziAchizitii &comanda)
{
    os << "Numar Comanda: " << comanda.NumarComanda << " | Data Comanda: " << comanda.DataComanda;
    return os;
}


void ComenziAchizitii::AdaugaProdus(const Produs &produs)
{
    produseComandate.push_back(std::shared_ptr <Produs> (produs.clone()));
}

long ComenziAchizitii::GetTotal() const
{
    long Total = 0;
     for (const auto &produs : produseComandate)
     {
        Total+=produs->AplicareDiscount();
    }
     return Total;
};
