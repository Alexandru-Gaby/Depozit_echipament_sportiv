//
// Created by Alexandru-Gabriel on 03.12.2023.
//

#ifndef OOP_FURNIZOR_H
#define OOP_FURNIZOR_H


#include <string>

class Furnizor {
private:
    std::string NumeFurnizor;
    std::string Adresa;

public:
    Furnizor(){};

    Furnizor(std::string nume, std::string adresa);

    Furnizor(const Furnizor &other);

    Furnizor &operator=(const Furnizor &other);


    ~Furnizor() = default;

    friend std::ostream &operator<<(std::ostream &os, const Furnizor &furnizor);

    friend std::istream &operator>>(std::istream &is, Furnizor &furnizor);

    const std::string &GetNume() const;

    const std::string &GetAdresa() const;;
};


#endif //OOP_FURNIZOR_H
