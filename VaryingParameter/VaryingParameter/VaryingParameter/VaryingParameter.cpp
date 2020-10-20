// VaryingParameter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdarg.h>

using namespace std;

//可变参数函数
void test1(int count, ...) {
    va_list ap;

    va_start(ap, count);
    for (unsigned i=0;i<count;++i)
    {
        cout << va_arg(ap,int) << endl;
    }
    va_end(ap);

}







//可变参数模板
template<class T, class... Args>
void test2(T t, Args... rests) {
    cout << t << endl;
    test2(rests...);
}
//可变参数模板---递归终止函数
void test2() {
	cout << "empty" << endl;
}


//可变参数模板--逗号表达式
template<class T>
T test2_1(T t) {
    cout <<t <<endl;
    return t;
}

template<class... Args>
void test2_2(Args...args) {
    int arr[] = { (test2_1(args), 0)... };
}

template<class T, class... Args>
void test2_2(Args...args) {
    T arr[] = { (test2_1(args), 0)... };
}





//可变参数模板偏特化
template<int... indexs>
struct IntSeq {

};

template<int T,int... indexs>
struct makeIndex:makeIndex<T - 1, T - 1, indexs...> {

};

template<int... indexs>
struct makeIndex <0, indexs...> {

    typedef IntSeq<0, indexs...>  types;
};





int main()
{
    test1(4,1, 2, 3, 4);
    cout << "\n";
    //test2<int, int, int>(1, 2, 3);
    test2_2(1, 2, 3);
    test2_2<char>("a", "a", "a");


    makeIndex<4>::types a;
    cout << typeid(a).name() << endl;
}

