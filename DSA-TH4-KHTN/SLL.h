#pragma once
#include <iostream>
using namespace std;

struct intNode {
	unsigned integer;
	intNode *next;
};

struct intNodeList {
	intNode *head;
	intNode *tail;
};

void intNodeListInit(intNodeList &);
void listInput(intNodeList &);
void listOutput(intNodeList);
void listDestroy(intNodeList &);
void addHead(intNodeList &, intNode *);
void addTail(intNodeList &, intNode *);
intNode *newNode(int);
intNode *popHead(intNodeList &);
intNode *popTail(intNodeList &);
void deleteHead(intNodeList &);
void deleteTail(intNodeList &);
void deleteNodeWithVal(intNodeList &, unsigned);
int numberOfNodes(intNodeList);
intNode *nodeWithVal(intNodeList, unsigned);
void sortList(intNodeList &);
void swap(intNode*, intNode*);
void addNodeSorted(intNodeList &, unsigned);
intNodeList decimalToBinary(int);
intNodeList decimalToHexadecimal(int);
void hexadecimalOuput(intNodeList);

#include "SLL.h"

void intNodeListInit(intNodeList &list) {
	list.head = list.tail = NULL;
}

void listInput(intNodeList &list) {
	intNodeListInit(list);
	int i;
	do
	{
		cout << "Nhap so nguyen duong: ";
		cin >> i;
		if (i > 0)
			addHead(list, newNode(i));
	} while (i > 0);
}

void listOutput(intNodeList list) {
	for (intNode *node = list.head; node; node = node->next)
	{
		cout << node->integer << " ";
	}
	cout << endl;
}
void listDestroy(intNodeList &list) {
	if (list.head == NULL)
		return;
	intNode *current = list.head, *holder;
	while (current) {
		holder = current;
		current = current->next;
		delete holder;
	}
	list.head = list.tail = NULL;
}

intNode *newNode(int n) {
	intNode * node = new intNode;
	if (node == NULL)
		return NULL;
	node->integer = n;
	node->next = NULL;
	return node;
}

void addHead(intNodeList &list, intNode *node) {
	if (list.head == NULL) {
		list.head = list.tail = node;
	}
	else {
		node->next = list.head;
		list.head = node;
	}
}

void addTail(intNodeList &list, intNode *node) {
	if (list.head == NULL)
		list.head = list.tail = node;
	else {
		list.tail->next = node;
		list.tail = node;
	}
}

intNode *popHead(intNodeList &list) {
	if (list.head == NULL)
		return NULL;
	if (list.head == list.tail) {
		cout << "hi mark" << endl;
		intNode * p = list.head;
		list.head = list.tail = NULL;
		return p;
	}
	intNode *p = list.head;
	list.head = list.head->next;
	p->next = NULL;
	return p;
}
intNode *popTail(intNodeList &list) {
	if (list.head == NULL)
		return NULL;
	if (list.head == list.tail) {
		intNode * p = list.head;
		list.head = list.tail = NULL;
		return p;
	}
	intNode *p = list.tail;
	intNode *nextToTail = list.head;
	while (nextToTail->next != list.tail)
	{
		nextToTail = nextToTail->next;
	}
	list.tail = nextToTail;
	list.tail->next = NULL;
	return p;
}

int numberOfNodes(intNodeList list)
{
	intNode *p = list.head;
	int answer = 0;
	while (p)
	{
		answer++;
		p = p->next;
	}
	return answer;
}

intNode *nodeWithVal(intNodeList list, unsigned x)
{
	intNode *p = list.head;
	while (p)
	{
		if (p->integer == x)
			break;
		p = p->next;
	}
	return p;
}

void deleteHead(intNodeList &list)
{
	delete popHead(list);
}
void deleteTail(intNodeList &list)
{
	delete popTail(list);
}
void deleteNodeWithVal(intNodeList &list, unsigned x)
{
	intNode * p = nodeWithVal(list, x);
	if (p == NULL) {
		cout << "Khong ton tai node voi gia tri x" << endl;
		return;
	}
	if (p == list.head)
	{
		deleteHead(list);
		return;
	}
	else if (p == list.tail)
	{
		deleteTail(list);
		return;
	}
	intNode *beforeP = list.head;
	while (beforeP->next != p)
		beforeP = beforeP->next;
	beforeP->next = p->next;
	delete p;
}


void sortList(intNodeList &list)
{
	for (intNode *p = list.head; p != NULL; p = p->next)
	{
		intNode *minNode = p;
		for (intNode *q = p->next; q != NULL; q = q->next)
		{
			if (q->integer < minNode->integer)
				minNode = q;
		}
		swap(minNode, p);
	}
}

void swap(intNode *a, intNode*b)
{
	if (a == b)
		return;
	int temp = a->integer;
	a->integer = b->integer;
	b->integer = temp;
}

void addNodeSorted(intNodeList &list, unsigned x)
{
	sortList(list);
	if (list.head == NULL) {
		addHead(list, newNode(x));
		return;
	}
	intNode *p = list.head, *beforeP = NULL;
	while (p)
	{
		if (p->integer >= x)
			break;
		beforeP = p;
		p = p->next;
	}
	intNode *node = newNode(x);
	node->next = p;
	beforeP->next = node;
}

intNodeList decimalToBinary(int x)
{
	intNodeList list;
	intNodeListInit(list);
	while (x > 0)
	{
		addHead(list, newNode(x % 2));
		x /= 2;
	}
	return list;
}