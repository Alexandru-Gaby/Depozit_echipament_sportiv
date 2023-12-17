//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#ifndef OOP_ECHIPAMENT_TENIS_H
#define OOP_ECHIPAMENT_TENIS_H


#include "Produs.h"
#include <vector>
#include <fstream>


class Echipament_Tenis: public Produs
{
private:
    std:: string culoare;

public:
    Echipament_Tenis(){};

    Echipament_Tenis(int id, std::string nume,std::string marime,int pret, int stoc, std:: string tip_sport,const Furnizor furnizor, std:: string culoare_);

    float AplicareDiscount() override;

    //static std::vector<Produs>Cauta_produs(const std::string& numeFisier);
};

#endif //OOP_ECHIPAMENT_TENIS_H
