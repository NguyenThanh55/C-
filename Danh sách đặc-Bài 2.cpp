//Bai 3
//Them pt cuoi ds co van de
#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node* link;
};
Node* first;
void init()
{
	first = NULL;
}
void process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}
Node* search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}
void insertFirst(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
int deleteFirst()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
void insertLast(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;

	Node* q = first;
	if (q->link != NULL)
		q=q->link;
	q->link = p;
}
void deleteLast()
{
	Node* p, * q = new Node;
	p = first;
	if (p != NULL)
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		q->link = NULL;
		delete p;
}
int Delete(int x)
{
	Node* p = first, *q = new Node;
	q->info = x;
	if (p != NULL)
	{
		while (p->info == q->info)
		{
			//q = p;
			p = p->link;
		}
		p->link = p->link->link;
		delete q;
		return 1;
	}
	return 0;
}

int main()
{
	int chon;
	bool in = false;
	do {
		system("cls");
	cout << "Menu\n1.Khoi tao ds rong\n2.Xuat\n3.Tim pt\n4.Them pt vao dau ds\n5.Xoa pt dau ds\n6.Them pt cuoi ds\n7.Xoa pt cuoi ds\n8.Tim va xoa pt\nBan chon:";
	cin >> chon;
	switch (chon)
	{
	case 1:
		init();
		in = true;
		break;
	case 2:
		if (in)
		{
			process_list();
		}
		else
			cout << "Ban vui long tao ds rong!\n";
		break;
	case 3:
		if (in)
		{
			int x;
			cout << "Gia trị ban muon tim: ";
			cin >> x;
			if (search(x) != NULL)
				cout << "Sucessful!\n";
			else
				cout << "Failed!\n";
		}
		else
			cout << "Ban vui long tao ds rong!\n";
		break;
	case 4:
	{
		if (in)
		{
			int x;
			cout << "Phan tu ban muon them vao dau ds la: ";
			cin >> x;
			insertFirst(x);
			cout << "Sucessful!\n";
		}
		else
			cout << "Ban vui long tao ds rong!\n";
		break;
	}
	case 5:
		if (in)
		{
			if (deleteFirst() == 1)
				cout << "Sucessful!\n";
			else
				cout << "Failed!\n";
		}
		else
			cout << "Ban vui long tao ds rong!\n";
		break;
	case 6:
		if (in)
		{
			int x;
			cout << "Gia tri ban muon them: ";
			cin >> x;
			insertLast(x);
			cout << "Sucessful!\n";
		}
		else
			cout << "Ban vui long tao ds rong!\n";
		break;
	case 7:
		if (in)
		{
			cout << "Sau khi xoa :";
			deleteLast();
			cout << "Secessful!\n";
		}
		else
			cout << "Ban vui long tao ds rong!\n";
		break;
	case 8:
		if (in)
		{
			int x;
			cout << "Gia tri ban muon tim va xoa: ";
			cin >> x;
			if (search(x) != NULL)
			{
				Delete(x);
				cout << "Sucessful!\n";
			}
			else
				cout << "Failed!\n";
		}
		else
			cout << "Ban vui long tao ds rong!\n";
		break;
	default :
		cout << "Ban chon thoat!\n";
	}
	_getch();
	} while (chon > 0 && chon < 9);
}