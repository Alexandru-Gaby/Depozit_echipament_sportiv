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
private:
    std:: string culoare;

public:
    Echipament_Fotbal(){};

    Echipament_Fotbal(int id, std::string nume,
                      std::string marime, int pret, int stoc, std::string tip_sport,
                      const Furnizor &furnizor, std::string culoare_);

    float AplicareDiscount() override;



};
#endif //OOP_ECHIPAMENT_FOTBAL_H
