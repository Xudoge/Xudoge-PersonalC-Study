// Const.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


//静态成员变量
struct SomeStruct {
	static unsigned const size1 = 44;  //编译期常量
	enum { size2 = 45 };  //编译期常量
	int someIntegers[size1];  //常量表达式，在编译期计算
	double someDoubles[size2]; //常量表达式，在编译期计算
};


int main()
{
	//任何不是用户自己定义的——而必须通过编译期计算出来的字面量都属于编译期常量表达式


    const int i = 1;//常量 非编译期常量

    const int j = i * 2;//常量 非编译期常量

    const int m = i * 2;//常量表达式 编译期常量
    int marray[m] = {};  //数组长度需要在编译期确定



}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
