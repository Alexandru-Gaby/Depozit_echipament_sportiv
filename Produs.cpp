//
// Created by Alexandru-Gabriel on 03.12.2023.
//

#include <csv.hpp>
#include "Produs.h"


Produs::Produs(int id, std::string nume, std::string marime, int pret, int stoc, std::string tip_sport,
               const Furnizor &furnizor)
        : ID_produs(id), Nume_produs(std::move(nume)), Marime(std::move(marime)), Pret(pret), Stoc_disponibil(stoc),
          TipSport(tip_sport), furnizorProdus(furnizor) {}


Produs::Produs(const Produs &other)
        : ID_produs(other.ID_produs), Nume_produs(other.Nume_produs), Marime(other.Marime),
          Pret(other.Pret), Stoc_disponibil(other.Stoc_disponibil), furnizorProdus(other.furnizorProdus) {}


Produs &Produs::operator=(const Produs &other)
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
       << produs.Stoc_disponibil
       << " | " << produs.furnizorProdus << " | " << produs.TipSport;
    return os;
}

int Produs::GetID() const
{
    return ID_produs;
}

int Produs::GetPret() const
{
    return Pret;
}

std::string Produs::GetTipSport() const
{
    return TipSport;
}

const Furnizor &Produs::GetFurnizor() const
{
    return furnizorProdus;
}

void Produs::SetPret(int nouPret)
{
    try {
        if (nouPret >= 0)
        {
            Pret = nouPret;
            std::cout << "\nPretul produsului a fost actualizat cu succes." << std::endl;
        }else
            throw "Produsul nu poate fi negativ!";

        }catch (const char* eroare){std::cout << eroare << std::endl;}

}


std::unique_ptr<Produs> Produs::CitesteProduseDinFisier(csv::CSVRow &row)
{
    int id = std::stoi(row["ID_produs"].get<>());
    std::string nume = row["Nume_produs"].get<>();
    std::string marime = row["Marime"].get<>();
    int pret = std::stoi(row["Pret"].get<>());
    int stoc = std::stoi(row["Stoc_disponibil"].get<>());
    Furnizor furnizor(row["NumeFurnizor"].get<std::string>(), row["Adresa"].get<std::string>());
    std::string tipSport = row["Tip_Sport"].get<std::string>();

    auto produsPtr = std::make_unique<Produs>(id,nume,marime,pret,stoc,tipSport,furnizor);
    return produsPtr;
    //Produs(id, nume, marime, pret, stoc, furnizor);
}


