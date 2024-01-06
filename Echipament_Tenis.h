//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#ifndef OOP_ECHIPAMENT_TENIS_H
#define OOP_ECHIPAMENT_TENIS_H

#include <vector>
#include <fstream>
#include <csv.hpp>
#include "Produs.h"


class Echipament_Tenis: public Produs
{
public:
    enum Dificultate
    {   INCEPATOR,
        AVANSAT,
        PROFESIONIST
    };

private:
    Dificultate dificultate;

public:


    Echipament_Tenis(){};

    Echipament_Tenis(const Echipament_Tenis &et);

    ~Echipament_Tenis()=default;

    float AplicareDiscount() override;

    void citire(const csv::CSVRow &row) override;

    Produs* clone() const override;
};

#endif //OOP_ECHIPAMENT_TENIS_H
