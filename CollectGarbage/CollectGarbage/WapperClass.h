#pragma once
#include "OriginClass.h"
#include "WapperMap.h"


using namespace std;

template<typename T>
class WapperClass
{

public:


	WapperClass() = default;

	//正常将基础类型制作成智能指针类
	WapperClass(OriginClass<T>* t):orgin(t){
		orginaddress = (int)t;
	}

	//
	WapperClass(OriginClass<T>* t,bool isTemp=false) :orgin(t),isTemp(isTemp) {
		orginaddress = (int)t;
	}

	//重写拷贝函数
	WapperClass(const WapperClass& t) {
		if (!isTemp)
		{
			copy(t);
		}
		orgin = t.orgin;
		orginaddress = t.orginaddress;
		isTemp = t.isTemp;
	}

	WapperClass& operator=(const WapperClass& t) {

		if (!isTemp)
		{
			copy(t);
		}
		
		orgin = t.orgin;
		orginaddress = t.orginaddress;
		isTemp = t.isTemp;

		return *this;
	}


	~WapperClass() {
		if (!isTemp)
		{
			clear();
		}
		
	}

	void clear() {
		if (orgin)
		{
			int ptraddress = (int)orgin;
			auto Wapperitor = find_if(WapperMap.begin(), WapperMap.end(), [ptraddress](pair<const int, int>& element) {return element.first == ptraddress; });
			if (Wapperitor != WapperMap.end())
			{
				Wapperitor->second--;
				cout << "这个空间" << ptraddress << "地址的引用计算减少到" << Wapperitor->second << endl;
				if (Wapperitor->second == 0)
				{
					delete(orgin);
					orgin = nullptr;	
				}
			}
			else {

			}
		}
	}

	void copy(const WapperClass& t) {
		int ptraddress = (int)t.orgin;
		auto Wapperitor = find_if(WapperMap.begin(), WapperMap.end(), [ptraddress](pair<const int, int>& element) {return element.first == ptraddress; });
		if (Wapperitor != WapperMap.end())
		{
			Wapperitor->second++;
			cout << "这个空间" << ptraddress << "地址的引用计算增到" << Wapperitor->second << endl;

		}
		else
		{
			WapperMap.insert(pair<int, int>(ptraddress, 1));
			cout << "这个空间" << ptraddress << "地址的引用计算增到" << 1 << endl;
		}
	}


	OriginClass<T>* orgin;
	int orginaddress;
	bool isTemp = false;
};


//创建制作智能指针
template<typename T>
static WapperClass<T> makeWapper(OriginClass<T>* t) {
	//isTemp设置为true,暂时标记为临时创建的变量
	WapperClass<T> wclass = WapperClass<T>(t,true);

	int ptraddress = (int)t;
	auto Wapperitor = find_if(WapperMap.begin(), WapperMap.end(), [ptraddress](pair<const int, int>& element) {return element.first == ptraddress; });
	if (Wapperitor != WapperMap.end())
	{
		Wapperitor->second++;
		cout << "这个空间" << ptraddress << "地址的引用计算增到" << Wapperitor->second << endl;

	}
	else
	{
		WapperMap.insert(pair<int, int>(ptraddress, 1));
		cout << "这个空间" << ptraddress << "地址的引用计算增到" << 1 << endl;
	}

	wclass.isTemp = false;
	//由于makeWapper导致的计算+1
	//这里还会进行一次，拷贝函数的+1
	//然后标记为false后执行一次-1
	//所以总系数为+1
	return wclass;
}

template<typename T>
static  WapperClass<T> makeWapper(WapperClass<T> t) {
	OriginClass<T>* o = t.orgin;
	WapperClass<T> wclass = WapperClass<T>(o, true);

	int ptraddress = (int)o;
	auto Wapperitor = find_if(WapperMap.begin(), WapperMap.end(), [ptraddress](pair<const int, int>& element) {return element.first == ptraddress; });
	if (Wapperitor != WapperMap.end())
	{
		Wapperitor->second++;
		cout << "这个空间" << ptraddress << "地址的引用计算增到" << Wapperitor->second << endl;

	}
	else
	{
		WapperMap.insert(pair<int, int>(ptraddress, 1));
		cout << "这个空间" << ptraddress << "地址的引用计算增到" << 1 << endl;
	}

	wclass.isTemp = false;
	return wclass;
}