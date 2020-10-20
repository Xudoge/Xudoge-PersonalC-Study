// vritual.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stddef.h>
using namespace std;


class Base1_f {

public:
	int a;
	short f;
	double b;
	short c;
};


class Base2_f {

public:
	int a;
	short fb;
	short b;
	double c;
};


class Base {

public:
	char a;
	char b;

	virtual void foo() {
	}

	virtual int foo2(int& a) {
		return 1;
	}

};


class Base2 {

public:
	char a;
	char b;

	virtual void foo() {
	}

	virtual int foo2(int& a) {
		return 1;
	}

};

class Base3 {

public:
	char a;
	char b;



};


class Derive1 :public Base {

public:
	virtual void foo() override{
	}

	virtual void tttt() {

	}
};

class Derive1_t :public Base {

public:
	virtual void foo() override {
	}

	virtual void tttt() {

	}
};
	
class Derive2 :public Derive1 {

	virtual void tttt() override{

	}
};
	
class Derive3 :public Base3, public Base2 {

public:
	int f;
};


int main()
{
	//内存对齐
	/*cout << "size:" << sizeof(Base1_f) << endl;
	cout << "size:" << sizeof(Base2_f) << endl;*/

    

	//虚函数

	cout<< "size:" << sizeof(Derive3) << endl;
	cout << "offset:" << offsetof(Derive3, f) << endl;
	//cout << "offset:" << offsetof(Base, b) << endl;

	Base* a = new Base();

	Derive1* b = new Derive1();

	Base* c = static_cast<Base*>(b);

	Derive2* d = new Derive2();

	Derive2 f;

	Derive3* g = new Derive3();
	 
	Derive1_t* h = new Derive1_t();

	
}

