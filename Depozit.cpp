#include <algorithm>
#include "Depozit.h"
#include <csv.hpp>


[[maybe_unused]] Depozit::Depozit(const Depozit &other) : locatie(other.locatie),numeDepozit(other.numeDepozit)
{
    for(const auto& produs : other.produseDepozit)
    {
        produseDepozit.push_back(std::shared_ptr<Produs>(produs->clone()));
    }
}

Depozit &Depozit::operator=(const Depozit &other)
{
    if(this != &other)
    {
        produseDepozit.clear();
        locatie = other.locatie;
        numeDepozit = other.numeDepozit;

        for (const auto& produs : other.produseDepozit)
        {
            produseDepozit.push_back(std::shared_ptr<Produs>(produs->clone()));
        }
    }
    return *this;
}

[[maybe_unused]] void Depozit::Sortare_produse_dupa_pret()
{
    std::sort(produseDepozit.begin(), produseDepozit.end(), [] (const std::shared_ptr<Produs> &a, const std::shared_ptr<Produs> &b)
    {
        return a->GetPret() < b->GetPret();
    });
}


[[maybe_unused]] void Depozit::ActualizarePret(int ID_produs, int Pret_nou)
{
    for(auto &produs : produseDepozit)
    {
        if(produs->GetID() == ID_produs )
        {
            produs->SetPret(Pret_nou);
            break;
        }
    }
}
