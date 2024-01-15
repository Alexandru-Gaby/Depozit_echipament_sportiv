//
// Created by Alexandru-Gabriel on 09.12.2023.
//

#ifndef OOP_DEPOZIT_H
#define OOP_DEPOZIT_H

#include <vector>
#include <string>
#include <csv.hpp>
#include "Produs.h"

class Depozit
{
private:
    std::vector<std::shared_ptr<Produs>> produseDepozit;
    std::string locatie;
    std::string numeDepozit;
    static Depozit instanta;

    Depozit()= default;

public:


    Depozit(const Depozit &other)=delete;

    virtual ~Depozit() = default;

    Depozit &operator=(const Depozit& other)=delete;

    [[maybe_unused]] void Sortare_produse_dupa_pret();

    //void AfiseazaProduse();

    [[maybe_unused]] void ActualizarePret(int ID_produs, int Pret_nou);

    //void CitesteProduseDinFisierCSV();

    static Depozit& GetDepozit();

    void AdaugaProdus(Produs*);

    friend std:: ostream &operator<<(std::ostream &os,const Depozit&);
};
std:: ostream &operator<<(std::ostream &os,const Depozit& );

#endif //OOP_DEPOZIT_H
