//
// Created by Alexandru-Gabriel on 09.12.2023.
//

#include "Depozit.h"


void Depozit::Adauga_produs(const Produs &produs)
{
    produseDepozit.push_back(produs);
}


void Depozit::Sortare_produse_dupa_pret()
{
    std::sort(produseDepozit.begin(), produseDepozit.end(), [] (const Produs &a, const Produs &b)
    {
        return a.GetPret() < b.GetPret();
    });
}

void Depozit::AfiseazaProduse()
{
    for (const Produs &produs : produseDepozit)
    {
        std::cout << produs << std::endl;
        std::cout << "---------------------------------------------------------------------------------------------------------------------" << std::endl;
    }
}

void Depozit::ActualizarePret(int ID_produs, int Pret_nou)
{
    for(Produs &produs : produseDepozit)
    {
        if(produs.GetID() == ID_produs )
        {
            produs.SetPret(Pret_nou);
            break;
        }
    }
}
