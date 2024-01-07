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
    EroareProprietateProdus(const std::string& prop, const std::string &val);
};

class EroareTipEchipament: public EroareProdus
{
public:
   explicit EroareTipEchipament( const std::string& tip);
};


#endif //OOP_EROAREPRODUS_H
