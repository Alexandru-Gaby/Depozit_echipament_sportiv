//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#ifndef OOP_ECHIPAMENT_BASCHET_H
#define OOP_ECHIPAMENT_BASCHET_H


#include <string>
#include "Furnizor.h"
#include "Produs.h"

class Echipament_Baschet: public Produs
{
private:
    std:: string culoare;

public:
    Echipament_Baschet(){};

    Echipament_Baschet(int id, std::string nume,std::string marime,int pret, int stoc,std::string tip_sport,
                       const Furnizor furnizor);

    //Echipament_Baschet(const Echipament_Baschet&);

    float AplicareDiscount() override;

    Produs* clone() const;
};

#endif //OOP_ECHIPAMENT_BASCHET_H
