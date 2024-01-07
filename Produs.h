
#include <string>
#include <iostream>
#include <memory>

#include "Furnizor.h"
#include "csv.hpp"

#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H



class Produs
{
protected:
    int ID_produs;
    std::string Nume_produs;
    std::string Marime;
    int Pret;
    int Stoc_disponibil;
    Furnizor furnizorProdus;

public:


    Produs(int id, const std::string& nume, const std::string& marime, int pret, int stoc, const Furnizor& furnizor);

    Produs(const Produs &other);

    Produs &operator = (const Produs &other);

    friend std::ostream &operator << (std::ostream &os, const Produs &produs);

    virtual Produs* clone() const = 0;

    virtual ~Produs() = default;

    virtual void citire(const csv::CSVRow &is);

    virtual float AplicareDiscount()  = 0;

    //int GetID() const;

    int GetPret() const;

    void SetPret(int nouPret);

    void initializare(int id,const std::string &nume, const std::string &marime, int pret, int stoc,
                      const std::string &numefurnizor,const std::string &adresa);

};
#endif
