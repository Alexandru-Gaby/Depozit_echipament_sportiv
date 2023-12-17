//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#include "ComenziAchizitii.h"

ComenziAchizitii::ComenziAchizitii(int numar, std::string data)
        : NumarComanda(numar), DataComanda(std::move(data)) {}

ComenziAchizitii::ComenziAchizitii(const ComenziAchizitii &other)
        : NumarComanda(other.NumarComanda), DataComanda(other.DataComanda),
          produseComandate(other.produseComandate){}

ComenziAchizitii::~ComenziAchizitii()
{
    for (auto produs : produseComandate)
        delete produs;
}

ComenziAchizitii &ComenziAchizitii::operator=(const ComenziAchizitii &other)
{
    if (this == &other)
        return *this;
    NumarComanda = other.NumarComanda;
    DataComanda = other.DataComanda;

    for(auto produs : produseComandate)
        delete produs;

    produseComandate.clear();
    produseComandate = other.produseComandate;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const ComenziAchizitii &comanda)
{
    os << "Numar Comanda: " << comanda.NumarComanda << " | Data Comanda: " << comanda.DataComanda;
    return os;
}

void ComenziAchizitii::AdaugaProdus(const Produs *produs)
{
    produseComandate.push_back(produs);
}

