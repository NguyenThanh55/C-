#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int ds1[MAX], ds2[MAX];
int n1, n2, n;
int Max(int a, int b)
{
	if (a >= b) return a;
	return b;
}
void nhap(int ds[MAX], int n);
void xuat(int ds[MAX], int n);
void tapHop(int ds1[MAX], int n1, int ds2[MAX], int n2);
void tapGiao(int ds1[MAX], int n1, int ds2[MAX], int n2);
void phanBu(int ds1[MAX], int n1, int ds2[MAX], int n2, int c[MAX], int &m);
int main()
{
	int chon;
	bool in = false;
	do {
		system("cls");
		cout << "Menu\n1.Nhap ds\n2.Xuat ds\n3.Tap hop 2 ds\n4.Tap giao 2 ds\n5.Phan bu 2 ds\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Nhap so pt cua ds 1: "; cin >> n1;
			nhap(ds1,n1);
			cout << "Nhap so pt cua ds 2: "; cin >> n2;
			nhap(ds2, n2);
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Ds 1: \n"; xuat(ds1, n1);
				cout << "Ds 2: \n"; xuat(ds2, n2);
			}
			else
				cout << "Ban can phai nhap ds truoc.";
			break;
		case 3:
			if (in)
			{
				cout << "Tap hop cua 2 ds: ";
				tapHop(ds1, n1, ds2, n2);
				cout << endl;
			}
			else
				cout << "Ban can phai nhap ds truoc.";
			break;
		case 4:
			if (in)
			{
				cout << "Tap giao cua 2 mang la: ";
				tapGiao(ds1, n1, ds2, n2);
			}
			else
				cout << "Ban can phai nhap ds truoc.";
			break;
		case 5:
			if (in)
			{
				int m = 1;
				int c[MAX];
				if (phanBu(ds1, n1, ds2, n2, c, m) == 1)
				{
					m--;
					xuat(c, m);
			}
			else
				cout << "Ban can phai nhap ds truoc.";
			break;
		default: 
			cout << "Ban chon thoat!\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 5);
	return 0;
}
void nhap(int ds[MAX], int n)
{
	for (int i = 1; i <= n; i++)
		cin >> ds[i];
}
void xuat(int ds[MAX], int n)
{
	for (int i = 1; i <= n; i++)
		cout << "Phan tu thu "<< i << " la:" << ds[i] << "\n";
}
void tapHop(int ds1[MAX], int n1, int ds2[MAX], int n2)
{
	for (int i = 1; i <= n1; i++)
		cout << ds1[i] << "\t";
	for (int i = 1; i <= n2; i++)
		cout << ds2[i] << "\t";
}
void tapGiao(int ds1[MAX], int n1, int ds2[MAX], int n2)
{
	int c[MAX], n = 0;
	if (Max(n1, n2) == n1)
	{
		for (int i = 1; i <= n1; i++)
		{
			for (int i1 = 1; i1 <= n2; i1++)
			{
				if (ds1[i] == ds2[i1])
				{
					c[n++] = ds1[i];
					break;
				}
			}
		}
	}
	else 
	{
		for (int i = 1; i <= n2; i++)
		{
			for (int i1 = 1; i1 <= n1; i1++)
			{
				if (ds2[i] == ds1[i1])
				{
					c[n++] = ds2[i];
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int i1 = i; i1 < n; i1++)
		{
			if (c[i] != c[i1])
			{
				i = i1 - 1;
				break;
			}
			if (i1 == n - 1)
				i = i1;
		}
		cout << c[i] << ' ';
	}
}
void phanBu(int ds1[MAX], int n1, int ds2[MAX], int n2, int c[MAX], int &m)
{
	int j=1;
	bool flag = false;
	if (n1>=n2)
	{
		for (int i = 1; i <= n1; i++)
		{
			while (j <= n2 && !flag)
			{
				if (ds2[i] == ds1[j])
					flag = true;
				j++;
			}
			if (!flag)
				c[m++] = ds1[i];
			j = 1;
			flag = false;
		}
	}
	if (m > 1)
		return 1;
	else
		return 0;
}

