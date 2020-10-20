// BubbleSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "FastSort.h"


using namespace std;
#define N 5




int main()
{

    int a[N] = { 1,4,3,2,1 };
   
    FastSort(a,N);

    int x = 0;
    while(x<N)
    {
        cout << a[x] << ",";
        ++x;
    }
}

