// hash2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{


    int a[5] = { 70,63,22,1,4 };
    int hash[5] = { 0 };

    for (uint8_t x=0;x<5;++x)
    {
        hash[x%10] = a[x];
    }

    std::cout << "Hello World!\n";
}


