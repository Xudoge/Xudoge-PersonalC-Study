// Constexpr_.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//常量表达式  可以在编译和运行期使用
//在函数中只能调用其他constexpr函数，该函数也不能有任何运行时才会有的行为,不能有try块，以及任何static和局部线程变量
constexpr unsigned int fibonacci(unsigned int i) {
    //注意的是，在编译期调用constexpr函数，所有运行时所做的检查，在编译期均不会处理。
    //最常见的问题就是int溢出的问题，此时我们还应该在代码中手动加上相应的检查：

	if (i > std::numeric_limits<unsigned int>::max())
	{
		throw std::invalid_argument("fibonacci i overflow");
	}

	if (i < std::numeric_limits<unsigned int>::min())
	{
		throw std::invalid_argument("fibonacci i overflow");
	}

    return (i <= 1u) ? i : (fibonacci(i - 1) + fibonacci(i - 2));
}


//正常类 只能在运行期确定值
class Point {
public:
	Point() = default;
	Point(unsigned int x, unsigned int y) :x(x), y(y) {}

    unsigned int X() const { return x; }
    void X(unsigned int val) { x = val; }
    unsigned int Y() const { return y; }
    void Y(unsigned int val) { y = val; }

private:
    unsigned int x;
    unsigned int y;
};

//consrexper类 能在编译期取值
class ConstPoint {
public:
    ConstPoint() = default;
    constexpr ConstPoint(unsigned int x, unsigned int y) :x(x), y(y) {}

    constexpr unsigned int X() const { return x; }
    constexpr void X(unsigned int val) { x = val; }
    constexpr unsigned int Y() const { return y; }
    constexpr void Y(unsigned int val) { y = val; }

private:
	unsigned int x;
	unsigned int y;
};



int main()
{
    int h = -8e+9;
    int v = fibonacci(h);

    int a[fibonacci(8)] = {};

    Point point(1,2);
    //int a2[point.X()];  point不是编译期常量


    //constexpr 修饰的变量
    constexpr ConstPoint constpoint(1, 2);
    int a2[constpoint.X()] = {};

    

    std::cout << sizeof(double)  << sizeof(1) <<"\n";
}

