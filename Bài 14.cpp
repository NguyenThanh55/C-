//dung ds lien ket don 
#include <iostream>
#include <conio.h>
using namespace std;

struct Donthuc
{
	int heso;
	int somu;
	Donthuc *link;
};
struct Dathuc
{
	Donthuc* head;
	Donthuc* tail;
};
Donthuc* Node(int h, int s)
{
	Donthuc* p = new Donthuc;
	if (!p) return NULL;
	p->link = NULL;
	p->heso = h;
	p->somu = s;
	return p;
}

void Init(Dathuc &d);
void addTail(Dathuc &d, Donthuc* p);
void addHead(Dathuc &d, Donthuc* p);
void addAt(Dathuc& d, Donthuc* p);
void nhap(Dathuc &d);
void xuat(Dathuc &d);
Donthuc* meger(Donthuc* d, Donthuc* d1);
void cong(Dathuc& d2);
void tru(Dathuc& d2);
int main()
{
	int chon;
	Dathuc d,d1,d2;
	bool in = false;
	Init(d); Init(d1); Init(d2);
	do {
		system("cls");
		cout << "Menu\n1.Nhap da thuc\n2.Xuat da thuc\n3.Cong 2 da thuc\n4.Tru 2 da thuc\n5.Nhan 2 da thuc\n6.Chia 2 da thuc\nBan chon:";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Nhap da thuc A:\n";
			nhap(d);
			cout << "Nhap da thuc B:\n";
			nhap(d1);
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Da thuc A= ";
				xuat(d);
				cout << "Da thuc B= ";
				xuat(d1);
			}
			else
				cout << "Nguoi dung vui long nhap da thuc!\n";
			break;
		case 3:
			if (in)
			{
				
				cout << "  ";
				xuat(d);
				cout << "\n+\n  ";
				xuat(d1);
				cout << "\n=  ";
				d2.head = meger(d.head, d1.head);
				cong(d2);
			}
			else
				cout << "Nguoi dung vui long nhap da thuc!\n";
			break;
		case 4:
			if (in)
			{
					cout << "  ";
					xuat(d);
					cout << "\n-\n  ";
					xuat(d1);
					cout << "\n=  ";
					d2.head = meger(d.head, d1.head);
					tru(d2);
			}
			else
				cout << "Nguoi dung vui long nhap da thuc!\n";
			break;
		case 5:
			if (in)
			{

			}
			else
				cout << "Nguoi dung vui long nhap da thuc!\n";
			break;
		case 6:
			if (in)
			{

			}
			else
				cout << "Nguoi dung vui long nhap da thuc!\n";
			break;
		default :
			cout << "Ban chon thoat!\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 6);

	return 0;
}
void Init(Dathuc &d)
{
	 d.head = NULL;
	 d.tail = NULL;
}
void addTail(Dathuc& d, Donthuc* p)
{
	if (d.head == NULL)
		d.head = d.tail = p;
	else
	{
		d.tail->link = p;
		d.tail = p;
	}
}
void addHead(Dathuc& d, Donthuc* p)
{
	if (!d.head)
		d.head = d.tail = p;
	else
	{
		d.tail->link = p;
		d.tail = p;
	}
}
void addAt(Dathuc& d, Donthuc* p)
{
	if (!d.head || d.head->somu < p->somu)
		addHead(d, p);
	else 
	{
		Donthuc* q = d.head;
		while (q->link)
		{
			if (q->link->somu < p->somu)
				break;
			q = q->link;
		}
		if (!q->link)
			addTail(d, p);
		else
		{
			p->link = q->link;
			q->link = p;
		}
	}
}
void nhap(Dathuc d)
{
	while (1)
	{
		int h, s, lc;
		cout << "Nhap he so, so mu: ";
		cin >> h >> s;
		Donthuc* p = Node(h, s);
		addAt(d, p);
		cout << "\nNhap #0 de tiep tuc, nhap 0 de ket thuc: ";
		cin >> lc;
		if (lc == 0)
			break;
	}

}
void xuat(Dathuc d)
{
	Donthuc* p = d.head;
	while (p!=NULL)
	{
		cout << p->heso << "x^" << p->somu;
		if (p->link) cout << " + ";
		p = p->link;
	}
	cout << endl;
}
/*Donthuc* meger(Donthuc* d, Donthuc* d1)
{
	if (!d && !d1) return NULL;
	else
		if (!d && d1) return d1;
		else 
			if(d && !d1) return d;
	Donthuc* d2 = NULL;
	if (d->somu > d1->somu)
	{
		d2 = d;
		d2->link = meger(d->link, d1);
	}
	else
	{
		d2 = d1;
		d2->link = meger(d, d1->link);
	}
	return d2;
}*/
void cong(Dathuc d, Dathuc d1, Dathuc d2)
{
	Donthuc* p = new Donthuc, * q = new Donthuc;
	if (d.head->somu >= d1.head->somu) {
		d = d1;
		p = l2.head;
	}
	else {
		l = l2;
		p = l1.head;
	}

	q = l.head;
	while (q->sm > p->sm) q = q->next; // tim dc q sao cho q->sm == p->sm
	while (q != NULL) {
		q->hs = q->hs + p->hs;
		p = p->next;
		q = q->next;
	}
}
void tru(Dathuc& d2)
{
	Donthuc* p = d2.head;
	while (p!=NULL)
	{
		if (p->somu == p->link->somu)
		{
			p->heso -= p->link->heso;
			p->link = p->link->link;
		}
		p = p->link;
	}
	xuat(d2);
}