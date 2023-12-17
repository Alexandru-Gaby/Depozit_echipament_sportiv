//
// Created by Alexandru-Gabriel on 03.12.2023.
//

#include "Furnizor.h"


Furnizor::Furnizor(std::string nume, std::string adresa)
        : NumeFurnizor(std::move(nume)), Adresa(std::move(adresa)) {}

Furnizor::Furnizor(const Furnizor &other)
        : NumeFurnizor(other.NumeFurnizor), Adresa(other.Adresa) {}

Furnizor &Furnizor::operator=(const Furnizor &other)
{
    if (this == &other) return *this;
    NumeFurnizor = other.NumeFurnizor;
    Adresa = other.Adresa;
    return *this;
}

std::ostream &operator<<(std::ostream& os, const Furnizor& furnizor)
{
    os << "Nume Furnizor: " << furnizor.NumeFurnizor << " | Adresa: " << furnizor.Adresa;
    return os;
}

std::istream& operator>>(std::istream& is, Furnizor& furnizor)
{
    is >> furnizor.NumeFurnizor >> furnizor.Adresa;
    return is;
}

const std::string &Furnizor::GetNume() const {
    return NumeFurnizor;
}

const std::string &Furnizor::GetAdresa() const {
    return Adresa;
}






