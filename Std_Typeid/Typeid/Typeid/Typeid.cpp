// Typeid.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Base {

};

int main()
{
    Base n;

   
    const char * a= "class Base";

    //std::cout << typeid(n).name() << "\n";

   if (typeid(n).name() == a)
   {
       std::cout << "true"<< "\n";
   }

   if (typeid(n).name() == typeid(Base).name())
   {
	   std::cout << "true" << "\n";
   }
   

   return 0;
}

