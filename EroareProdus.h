#ifndef OOP_EROAREPRODUS_H
#define OOP_EROAREPRODUS_H

#include <stdexcept>

class EroareProdus: public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

class EroareProprietateProdus : public EroareProdus
{
public:
    EroareProprietateProdus(const std::string& prop, const std::string &val) : EroareProdus(std::string ("Proprietatea ") + prop + " a primit valoarea invalida " + val){}
};

class EroareTipEchipament: public EroareProdus
{
public:
   explicit EroareTipEchipament( const std::string& tip) : EroareProdus(std::string("Tipul ") +  tip +  " nu exista! "){}
};


#endif //OOP_EROAREPRODUS_H
