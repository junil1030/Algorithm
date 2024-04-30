#pragma once

class C_GRAPH
{
	struct S_NODE
	{
		bool bNode;
		bool bVisit;
	};
private:
	S_NODE** m_ppBuffer;
	int			m_nBufferSize;

	void searchNode(int nNode);

public:
	C_GRAPH() = default;
	void init(int nBufferSize);
	void release();
	bool addNode(int nDst, int nSrc);
	void print();
	void dfs(int nNode);
};