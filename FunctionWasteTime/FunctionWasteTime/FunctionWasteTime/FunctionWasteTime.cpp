// FunctionWasteTime.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h> 
#include <thread>
#include <limits>
using namespace std;


static double scount= (std::numeric_limits<double>::min)();

static double max = (std::numeric_limits<double>::max)();

void Count() {
    while ( scount != max) {

    
        scount += 1e-300;

    }
}



static void sfun(){

}

class TestClass {

public:
    void fun() {

    }

    virtual void vfun() {

    }
};


int main()
{
    std::cout << "Hello World!\n";

    SYSTEMTIME sys;
    GetLocalTime(&sys);
    
    thread th1(Count);
    
	cout.precision(20);
    //cout.setf(ios::fixed);

    TestClass* tc = new TestClass();
    
    cout << scount << endl;
    sfun();
    cout << scount << endl;
    tc->fun();
    cout << scount << endl;
    tc->vfun();
    cout << scount << endl;


    th1.join();
}

