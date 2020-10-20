// Constexpr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stdarg.h>
using namespace std;



// 运行时期确定 行列宽
class Martix
{

public:
    Martix() = default;
    Martix(int row, int col):colCount(col),rowCount(row){}


    int colCount=0;
    int rowCount = 0;

    vector<int> value;
   
    void setValue(int count,...) {
        va_list valist;
        int num=0;
        va_start(valist, count);
        for (int i=0;i<count;i++)
        {
            num= va_arg(valist, int);
            value.push_back(num);
        }
        va_end(valist);
    }

    
};

// 编译时期确定 行列宽  
template<int row,int col>
class MartixT {

public:
    MartixT() = default;

    vector<int> value;


   /* template <int val, int... vals>
	void setValue(int head, vals... args) {
        value.push_back(head);
        setValue(args...);
	}*/

};


int main()
{
    Martix* ma1 = new Martix(2, 2);  
    ma1->setValue(4,1, 1, 1, 1);
    
    
    MartixT<2,2>* ma1T = new MartixT<2, 2>();   //矩阵中也没必要花费空间去存储矩阵的行数和列数了
   /* ma1T->setValue<1,2,3,4>();*/




    unsigned int intlength = sizeof(int);
}
