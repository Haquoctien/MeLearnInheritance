#include "SLL.h"

int main(int argc, char const *argv[])
{
	intNodeList list;
	listInput(list);
	listOutput(list);
	intNode *head = popHead(list);
	cout << head->integer << " popped" << endl;
	intNode *tail = popTail(list);
	cout << tail->integer << " popped" << endl;
	listOutput(list);
	cout << (nodeWithVal(list, 7)->integer) << endl;
	cout << "list co do dai la: " << numberOfNodes(list) << endl;
	sortList(list);
	listOutput(list);
	cout << "them node '5' vao sorted list" << endl;
	addNodeSorted(list, 5);
	listOutput(list);
	deleteNodeWithVal(list, 5);
	listOutput(list);
	system("pause");
	return 0;
}
