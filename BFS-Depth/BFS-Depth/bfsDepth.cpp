#include <queue>
#include "BFSDepth.h"

C_BFS::S_NODE* C_BFS::createNode(int nId)
{
    S_NODE* pNew = new S_NODE{};
    pNew->nId = nId;

    return pNew;
}

C_BFS::S_NODE* C_BFS::insertNode(int nId)
{
    auto iterResult = m_mapNode.insert({ nId, nullptr });
    if (iterResult.second)
        iterResult.first->second = createNode(nId);

    return iterResult.first->second;
}

bool C_BFS::add(int nDst, int nSrc)
{
    S_NODE* pDst = insertNode(nDst);
    S_NODE* pSrc = insertNode(nSrc);

    if (!pDst->setChild.insert(pSrc).second)
        return false;

    if (!pSrc->setChild.insert(pDst).second)
        return false;

    return true;
}

void C_BFS::print()
{
    for (std::map<int, S_NODE*>::iterator iter = m_mapNode.begin(); iter != m_mapNode.end(); iter++)
    {
        printf("%d: ", iter->first);
        for (S_NODE* pNode : iter->second->setChild)
        {
            printf("%d ", pNode->nId);
        }
        printf("\n");
    }
}

void C_BFS::run(int nId)
{
    S_NODE* pNode{};

    auto iterFind = m_mapNode.find(nId);
    if (m_mapNode.find(nId) == m_mapNode.end())
        return;

    pNode = iterFind->second;
    std::queue<S_NODE*> qBuffer{};
    pNode->bVisit = true;
    qBuffer.push(pNode);

    int nDepth{};
    while (!qBuffer.empty())
    {
        int nCount = qBuffer.size();

        for (int i = 0; i < nCount; i++)
        {
            pNode = qBuffer.front();
            qBuffer.pop();

            printf("%d\n", pNode->nId);
            for (S_NODE* pChild : pNode->setChild)
            {
                if (!pChild->bVisit)
                {
                    pChild->bVisit = true;
                    qBuffer.push(pChild);
                }
            }
        }
        printf("------------%d------------\n", nDepth);
        nDepth++;
    }
}