#include <iostream>
#include "dfs.h"

int main()
{
	C_GRAPH cGraph{};

	cGraph.init(10);

	cGraph.addNode(0, 1);
	cGraph.addNode(0, 2);
	cGraph.addNode(1, 2);
	cGraph.addNode(1, 3);
	cGraph.addNode(2, 4);
	cGraph.addNode(3, 6);
	cGraph.addNode(4, 5);
	cGraph.addNode(4, 6);
	cGraph.addNode(4, 7);
	cGraph.addNode(6, 8);

	cGraph.print();

	cGraph.dfs(3);

	cGraph.release();
}
