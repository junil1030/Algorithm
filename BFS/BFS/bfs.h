#pragma once
#include <list>
#include <map>

class C_BFS
{
private:
	struct S_NODE
	{
		int nId;
		std::list<std::map<int, S_NODE>::iterator> listIter;
		bool bVisit;
	};
private:
	std::map<int, S_NODE> m_mapNode;
	std::map<int, S_NODE>::iterator createNode(int nId);

public:
	C_BFS() = default;
	void add(int nDst, int nSrc);
	void print();
	void run();
};