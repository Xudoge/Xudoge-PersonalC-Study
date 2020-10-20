// Search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class TreeNode {

public:

    TreeNode() = default;
    TreeNode(int a) :NodeIndex(a){}


    int NodeIndex=0;
    TreeNode* RightChildNode;
    TreeNode* LeftChildNode;
};

class Tree {

public:
    Tree() = default;
    TreeNode* Root=nullptr;

    void Generate();

};

void Tree::Generate()
{

    //        0
    //     1     4
    //  2     3

    Root = new TreeNode(0);

    Root->RightChildNode = new TreeNode(4);

    Root->LeftChildNode = new TreeNode(1);

    Root->LeftChildNode->LeftChildNode = new TreeNode(2);
    Root->LeftChildNode->RightChildNode = new TreeNode(3);
}

void DFS(TreeNode* node,vector<int>& visited){
    
    if (!node)
    {
        return;
    }

	cout << node->NodeIndex << endl;

	DFS(node->LeftChildNode, visited);
	DFS(node->RightChildNode, visited);
   
}

void DPS_stack(TreeNode* node, vector<int>& visited) {

    stack<TreeNode*> m;
	
    m.push(node);

    while (!m.empty())
    {
 
        cout << m.top()->NodeIndex << endl;
        TreeNode* tempNode = m.top();
        m.pop();

        if (tempNode->RightChildNode)
        {
            m.push(tempNode->RightChildNode);
          
        }

		if (tempNode->LeftChildNode)
		{
			m.push(tempNode->LeftChildNode);

		}
    }

	return;
}


void BFS(TreeNode* node, vector<int>& visited) {

    queue<TreeNode*> m;

    m.push(node);

    while(!m.empty())
    {
        cout << m.front()->NodeIndex << endl;

		TreeNode* tempNode = m.front();
		m.pop();

		if (tempNode->LeftChildNode)
		{
			m.push(tempNode->LeftChildNode);

		}

		if (tempNode->RightChildNode)
		{
			m.push(tempNode->RightChildNode);

		}
    }

}

int main()
{

    vector<int> visited;
    Tree tree;
    tree.Generate();

   // DFS(tree.Root, visited);
   // DPS_stack(tree.Root, visited);
    BFS(tree.Root, visited);

    std::cout << "Hello World!\n";
}


