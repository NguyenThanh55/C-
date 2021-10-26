#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int a[MAX];

void nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}
int timkiem(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (x == a[i])
			return 1;
	}
	return -1;
}
int themcuoids(int a[], int& n, int x)
{
	if (n >= MAX)
		return 0;
	else
	{
		a[n] = x;
		n++;
	}
	return 1;
}
int xoacuoids(int a[], int& n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
int xoapt(int a[], int& n, int x)
{
	if (x >= 0 && x < n)
	{
		for (int i = x; i < n; i++)
			a[x] = a[x + 1];
		n--;
		return 1;
	}
	return 0;
}
int main()
{
	int n, x, chon;
	bool in = false;
	do {
		system("cls");
		cout << "Menu\n1.Nhap\n2.Xuat\n3.Tim kiem pt\n4.Them pt vao cuoi ds\n5.Xoa cuoi ds\n6.Xoa pt thu x\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Moi ban nhap so pt cua mang:"; cin >> n;
			nhap(a,n);
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Xuat mang: \n";
				xuat(a, n);
			}
			else
				cout << "Ban vui long nhap mang";
			break;
		case 3:
			if (in)
			{
				cout << "Nhap gia tri pt ban muon tim: ";
				cin >> x;
				int b = timkiem(a, n, x);
				if (b == 1)
					cout << "Ban tim thanh cong!";
				else
					cout << "Ban tim khong thanh cong!";
			}
			else
				cout << "Ban vui long nhap mang";
			break;
		case 4:

			if (in)
			{
				cout << "Nhap gtri ban muon them: "; cin >> x;
				int c = themcuoids(a, n, x);
				if (c == 1)
					cout << "Them thanh cong!";
				else
					cout << "K thanh cong";
			}
			else
				cout << "Ban vui long nhap mang";
			break;
		case 5:
			if (in)
			{
				int b = xoacuoids(a, n);
				if (b == 1)
					cout << "Xoa thanh cong";
				else
					cout << "Xoa k thanh cong";
			}
			else
				cout << "Ban vui long nhap mang";
			break;
		case 6:
			if (in)
			{
				cout << "Nhap vi tri ban can xoa: "; cin >> x;
				int b = xoapt(a, n, x);
				if (b == 1)
					cout << "Xoa thanh cong";
				else
					cout << "Xoa k thanh cong";
			}
			else
				cout << "Ban vui long nhap mang";
			break;
		default:
			cout << "Ban chon thoat!\n";
		}
		_getch();
	} while (chon > 0 && chon < 7);
}