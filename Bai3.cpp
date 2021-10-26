//Chuong trinh xuat ra tien luong
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ten;  
	int soNLV, tienC, tienL;
	cout << "Nhap ten ";
	cin >> ten;
	cout << "Nhap so ngay lam viec ";
	cin >> soNLV;
	cout << "Nhap tien cong 1 ngay ";
	cin >> tienC;
	tienL = soNLV * tienC;
	cout << "Ten: " << ten << endl;
	cout << "Tien luong nhan duoc: " << tienL << endl;
	return 0;

	
	
}