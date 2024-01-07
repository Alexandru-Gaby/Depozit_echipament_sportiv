#ifndef OOP_ECHIPAMENT_BASCHET_H
#define OOP_ECHIPAMENT_BASCHET_H


#include <string>
#include <iostream>
#include <csv.hpp>
#include "Furnizor.h"
#include "Produs.h"

class Echipament_Baschet: public Produs
{
public:
    enum TaraProductie
    {
        ITALIA,
        SUA,
        VIETNAM,
    };

private:
    TaraProductie taraProductie;

public:

    Echipament_Baschet(const Echipament_Baschet &eb);

    ~Echipament_Baschet()=default;

    float AplicareDiscount() override;

    Echipament_Baschet* clone() const override;

    void citire(const csv::CSVRow &row) override;
};

#endif //OOP_ECHIPAMENT_BASCHET_H
