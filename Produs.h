//
// Created by Alexandru-Gabriel on 03.12.2023.
//

#include <string>
#include <iostream>
#include <memory>
#include "Furnizor.h"
#include "Interfata_Produs.h"

#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H


class CSVRow;

class Produs:public Interfata_Produs
{
private:
    int ID_produs;
    std::string Nume_produs;
    std::string Marime;
    int Pret;
    int Stoc_disponibil;
    std::string TipSport;
    Furnizor furnizorProdus;


public:
    float AplicareDiscount(){};

    Produs(){};

    Produs(int id, std::string nume, std::string marime, int pret, int stoc, std:: string tip_sport, const Furnizor &furnizor);


    Produs(const Produs &other);

    Produs &operator=(const Produs &other);


    ~Produs() = default;

    friend std::ostream &operator<<(std::ostream &os, const Produs &produs);

    int GetID() const;

    int GetPret() const;

    std::string GetTipSport() const;

    const Furnizor &GetFurnizor() const;

    void SetPret(int nouPret);

    /*
    static void Afisare_Produse(const std::vector<Produs> &produse)
    {
        for (const Produs &produs: produse)
        {
            std::cout << produs << std::endl;
            std::cout
                    << "---------------------------------------------------------------------------------------------------------------------"
                    << std::endl;

        }
    }
   */
    static std::unique_ptr<Produs> CitesteProduseDinFisier(csv:: CSVRow &row);


};
#endif