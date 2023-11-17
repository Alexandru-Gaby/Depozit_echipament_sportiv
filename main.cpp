#include <iostream>
#include <vector>
#include <string>
#include <csv.hpp>
//#include <algorithm>

using namespace csv;


class Furnizor
{
private:
    std::string NumeFurnizor;
    std::string Adresa;

public:
    Furnizor(std::string  nume, std::string  adresa)
            : NumeFurnizor(std::move(nume)), Adresa(std::move(adresa)) {}

    Furnizor(const Furnizor& other)
            : NumeFurnizor(other.NumeFurnizor), Adresa(other.Adresa) {}

    Furnizor& operator=(const Furnizor& other)
    {
        if (this == &other) return *this;
        NumeFurnizor = other.NumeFurnizor;
        Adresa = other.Adresa;
        return *this;
    }

    ~Furnizor() = default;

    friend std::ostream& operator<<(std::ostream& os, const Furnizor& furnizor)
    {
        os << "Nume Furnizor: " << furnizor.NumeFurnizor << " | Adresa: " << furnizor.Adresa;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Furnizor& furnizor)
    {
        is >> furnizor.NumeFurnizor >> furnizor.Adresa;
        return is;
    }

    const std::string &GetNume() const
    {
        return NumeFurnizor;
    }

    const std::string &GetAdresa() const
    {
        return Adresa;
    }
};

class Produs;

class ComenziAchizitii
{
private:
    int NumarComanda;
    std::string DataComanda;
    std::vector<Produs> produseComandate;

public:
    ComenziAchizitii(int numar, std::string data)
            : NumarComanda(numar), DataComanda(std::move(data)) {}

    ComenziAchizitii(const ComenziAchizitii &other)
            : NumarComanda(other.NumarComanda), DataComanda(other.DataComanda),
              produseComandate(other.produseComandate) {}

    ComenziAchizitii &operator=(const ComenziAchizitii &other)
    {
        if (this == &other) return *this;
        NumarComanda = other.NumarComanda;
        DataComanda = other.DataComanda;
        produseComandate = other.produseComandate;

        return *this;
    }

    ~ComenziAchizitii() = default;

    friend std::ostream &operator<<(std::ostream &os, const ComenziAchizitii &comanda)
    {
        os << "Numar Comanda: " << comanda.NumarComanda << " | Data Comanda: " << comanda.DataComanda;
        return os;
    }

    void AdaugaProdus(const Produs &produs)
    {
        produseComandate.push_back(produs);
    }


};

class Produs
{
private:
    int ID_produs;
    std::string Nume_produs;
    std::string Marime;
    int Pret;
    int Stoc_disponibil;
    Furnizor furnizorProdus;


public:
    Produs(int id,std::string  nume, std::string  marime, int pret, int stoc, const Furnizor &furnizor)
            : ID_produs(id), Nume_produs(std::move(nume)), Marime(std::move(marime)), Pret(pret), Stoc_disponibil(stoc), furnizorProdus(furnizor){}


    Produs(const Produs& other)
            : ID_produs(other.ID_produs), Nume_produs(other.Nume_produs), Marime(other.Marime),
              Pret(other.Pret), Stoc_disponibil(other.Stoc_disponibil), furnizorProdus(other.furnizorProdus){}

    Produs& operator = (const Produs& other)
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


    ~Produs() = default;

    friend std::ostream& operator<<(std::ostream& os, const Produs &produs)
    {
        os << "ID Produs: " << produs.ID_produs << " | Nume Produs: " << produs.Nume_produs
           << " | Marime: " << produs.Marime << " | Pret: " << produs.Pret << " RON | Stoc Disponibil: " << produs.Stoc_disponibil
           << " | " << produs.furnizorProdus;
        return os;
    }

    int GetID() const
    {
        return ID_produs;
    }
    int GetPret() const
    {
        return Pret;
    }

    const Furnizor &GetFurnizor() const
    {
        return furnizorProdus;
    }

