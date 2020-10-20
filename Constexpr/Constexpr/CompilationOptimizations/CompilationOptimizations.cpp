// CompilationOptimizations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


//模板求和 编译器常量
template< int... last>
struct Sum; 

template<int frist, int... last>
struct Sum<frist, last...> {
	enum {
		Value = Sum<frist>::Value + Sum<last...>::Value
	};
};

template<int t>
struct Sum<t> {
	enum  { Value =t};
};


struct MyStruct
{
	typedef int vector[10];
};


int main()
{

	Sum<1, 2, 3, 4, 5>* sum = new Sum<1, 2, 3, 4, 5>();

	cout << sum->Value<< endl;

	///MyStruct::vector[1]=1;


	//编译优化
	//编译器能根据编译期常量来实现各种不同的优化。
	//比如，如果在一个if判断语句中，其中一个条件是编译期常量，编译器知道在这个判断句中
	//一定会走某一条路，那么编译器就会把这个if语句优化掉，留下只会走的那一条路。

	


	if (sizeof(void*)==4)
	{
		std::cout << "Hello World!\n";
	}
	else
	{
		std::cout << "Hello nImabi!\n";
	}


   
}

