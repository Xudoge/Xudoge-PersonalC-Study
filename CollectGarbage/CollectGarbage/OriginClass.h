#pragma once

#include <iostream>


template<typename T>
class OriginClass
{

public:
	OriginClass() = default;
	OriginClass(T t):baseValue(t),Flags(1){}

	T GetValue() const;
	T SetValue(const T& t);


private:
	T baseValue;

	//被引用计数
	uint8_t Flags = 0;
	
};

typedef OriginClass<int> OrginInt;



