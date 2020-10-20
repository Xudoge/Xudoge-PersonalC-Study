// thread.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
using namespace std;

static int a = 0;
static bool b = true;
void t1() {


	while (1)
	{
		if (b)
		{
			cout << "a++ =" << a++ << endl;
			b = !b;
		}
	}

}

void t2() {

	while (1)
	{
		if (!b)
		{
			cout << "a++ =" << a++ << endl;
			b = !b;
		}

		
	}
}


int main()
{
	thread th1(t1);
	thread th2(t2);

	th1.join();
	th2.join();

	return 0;
}