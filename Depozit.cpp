#include "Depozit.h"
#include <csv.hpp>




void Depozit::AdaugaProdus(Produs *prod)
{
produseDepozit.push_back( std::shared_ptr<Produs>(prod));
}

std:: ostream &operator<<(std::ostream &os,const Depozit& dep)
{
    for(auto prod:dep.produseDepozit)
    {
        os << *prod;
    }
    return os;
}

/*[[maybe_unused]] void Depozit::Sortare_produse_dupa_pret()
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
}*/

Depozit& Depozit::GetDepozit()
{
    return instanta;
}


Depozit Depozit::instanta = {};

