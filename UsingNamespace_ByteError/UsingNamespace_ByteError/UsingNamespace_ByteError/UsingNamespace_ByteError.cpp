// UsingNamespace_ByteError.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


namespace A{
    typedef unsigned char byte;
}

using namespace A;

typedef char byte;

int main()
{
    

    byte a[2] = {};

    std::cout << "Hello World!\n";
}

