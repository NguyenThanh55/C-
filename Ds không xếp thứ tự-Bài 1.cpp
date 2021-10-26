#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int a[MAX];
int n;

void Input(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "a[" << i << "]=" << a[i] << endl;
}
int Search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}
int InsertLast(int a[], int &n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
}
int DeleteLast(int a[], int &n)
{
	int i = n;
	if (i == n)
	{
		a[n] = NULL;
		n--;
		return 1;
	}
	return 0;
}
int Delete(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
		if (i == x)
		{
			a[i] = a[i + 1];
			n--;
			return 1;
		}
}
int main()
{
	int choose;
	bool in = false;
	do {
		system("cls");
		cout << "Menu\n1.Input\n2.Output\n3.Search X\n4.Insert X at last\n5.Delete X at last\n6.Delete X at i\n7.Exit\nYou choose ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Input a mount of list: ";
			cin >> n;
			Input(a, n);
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "List: ";
					Output(a, n);
			}
			else
				cout << "Please input list!";
			break;
		case 3:
			if (in)
			{
				int x;
				cout << "Input element which you search: ";
				cin >> x;
				
				if (Search(a, n, x) != -1)
				{
					cout << "Element which you search at: ";
					cout << Search(a, n, x);
				}
				else
					cout << x << "does not exists!\n";
			}
			else
				cout << "Please input list!";
			break;
		case 4:
			if (in)
			{
				int x;
				cout << "Input element which you want to insert: ";
				cin >> x;
				if (InsertLast(a, n, x) == 1)
					cout << "Success!\n";
				else
					cout << "Failed!\n";
			}
			else
				cout << "Please input list!";
			break;
		case 5:
			if (in)
			{
				if (DeleteLast(a, n) == 1)
					cout << "Success!\n";
				else
					cout << "Failed!\n";
			}
			else
				cout << "Please input list!";
			break;
		case 6:
			if (in)
			{
				int x;
				cout << "Input location which you want to delete: ";
				cin >> x;
				if (Delete(a, n, x) == 1)
					cout << "Success!\n";
				else
					cout << "Failed!\n";
			}
			else
				cout << "Please input list!";
			break;
		default:
			cout << "Please exit!";
			
		}
		_getch();
	} while (choose > 0 && choose <= 6);
	return 0;
}