#include <csv.hpp>
#include "Produs.h"

using namespace csv;

Produs::Produs(const Produs &other)
        : ID_produs(other.ID_produs), Nume_produs(other.Nume_produs), Marime(other.Marime),
          Pret(other.Pret), Stoc_disponibil(other.Stoc_disponibil),furnizorProdus(other.furnizorProdus) {}


Produs &Produs::operator= (const Produs &other)
{
    if (this == &other) return *this;
    ID_produs = other.ID_produs;
    Nume_produs = other.Nume_produs;
    Marime = other.Marime;
    Pret = other.Pret;
    Stoc_disponibil = other.Stoc_disponibil;
    furnizorProdus = other.furnizorProdus;

    return *this;
}


std::ostream &operator<<(std::ostream &os, const Produs &produs)
{

    os << "ID Produs: " << produs.ID_produs << " | Nume Produs: " << produs.Nume_produs
       << " | Marime: " << produs.Marime << " | Pret: " << produs.Pret << " RON | Stoc Disponibil: "
       << produs.Stoc_disponibil << " | "<< produs.furnizorProdus;
    return os;
}


void Produs::citire(const CSVRow &){}


int Produs::GetID() const
{
    return ID_produs;
}

int Produs::GetPret() const
{
    return Pret;
}


void Produs::SetPret(int nouPret)
{

        if (nouPret >= 0)
        {
            Pret = nouPret;

        }else
        {
            std::cout<<"Pretul produsului nu poate sa fie negativ!";
        }

}



void Produs::initializare(int id,const std::string &nume, const std::string &marime, int pret, int stoc,
                          const std::string &numefurnizor,const std:: string &adresa)
{
    this->ID_produs=id;
    this->Nume_produs=nume;
    this->Marime=marime;
    this->Pret=pret;
    this->Stoc_disponibil=stoc;
    this->furnizorProdus.initializare(numefurnizor, adresa);
}