    void SetPret(int nouPret)
    {
        if (nouPret >= 0)
        {
            Pret = nouPret;
            std::cout << "Pretul produsului a fost actualizat cu succes." << std::endl;
        }
        else
        {
            std::cout << "Pretul nu poate fi negativ." << std::endl;
        }
    }
    /*
    static void Afisare_Produse(const std::vector<Produs> &produse)
    {
        for (const Produs &produs: produse)
        {
            std::cout << produs << std::endl;
            std::cout
                    << "---------------------------------------------------------------------------------------------------------------------"
                    << std::endl;

        }
    }
    */
    static Produs CitesteProduseDinFisier(const CSVRow& row)
    {
        int id = std::stoi(row["ID_produs"].get<>());
        std::string nume = row["Nume_produs"].get<>();
        std::string marime = row["Marime"].get<>();
        int pret = std::stoi(row["Pret"].get<>());
        int stoc = std::stoi(row["Stoc_disponibil"].get<>());
        Furnizor furnizor(row["NumeFurnizor"].get<std::string>(), row["Adresa"].get<std::string>());

        return Produs(id, nume, marime, pret, stoc, furnizor);
    }


};
class Depozit
{
private:
    std:: vector<Produs> produseDepozit;

public:

    void Adauga_produs(const Produs &produs)
    {
        produseDepozit.push_back(produs);
    }

    void Sortare_produse_dupa_pret()
    {
        std::sort(produseDepozit.begin(), produseDepozit.end(), [] (const Produs &a, const Produs &b)
        {
            return a.GetPret() < b.GetPret();
        });
    };

    void AfiseazaProduse()
    {
        for (const Produs &produs : produseDepozit)
        {
            std::cout << produs << std::endl;
            std::cout << "---------------------------------------------------------------------------------------------------------------------" << std::endl;
        }
    }

    void ActualizarePret(int ID_produs, int Pret_nou)
    {
     for(Produs &produs : produseDepozit)
     {
         if(produs.GetID() == ID_produs )
         {
             produs.SetPret(Pret_nou);
             break;
         }
     }
    }


};

int main()
{
    std::ifstream file("date.csv");
    CSVFormat format;
    format.delimiter(';');
    CSVReader reader(file, format);

    std::vector<Produs> produse;
    Depozit depozit;

    for (CSVRow &row : reader)
    {
        Produs produs = Produs::CitesteProduseDinFisier(row);
        produse.push_back(produs);
        depozit.Adauga_produs(produs);

        std::cout << "Nume Furnizor: " << produs.GetFurnizor().GetNume() << std::endl;
        std::cout << "Adresa Furnizor: " << produs.GetFurnizor().GetAdresa() << std::endl;
    }


    ComenziAchizitii comanda(100, "02/11/2023");

    Furnizor furnizor1("Nike", "Adresa1");
    Furnizor furnizor2("New Balance", "Adresa2");


    Produs produs1(1, "NumeProdus1", "Marime1", 50, 10, furnizor1);
    Produs produs2(2, "NumeProdus2", "Marime2", 60, 15, furnizor2);


    comanda.AdaugaProdus(produs1);
    comanda.AdaugaProdus(produs2);

    depozit.ActualizarePret(1,100);
    int idProdusDeModificat = 1;
    int noulPret = 100;

    for (Produs &produs: produse)
    {
        if (produs.GetID() == idProdusDeModificat)
        {
            produs.SetPret(noulPret);
            std::cout << "\n Pretul produsului cu ID " << idProdusDeModificat << " a fost actualizat cu succes."
                      << std::endl;
            std::cout
                    << "---------------------------------------------------------------------------------------------------------------------"
                    << std::endl;
            break;
        }
    }

    std::cout << "Detalii produse dupa actualizare:" << std::endl;

    depozit.Sortare_produse_dupa_pret();
    depozit.AfiseazaProduse();
    //Produs::Afisare_Produse(produse);

    return 0;
}