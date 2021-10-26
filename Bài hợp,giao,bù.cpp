#include<iostream>
#include<iomanip>
using namespace std;


void Input(long a[], long n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Sort(long a[], long n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int i1 = i; i1 < n; i1++)
		{
			if (a[i] > a[i1])
				swap(a[i], a[i1]);
		}
	}
}
void Print(long a[], long b[], long n1, long n2)     // xuat tap hop
{
	for (int i = 0; i < n1; i++)
		cout << a[i] << ' ';
	for (int i = 0; i < n2; i++)
		cout << b[i] << ' ';
}

void Print2(long a[], long b[], long n1, long n2)
{
	long c[100], n = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int i1 = 0; i1 < n2; i1++)
		{
			if (a[i] == b[i1])
			{
				c[n++] = a[i];
				break;
			}
		}
	}
	Sort(c, n);
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

void Print3(long a[], long b[], long n1, long n2)
{
	long c[100], n = 0, d[100], dem = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int i1 = 0; i1 < n2; i1++)
		{
			if (a[i] == b[i1])
			{
				c[n++] = a[i];
				break;
			}
		}
	}


	for (int i = 0; i < n1; i++)
	{
		long flag = 1;
		for (int i1 = 0; i1 < n; i1++)
		{
			if (a[i] == c[i1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			d[dem++] = a[i];
	}
	for (int i = 0; i < n2; i++)
	{
		long flag = 1;
		for (int i1 = 0; i1 < n; i1++)
		{
			if (b[i] == c[i1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			d[dem++] = b[i];
	}
	Sort(d, dem);
	for (int i = 0; i < dem; i++)
	{
		for (int i1 = i; i1 < dem; i1++)
		{
			if (d[i] != d[i1])
			{
				i = i1 - 1;
				break;
			}
			if (i1 == dem - 1)
				i = i1;
		}
		cout << d[i] << ' ';
	}
}
int main()
{
	long a[100], b[100], n1, n2;				// n1 la do lon mang a, n2 mang b
	cin >> n1 >> n2;		// nhap size cho a va b
	cout << "Nhap a: ";
	Input(a, n1);
	cout << "Nhap b: ";
	Input(b, n2);
	Print(a, b, n1, n2);
	cout << "\nGiao cua 2 mang: " << endl;
	Print2(a, b, n1, n2);
	cout << "\nPhan bu cua 2 mang la: " << endl;
	Print3(a, b, n1, n2);
}
