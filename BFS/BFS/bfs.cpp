#include <queue>
#include "BFS.h"

std::map<int, C_BFS::S_NODE>::iterator C_BFS::createNode(int nId)
{
	S_NODE sNew{};
	sNew.nId = nId;

	return m_mapNode.insert({ nId, sNew }).first;
}

void C_BFS::add(int nDst, int nSrc)
{
	auto iterDst = createNode(nDst);
	auto iterSrc = createNode(nSrc);

	iterDst->second.listIter.push_back(iterSrc);
	iterSrc->second.listIter.push_back(iterDst);
}

void C_BFS::print()
{
	for (std::map<int, S_NODE>::iterator iter = m_mapNode.begin(); iter != m_mapNode.end(); iter++)
	{
		printf("id: %d - ", iter->first);
		std::list<std::map<int, S_NODE>::iterator>::iterator iterList = iter->second.listIter.begin();
		while (iterList != iter->second.listIter.end())
		{
			printf("%d ", (*iterList)->first);
			iterList++;
		}
		printf("\n");
	}
}

void C_BFS::run()
{
	std::queue<std::map<int, S_NODE>::iterator> queueIter{};

	queueIter.push(m_mapNode.find(0));

	while (!queueIter.empty())
	{
		std::map<int, S_NODE>::iterator iterNode = queueIter.front();
		queueIter.pop();
		iterNode->second.bVisit = true;
		printf("%d\n", iterNode->first);
		std::list<std::map<int, S_NODE>::iterator>::iterator iterChild{};
		iterChild = iterNode->second.listIter.begin();

		while (iterChild != iterNode->second.listIter.end())
		{
			if (!(*iterChild)->second.bVisit)
			{
				queueIter.push(*iterChild);
				(*iterChild)->second.bVisit = true;
			}
			iterChild++;
		}
	}
}