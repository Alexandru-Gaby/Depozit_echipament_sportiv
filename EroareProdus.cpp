#include "EroareProdus.h"

EroareProprietateProdus::EroareProprietateProdus(const std::string &prop, const std::string &val) :
EroareProdus(std::string ("Proprietatea ") + prop + " a primit valoarea invalida " + val){}

EroareTipEchipament::EroareTipEchipament(const std::string &tip) : EroareProdus(std::string("Tipul ") +  tip +  " nu exista! "){}
