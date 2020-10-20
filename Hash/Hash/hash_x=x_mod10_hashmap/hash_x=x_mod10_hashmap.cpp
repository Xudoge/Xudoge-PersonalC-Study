// hash_x=x_mod10_hashmap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


class HashNode {

public:
	HashNode() = default;
	HashNode(int a) :value(a) {};
	int value;

	HashNode* next;
};

class HashHead {
public:
    HashNode* next;
};



class HashMap {

public:
    HashHead hashtable[10];

    void Insert(int a);
    void Delete(int a);

    bool Find(int a);
};

void HashMap::Insert(int a)
{
    if (Find(a))
    {
        std::cout << "未成功输入：" << a << "\n";
        return;
    }
   
    if (hashtable[a%10].next!=nullptr)
    {
        HashNode* newNode = new HashNode(a);
        newNode->next = hashtable[a % 10].next;

        hashtable[a % 10].next = newNode;

        std::cout << "成功输入："<<a<<"\n";
    }
    else
    {
		HashNode* newNode = new HashNode(a);
        

        hashtable[a % 10].next = newNode;

        std::cout << "成功输入：" << a << "\n";

    }
}

void HashMap::Delete(int a)
{
	if (hashtable[a % 10].next != nullptr)
	{
        HashNode* preNode = nullptr;
		for (HashNode* Node = hashtable[a % 10].next; Node != nullptr; Node = Node->next)
		{
			if (a == Node->value)
			{
				if (preNode)
				{
                    preNode->next = Node->next;
                    delete(Node);

                    std::cout << "成功删除：" << a << "\n";

                    return;
                }
                else
                {
                    hashtable[a % 10].next = Node->next;
                    delete(Node);

					std::cout << "成功删除：" << a << "\n";

					return;
                }
			}
            preNode = Node;
		}
	}

    std::cout << "未删除：" << a << "\n";
}

bool HashMap::Find(int a)
{
	if (hashtable[a % 10].next != nullptr)
	{
		for (HashNode* Node = hashtable[a % 10].next; Node != nullptr; Node = Node->next)
		{
            if (a== Node->value)
            {
                std::cout << "成功找到：" << a << "\n";
                return true;
            }
		}
	}
	
    std::cout << "未找到：" << a << "\n";
    return false;
}

int main()
{
    HashMap* map = new HashMap();

    map->Insert(100);
    map->Insert(10);
    map->Insert(1000);
    map->Insert(10);


    map->Delete(10);
    map->Delete(1000);

    map->Find(100);

    std::cout << "Hello World!\n";
}

