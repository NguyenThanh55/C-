#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node* left;
	Node* right;
};
Node* root;
void tree_empty()
{
	root = NULL;
}
Node* search(Node* p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}
void InsertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return ;
		else if (p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
void searchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(Node*& T, int x)
{
	if (T == NULL) return 0;
	if (T->info == x)
	{
		Node* p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else	
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x) return Delete(T->right, x);
	if (T->info > x) return Delete(T->left, x);
}
void duyetNLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
void duyetLNR(Node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}
void duyetLRN(Node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}
int main()
{
	int x,chon;
	bool in = false;
	do {
		system("cls");
		cout << "Menu\n"
			"1.Tao cay rong\n"
			"2.Them 1 pt\n"
			"3.Tim 1 pt\n"
			"4.Xoa 1 pt\n"
			"5.Duyet thu tu NLR\n"
			"6.Duyet thu tu LNR\n"
			"7.Duyet thu tu LRN\n"
			"Ban chon:";
		cin >> chon;
		switch (chon)
		{
		case 1:
			tree_empty();
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Nhap pt ban muon them:"; cin >> x;
				InsertNode(root, x);
				cout << "Thanh cong!\n";
			}
			else
				cout << "Moi ban tao cay rong!";
			break;
		case 3:
			if (in)
			{
				cout << "Nhap pt ban muon tim: "; cin >> x;
				if (search(root, x))
					cout << "Tim thanh cong!\n";
				else
					cout << "Tim khong thanh cong!\n";
			}
			else
				cout << "Moi ban tao cay rong!";
			break;
		case 4:
			if (in)
			{
				cout << "Nhap pt ban muon xoa: "; cin >> x;
				if (Delete(root, x))
					cout << "Xoa thanh cong\n";
				else 
					cout << "Xoa khong thanh cong\n";
			}
			else
				cout << "Moi ban tao cay rong!";
			break;
		case 5:
			if (in)
			{
				cout << "Sau khi duyet thu tu NLR: \n";
				duyetNLR(root);
			}
			else
				cout << "Moi ban tao cay rong!";
			break;
		case 6:
			if (in)
			{
				cout << "Sau khi duyet thu tu LNR: \n";
				duyetLNR(root);
			}
			else
				cout << "Moi ban tao cay rong!";
			break;
		case 7:
			if (in)
			{
				cout << "Sau khi duyet thu tu LRN: \n";
				duyetLRN(root);
			}
			else
				cout << "Moi ban tao cay rong!";
			break;
		default:
			cout << "Ban chon thoat!\n";
		}
		_getch();
	} while (chon > 0 && chon < 8);
}
