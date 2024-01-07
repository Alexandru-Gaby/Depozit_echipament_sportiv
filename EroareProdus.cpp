#include "EroareProdus.h"
#include <string>

EroareProprietateProdus::EroareProprietateProdus(const std::string &prop, const std::string &val) :
EroareProdus("Proprietatea " + prop + " a primit valoarea invalida " + val){}

EroareTipEchipament::EroareTipEchipament(const std::string &tip) : EroareProdus("Tipul " +  tip +  " nu exista! "){}
