#ifndef OOP_FACTORY_PRODUSE_H
#define OOP_FACTORY_PRODUSE_H

#include <string>
#include <csv.hpp>
#include "Produs.h"


class ProdusFactory
{
public:
    enum TipEchipament
    {
        Fotbal,
        Baschet,
        Tenis
    };

    static Produs *CitesteProdus(csv::CSVRow &row, TipEchipament tipEchipament);



};


#endif //OOP_FACTORY_PRODUSE_H
