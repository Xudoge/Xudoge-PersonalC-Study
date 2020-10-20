// Hash.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>




//自然数N(1<n<100)  70 60 20 1 5
//判断7 在不在里面

int main()
{
    int a[100] = {0};

    a[70] = 1; a[60] = 1; a[20] = 1; a[1] = 1; a[5] = 1;


    int N = 7;
    if (a[N]==1)
    {
        std::cout << "5 have it\n";
    }
    else
    {
        std::cout << "5 do not have it\n";
    }

   
}


