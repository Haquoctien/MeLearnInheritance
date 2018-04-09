#include <iostream>
#include "../DSA-TH4-KHTN/SLL.h"
using namespace std;
int main(void) {
	cout << "Nhap mot so thap phan de chuyen so nay ve nhi phan: ";
	int n;
	cin >> n;
	intNodeList ans = decimalToBinary(n);
	listOutput(ans);
	system("pause");
	return 0;
}


