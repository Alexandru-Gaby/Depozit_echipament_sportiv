//
// Created by Alexandru-Gabriel on 10.12.2023.
//

#ifndef OOP_COMENZIACHIZITII_H
#define OOP_COMENZIACHIZITII_H


#include <string>
#include <vector>
#include "Produs.h"

class ComenziAchizitii
{
private:
    int NumarComanda;
    std::string DataComanda;
    std::vector<Produs*> produseComandate;

public:
    [[maybe_unused]] ComenziAchizitii(int numar, std::string data);

    ComenziAchizitii(const ComenziAchizitii &other);

    ~ComenziAchizitii();

    ComenziAchizitii &operator=(const ComenziAchizitii &other);

    friend std::ostream &operator<<(std::ostream &os, const ComenziAchizitii &comanda);

    [[maybe_unused]] void AdaugaProdus(const Produs &produs);
};

#endif //OOP_COMENZIACHIZITII_H
