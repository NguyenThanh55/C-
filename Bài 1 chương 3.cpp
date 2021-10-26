#include <iostream>
using namespace std;
#define MAX 100
int a[MAX], n;

void nhap(int a[], int n)
{
	for (int i = 0; i <= n; i++)
		cin >> a[i];
}
void xuat(int a[], int n)
{
	for (int i = 0; i <= n; i++)
		cout <<  a[i] << "\t";
}
void InsertionSort(int a[], int n)
{
	int x, i, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];		// biến x lưu giá trị a[i]
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void swap(int& a, int& b)
{
	int  c;
	c = a;
	a = b;
	b = c;
}
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j; //min_pos là vị trí chứa giá trị hiện tại nhỏ nhất
		swap(a[min_pos], a[i]);
	}
}
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j; //min_pos là vị trí chứa giá trị hiện tại nhỏ nhất
		swap(a[min_pos], a[i]);
	}
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) // xét điều kiện phần tử sau nhỏ hơn phần tử trước
				swap(a[j], a[j - 1]); // hoán vị a[j] với a[j-1]
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
				i++; j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j < n)	// nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j + 1 <= n)        // nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình
		if (a[j] < a[j + 1])	// nếu vị trí j không tồn tại phần tử a[j] < a[j+1]
			j++;

	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}

int main()
{
	int n, left = 0, right = n - 1;

}


