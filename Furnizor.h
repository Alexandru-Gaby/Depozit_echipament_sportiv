//
// Created by Alexandru-Gabriel on 03.12.2023.
//

#ifndef OOP_FURNIZOR_H
#define OOP_FURNIZOR_H


#include <string>

class Furnizor
{
private:
    std::string NumeFurnizor;
    std::string AdresaFurnizor;

public:
    Furnizor()= default;

    Furnizor(std::string numefurnizor, std::string adresa);


    Furnizor(const Furnizor &other);

    Furnizor &operator=(const Furnizor &other);


    ~Furnizor() = default;

    friend std::ostream &operator<<(std::ostream &os, const Furnizor &furnizor);

    friend std::istream &operator>>(std::istream &is, Furnizor &furnizor);



    void initializare(const std::string &numefurnizor, const std::string &adresa);


};


#endif //OOP_FURNIZOR_H
