// reinterpret_cast.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


class test1{
public:
    short a;
    short b;

};



int main()
{
   // BYTE val[8] = { 1,0,0,0,1,0,0,0 };
    unsigned long b = 0x00010001;

    test1* a = reinterpret_cast<test1*>(&b);

    std::cout << "Hello World!\n";
}

