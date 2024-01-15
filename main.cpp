#include <iostream>
#include <string>
#include "csv.hpp"
#include "Produs.h"
#include "Factory_produse.h"
#include "EroareProdus.h"
#include "Depozit.h"
#include "ComenziAchizitii.h"


using namespace csv;


int main()
{
    //ProdusFactory produsFactory;
    ComenziAchizitii comanda(1, "2024-01-15");
    csv::CSVReader reader("date.csv");

       for (auto &row: reader)
       {
           try
           {
               std::string tipEchipamentStr = row["Tip Echipament"].get<>();
               ProdusFactory::TipEchipament tipEchipament;

               if (tipEchipamentStr == "Fotbal") {
                   tipEchipament = ProdusFactory::Fotbal;
               } else if (tipEchipamentStr == "Baschet") {
                   tipEchipament = ProdusFactory::Baschet;
               } else if (tipEchipamentStr == "Tenis") {
                   tipEchipament = ProdusFactory::Tenis;
               } else {
                   throw EroareTipEchipament(tipEchipamentStr);
               }

               Produs *produs = ProdusFactory::CitesteProdus(row, tipEchipament);

               produs->SetPret(produs->AplicareDiscount());

               Depozit::GetDepozit().AdaugaProdus(produs);

               comanda.AdaugaProdus(*produs);

               //std::cout << std::endl << *produs << std::endl;

               //delete produs;

           }
           catch (const EroareTipEchipament &e)
           {std::cout<<" \nEroare: " << e.what() << std::endl;}

           catch (const EroareProprietateProdus &e)
           {std::cout <<"\nEroare la proprietatea echipamentului: " << e.what() << std::endl;}


       }

        std::cout<<Depozit::GetDepozit();
        std::cout << comanda << std::endl;
        std::cout << "Total comanda: " << comanda.GetTotal() << " RON" << std::endl;



    return 0;
}



