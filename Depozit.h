//
// Created by Alexandru-Gabriel on 09.12.2023.
//

#ifndef OOP_DEPOZIT_H
#define OOP_DEPOZIT_H

#include <vector>
#include <string>
#include <csv.hpp>
#include "Produs.h"

class [[maybe_unused]] Depozit
{
private:
    std::vector<std::shared_ptr<Produs>> produseDepozit;
    std::string locatie;
    std::string numeDepozit;

public:
    Depozit()= default;

    [[maybe_unused]] Depozit(const Depozit &other);

    virtual ~Depozit() = default;

    Depozit &operator=(const Depozit& other);


    [[maybe_unused]] void Sortare_produse_dupa_pret();

    [[maybe_unused]] void AfiseazaProduse();

    [[maybe_unused]] void ActualizarePret(int ID_produs, int Pret_nou);

    //void CitesteProduseDinFisierCSV();

    //void AdaugaProdusDinFisier(const csv::CSVRow& row);

};


#endif //OOP_DEPOZIT_H
