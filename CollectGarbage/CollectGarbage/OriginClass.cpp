#include "OriginClass.h"



template<typename T>
T OriginClass<T>::GetValue() const
{
	return baseValue;
}

template<typename T>
T OriginClass<T>::SetValue(const T& t)
{
	baseValue = t;
}


