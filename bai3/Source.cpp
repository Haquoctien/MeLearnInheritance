#include <iostream>
#include <cmath>
#include "../DSA-TH4-KHTN/SLL.h"
#define itoa _itoa_s
using namespace std;
intNodeList decimalToHexadecimal(int x)
{
	intNodeList list;
	intNodeListInit(list);
	while (x > 0)
	{
		addHead(list, newNode(x % 16));
		x /= 16;
	}
	return list;
}

char getHexadecimalDigit(int n)
{
	char a[2];
	itoa(n, a, 2, 16);
	return a[0];

}

void hexadecimalOuput(intNodeList list)
{
	intNode * p = list.head;
	while (p)
	{
		cout << getHexadecimalDigit(p->integer);
		p = p->next;
	}
	cout << endl;
}
int main(void) {
	cout << "Nhap so thap phan de chuyen sang thap luc phan: ";
	int n;
	cin >> n;
	intNodeList ans = decimalToHexadecimal(n);
	hexadecimalOuput(ans);
	system("pause");
	return 0;
}


