//
// Created by Alexandru-Gabriel on 09.12.2023.
//

#ifndef OOP_DEPOZIT_H
#define OOP_DEPOZIT_H


#include "Produs.h"
#include <vector>

class Depozit
{
private:
    //vectorul ar trebui sa contina pointeri la clasa produs(upcasting)
    std:: vector<Produs> produseDepozit;

public:
    Depozit(){};

    void Adauga_produs(const Produs &produs);

    void Sortare_produse_dupa_pret();

    void AfiseazaProduse();

    void ActualizarePret(int ID_produs, int Pret_nou);


};


#endif //OOP_DEPOZIT_H
