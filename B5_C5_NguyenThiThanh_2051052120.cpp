#include<iostream>
#include<conio.h>
#define MAX 20
using namespace std;

struct Node
{
	int info;
	Node* link;
} *first[MAX], * sp, * front, * rear;

int n;
int C[MAX];

int bfs[MAX];	
int nbfs = 0;	
int dfs[MAX];	
int ndfs = 0;	

void init();
void insert_Last(Node*& f, int x);
void input();
void output_1_List(Node* f);
void output();

void initQueue_BFS();	
void push_BFS(int x);	
void pop_BFS(int& x);	
void init_C();			
void output_BFS();		
void BFS(int v);
void delete_Queue();
void initStack_DFS();	
void output_DFS();		
void push_DFS(int x);	
void pop_DFS(int& x);	
void DFS(int s);
void delete_Stack();
int findVertex(int x);

int main()
{
	char choose;
	bool in = false;

	do {
		system("cls");
		cout << "Menu:\n"
			<< "1. Nhap do thi\n"
			<< "2. Xuat do thi\n"
			<< "3. Duyet BFS\n"
			<< "4. Duyet DFS\n"
			<< "5. Tim dinh X\n"
			<< "6. Thoat\n"
			<< "Ban chon : ";
		cin >> choose;

		switch (choose)
		{
		case '1':
			init();
			input();
			in = true;
			break;
		case '2':
			if (in)
			{
				output();
			}
			else
				cout << "Vui long nhap do thi\n";
			break;
		case '3':
			if (in)
			{
				initQueue_BFS();
				init_C();

				BFS(0);

				output_BFS();

				nbfs = 0;
				delete_Queue();
			}
			else
				cout << "Vui long nhap do thi\n";
			break;
		case '4':
			if (in)
			{
				initStack_DFS();
				init_C();

				DFS(0);

				output_DFS();

				ndfs = 0;
				delete_Stack();
			}
			else
				cout << "Vui long nhap do thi\n";
			break;
		case '5':
			if (in)
			{
				int x;

				cout << "Nhap dinh muon tim: ";
				cin >> x;

				initQueue_BFS();
				init_C();

				BFS(0);

				if (findVertex(x))
					cout << "Dinh " << x << " co ton tai trong do thi\n";
				else
					cout << "Dinh " << x << " khong ton tai trong do thi\n";

				nbfs = 0;
				delete_Queue();
			}
			else
				cout << "Vui long nhap do thi\n";
			break;
		default:
			cout << "---Ket thuc chuong trinh---\n";
		}
		_getch();
	} while (choose >= '1' && choose <= '5');

	return 0;
}

// Dinh nghia ham
void init()
{
	for (int i = 0; i < n; i++)
		first[i] = NULL;

	cout << "*Khoi tao thanh cong\n";
	_getch();
}
void insert_Last(Node*& f, int x)
{
	if (f != NULL)
	{
		Node* q = f;
		while (q->link != NULL)
		{
			q = q->link;
		}

		Node* p = new Node;
		p->info = x;
		p->link = NULL;
		q->link = p;
	}
	else
	{
		Node* p = new Node;
		p->info = x;
		p->link = NULL;
		f = p;
	}
}
void input()
{
	int d, x, m;

	do {
		system("cls");
		cout << "Nhap so dinh cua do thi: ";
		cin >> n;
		if (n < 1 || n > MAX)
		{
			cout << "Du lieu nhap sai. Vui long nhap lai\n";
			_getch();
		}
	} while (n < 1 || n > MAX);

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dinh thu " << i + 1 << ": ";
		cin >> d;
		insert_Last(first[i], d);

		cout << "Nhap so dinh ke cua dinh " << d << ": ";
		do {
			cin >> m;
			if (m < 0 || m > n - 1)
				cout << "Nhap sai. Nhap lai: ";
		} while (m < 0 || m > n - 1);

		if (m != 0)
		{
			cout << "Nhap lan luot " << m << " dinh ke: ";
			for (int j = 0; j < m; j++)
			{
				cin >> x;
				insert_Last(first[i], x);
			}
		}
		else
			cout << "Khong co dinh ke\n";
	}

	cout << "*Luu du lieu thanh cong!\n";
}
void output_1_List(Node* f)
{
	Node* p = f;

	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
}
void output()
{
	cout << "*Danh sach dang luu tru...\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Danh sach dinh ke cua dinh thu " << i + 1 << ":\n";
		if (first[i] != NULL)
		{
			output_1_List(first[i]);
			cout << endl;
		}
		else
			cout << "- Khong co dinh ke\n";
	}
}
void initQueue_BFS()
{
	front = NULL;
	rear = NULL;
}
void push_BFS(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;

	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
void pop_BFS(int& x)
{
	Node* p = front;
	x = p->info;
	front = front->link;

	if (front == NULL)
		rear = NULL;
	delete p;
}
void init_C()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void output_BFS()
{
	cout << "Duyet BFS:\n";
	for (int i = 0; i < nbfs; i++)
		cout << bfs[i] << "\t";
}
void BFS(int v)
{
	int p;
	Node* temp = NULL;

	push_BFS(v);
	C[v] = 0;

	while (front != NULL)
	{
		pop_BFS(p);
		bfs[nbfs] = p;
		nbfs++;

		temp = first[p];
		while (temp != NULL)
		{
			if (C[temp->info] == 1)
			{
				push_BFS(temp->info);
				C[temp->info] = 0;
			}
			temp = temp->link;
		}
	}
}
void initStack_DFS()
{
	sp = NULL;
}
void push_DFS(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
void pop_DFS(int& x)
{
	Node* p = sp;
	x = p->info;
	sp = p->link;
	delete p;
}
void output_DFS()
{
	cout << "Duyet DFS:\n";
	for (int i = 0; i < ndfs; i++)
		cout << dfs[i] << "\t";
}
void DFS(int s)
{
	bool flag = false;
	push_DFS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;

	int u = s;
	Node* temp = NULL;

	while (sp != NULL)
	{
		if (temp == NULL)
			pop_DFS(u);
		temp = first[u];
		while (temp != NULL && !flag)
		{
			if (C[temp->info] == 1)
			{
				push_DFS(u);
				push_DFS(temp->info);

				dfs[ndfs] = temp->info;
				ndfs++;

				C[temp->info] = 0;
				u = temp->info;
				flag = true;
			}
			temp = temp->link;
		}
		flag = false;
	}
}
int findVertex(int x)
{
	int i = 0;

	while (i < n && bfs[i] != x)
	{
		i++;
	}

	if (i == n)
		return 0;
	else
		return 1;
}
void delete_Stack()
{
	while (sp != NULL)
	{
		Node* p = sp;
		sp = sp->link;
		delete p;
	}

	cout << "*Stack rong!\n";
}
void delete_Queue()
{
	while (front != NULL)
	{
		Node* p = front;
		front = front->link;

		if (front == NULL)
			rear = NULL;
		delete p;
	}

	cout << "*Queue rong!\n";
}