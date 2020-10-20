// Template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


enum Color {
   RED,
   BLUE,
   GREEN
};


//模板特化模板中的编译期常量
//除了类型以外，数字也可以作为模板的参数。这些数值变量包括int，long，short，bool，char和弱枚举enum等。
template<Color color>
struct  ColorAllor
{
    
    
};

struct Empty {

};

int main()
{
   

    ColorAllor<RED>* color = new ColorAllor<RED>();
    Empty* empty = new Empty();

    cout << sizeof(*color) << endl;
    cout << sizeof(*empty) << endl;
}


