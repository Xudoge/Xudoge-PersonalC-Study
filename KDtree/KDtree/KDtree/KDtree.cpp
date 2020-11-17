// KDtree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#define RANGE 15
#define SAMPLECOUNT 10

struct Coord {
    float x;
    float y;
};


struct KDTreeNode
{
    Coord coord;
    int SegDimen;

    KDTreeNode* LeftTreeNode;
    KDTreeNode* RightTreeNode;
};


KDTreeNode* CreateKDTree(const std::vector<Coord>& value,int SegDimen) {
    

    std::sort(value.begin(), value.end(), [](const Coord ) {})
    

    return nullptr;
}


int main()
{
    std::vector<Coord> coord;
    
    //填充数据
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0u, 1500u);
    for (unsigned int i=1;i<SAMPLECOUNT;++i)
    {

        float randomX = ((float)u(e))/100;
        float randomY = ((float)u(e)) / 100;
        Coord c = { randomX,randomY };
        std::cout << "随机坐标值:" << c.x << " " << c.y << std::endl;
        coord.push_back(std::move(c));
    }





    std::cout << "Hello World!\n";
}


