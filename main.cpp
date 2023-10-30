#include <iostream>
#include <vector>
#include <string>
#include <csv.hpp>

using namespace csv;

//class ComenziAchizitii;

class Furnizor
{
private:
    std::string NumeFurnizor;
    std::string Adresa;

public:
    Furnizor(const std::string& nume, const std::string& adresa)
            : NumeFurnizor(nume), Adresa(adresa) {}

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

    const std::string& GetNume() const
    {
        return NumeFurnizor;
    }

    const std::string& GetAdresa() const
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
    std::vector<Produs*> produseComandate;

public:
    ComenziAchizitii(int numar, const std::string& data)
            : NumarComanda(numar), DataComanda(data) {}

    ComenziAchizitii(const ComenziAchizitii& other)
            : NumarComanda(other.NumarComanda), DataComanda(other.DataComanda)
    {
        for (Produs* produs : other.produseComandate)
        {
            produseComandate.push_back(new Produs(*produs));
        }
    }

    ComenziAchizitii& operator=(const ComenziAchizitii& other)
    {
        if (this == &other) return *this;
        NumarComanda = other.NumarComanda;
        DataComanda = other.DataComanda;

        for (Produs* produs : produseComandate)
        {
            delete produs;
        }
        produseComandate.clear();

        for (Produs* produs : other.produseComandate)
        {
            produseComandate.push_back(new Produs(*produs));
        }
        return *this;
    }

    ~ComenziAchizitii()
    {
        for (Produs* produs : produseComandate)
        {
            delete produs;
        }
        produseComandate.clear();
    }

    friend std::ostream& operator<<(std::ostream& os, const ComenziAchizitii& comanda)
    {
        os << "Numar Comanda: " << comanda.NumarComanda << " | Data Comanda: " << comanda.DataComanda;
        return os;
    }

    void AdaugaProdusComandat(Produs* produs)
    {
        produseComandate.push_back(produs);
    }

   /* std::vector<Produs*> ProduseDinData(const std::string& dataCautata) const
    {
        std::vector<Produs*> produseGasite;
        for (Produs* produs : produseComandate)
        {
            if (produs->GetComandaProdus()->GetDataComanda() == dataCautata)
            {
                produseGasite.push_back(produs);
            }
        }
        return produseGasite;
    }
    */
};

class Produs
{
private:
    int ID_produs;
    std::string Nume_produs;
    std::string Marime;
    int Pret;
    int Stoc_disponibil;
    Furnizor* furnizorProdus;
    ComenziAchizitii* comandaProdus;

public:
    Produs(int id, const std::string& nume, const std::string& marime, int pret, int stoc, Furnizor* furnizor, ComenziAchizitii* comanda)
            : ID_produs(id), Nume_produs(nume), Marime(marime), Pret(pret), Stoc_disponibil(stoc), furnizorProdus(furnizor), comandaProdus(comanda) {}

    Produs(const Produs& other)
            : ID_produs(other.ID_produs), Nume_produs(other.Nume_produs), Marime(other.Marime),
              Pret(other.Pret), Stoc_disponibil(other.Stoc_disponibil), furnizorProdus(other.furnizorProdus), comandaProdus(other.comandaProdus) {}

    Produs& operator=(const Produs& other)
    {
        if (this == &other) return *this;
        ID_produs = other.ID_produs;
        Nume_produs = other.Nume_produs;
        Marime = other.Marime;
        Pret = other.Pret;
        Stoc_disponibil = other.Stoc_disponibil;
        furnizorProdus = other.furnizorProdus;
        comandaProdus = other.comandaProdus;
        return *this;
    }

    ~Produs() {}

    friend std::ostream& operator<<(std::ostream& os, const Produs& produs)
    {
        os << "ID Produs: " << produs.ID_produs << " | Nume Produs: " << produs.Nume_produs
           << " | Marime: " << produs.Marime << " | Pret: " << produs.Pret << " RON | Stoc Disponibil: " << produs.Stoc_disponibil;
        return os;
    }

    void SetPret(int nou_pret)
    {
        if (nou_pret >= 0)
        {
            Pret = nou_pret;
            std::cout << "Pretul produsului a fost actualizat cu succes." << std::endl;
        }
        else
        {
            std::cout << "Pretul nu poate fi negativ." << std::endl;
        }
    }

    void Actualizare_Stoc(int cantitatea_noua)
    {
        if (cantitatea_noua >= 0) Stoc_disponibil = cantitatea_noua;
        else std::cout << "Cantitatea noua nu este valida" << std::endl;
    }

    void Afisare() const
    {
        std::cout << *this << " | Furnizor: " << *furnizorProdus << " | Comanda: " << *comandaProdus;
    }

    ComenziAchizitii* GetComandaProdus() const
    {
        return comandaProdus;
    }
};

int main()
{
    std::ifstream file("date.csv");
    CSVFormat format;
    format.delimiter(';');

    CSVReader reader(file, format);

    std::vector<Furnizor> furnizori;
    std::vector<ComenziAchizitii> comenzi;
    std::vector<Produs> produse;

    for (CSVRow& row : reader) 
    {
        int id = std::stoi(row["ID_produs"]);
        std::string nume = row["Nume_produs"];
        std::string marime = row["Marime"];
        int pret = std::stoi(row["Pret"]);
        int stoc = std::stoi(row["Stoc_disponibil"]);

        Furnizor furnizor("NumeFurnizor", "AdresaFurnizor");
        ComenziAchizitii comanda(1, "DataComanda");

        Produs produs(id, nume, marime, pret, stoc, &furnizor, &comanda);
    }

    return 0;
}
