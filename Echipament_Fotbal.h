//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#ifndef OOP_ECHIPAMENT_FOTBAL_H
#define OOP_ECHIPAMENT_FOTBAL_H


#include <string>
#include "Furnizor.h"
#include "Produs.h"


class Echipament_Fotbal: public Produs
{
public:
    enum Culoare
    {
        ROSU,
        ALBASTRU,
        ALB
    };
private:

    Culoare culoare;

public:

    Echipament_Fotbal(){};

    Echipament_Fotbal(const Echipament_Fotbal& ef);

    ~Echipament_Fotbal()=default;

    friend int Produs::GetPret() const;
    friend int Produs::GetID() const;

    Echipament_Fotbal* clone() const override;

    void citire(const csv::CSVRow &is);

    float AplicareDiscount() override;


};
#endif //OOP_ECHIPAMENT_FOTBAL_H
