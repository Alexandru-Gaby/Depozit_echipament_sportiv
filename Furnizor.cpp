//
// Created by Alexandru-Gabriel on 03.12.2023.
//

#include "Furnizor.h"
#include <iostream>
#include <string>


Furnizor::Furnizor(std::string numefurnizor, std::string adresa)
        : NumeFurnizor(std::move(numefurnizor)), AdresaFurnizor(std::move(adresa)) {}

Furnizor::Furnizor(const Furnizor &other)
        : NumeFurnizor(other.NumeFurnizor), AdresaFurnizor(other.AdresaFurnizor) {}

Furnizor &Furnizor::operator=(const Furnizor &other)
{
    if (this == &other) return *this;
    NumeFurnizor = other.NumeFurnizor;
    AdresaFurnizor = other.AdresaFurnizor;

    return *this;
}

std::ostream &operator<<(std::ostream& os, const Furnizor& furnizor)
{
    os << "Nume Furnizor: " << furnizor.NumeFurnizor << " | Adresa: " << furnizor.AdresaFurnizor;

    return os;
}

std::istream& operator>>(std::istream& is, Furnizor& furnizor)
{
    is >> furnizor.NumeFurnizor >> furnizor.AdresaFurnizor;

    return is;
}



void Furnizor::initializare(const std::string &numefurnizor, const std::string &adresa)
{
    NumeFurnizor = numefurnizor;
    AdresaFurnizor = adresa;
}





