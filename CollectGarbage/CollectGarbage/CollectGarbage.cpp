// CollectGarbage.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<thread>
#include "WapperClass.h"
using namespace std;

void CGloopCheck() {

}


void WapperCTest(WapperClass<int> c) {


    WapperClass<int> d = c;
    WapperClass<int> f = makeWapper<int>(c);
}

int main()
{

    thread CG(CGloopCheck);
    CG.join();

    OrginInt* newInt = new OrginInt(1);
    //WapperClass<int> a = makeWapper<int>(newInt);
	WapperClass<int> b = makeWapper<int>(newInt);

	WapperCTest(b);

    //a.clear();
    b.clear();
    
    ;
    //std::cout << "Hello World!\n";
}


