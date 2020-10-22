#include "pClass.h"

#include <iostream>

pClass::pChildClass::pChildClass()
{
	std::cout << "pChildClass init\n";
}

pClass::pChildClass pClass::pChildClass::pCClass;