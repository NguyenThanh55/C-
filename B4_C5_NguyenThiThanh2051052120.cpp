#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;

int a[MAX][MAX];
int n = 0;

// Khoi tao cac gia tri cho ham BFS va DFS
int C[MAX];

int bfs[MAX];	// BFS
int nbfs = 0;	// BFS

int dfs[MAX];	// DFS
int ndfs = 0;	// DFS

struct Queue
{
	int info;
	Queue* link;
} *front, * rear;

struct stack
{
	int info;
	stack* link;
} *sp;

// Danh sach ham
void input();
void output();
void initQueue_BFS();	// Ham khoi tao dslk don cho BFS
void push_BFS(int x);	// Ham them phan tu vao dslk don cho BFS
void pop_BFS(int& x);	// Ham lay phan tu tu dslk don cho BFS
void init_C();			// Ham khoi tao mang 1 chieu C cho BFS va DFS
void output_BFS();		// Ham xuat cho BFS
void BFS(int v);
void initStack_DFS();	
void output_DFS();		
void push_DFS(int x);	
void pop_DFS(int& x);	
void DFS(int s);
int findVertex(int x);
void delete_Stack();
void delete_Queue();
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
			<< "Ban chon: ";
		cin >> choose;

		switch (choose)
		{
		case '1':
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

void input()
{
	cout << "*Lien ket : 1\n*Khong lien ket : 0\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri lien ket dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	cout << "Luu do thi thanh cong. Chon Xuat de kiem tra\n";
}
void output()
{
	cout << "Do thi dang luu tru:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
void initQueue_BFS()
{
	front = NULL;
	rear = NULL;
}
void push_BFS(int x)
{
	Queue* p = new Queue;
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
	Queue* p = front;
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

	push_BFS(v);
	C[v] = 0;

	while (front != NULL)
	{
		pop_BFS(p);
		bfs[nbfs] = p;
		nbfs++;

		for (int i = 0; i < n; i++)
			if (C[i] == 1 && a[p][i] == 1)
			{
				push_BFS(i);
				C[i] = 0;
			}
	}
}
void initStack_DFS()
{
	sp = NULL;
}
void push_DFS(int x)
{
	stack* p = new stack;
	p->info = x;
	p->link = sp;
	sp = p;
}
void pop_DFS(int& x)
{
	stack* p = sp;
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

	int v = -1, u = s;

	while (sp != NULL)
	{
		if (v == n)
			pop_DFS(u);
		v = 0;
		while (v < n && !flag)
		{
			if (a[u][v] != 0 && C[v] == 1)
			{
				push_DFS(u);
				push_DFS(v);

				dfs[ndfs] = v;
				ndfs++;

				C[v] = 0;
				u = v;

				flag = true;
			}
			v++;
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
		stack* p = sp;
		sp = sp->link;
		delete p;
	}

	cout << "*Stack rong!\n";
}
void delete_Queue()
{
	while (front != NULL)
	{
		Queue* p = front;
		front = front->link;

		if (front == NULL)
			rear = NULL;
		delete p;
	}

	cout << "*Queue rong!\n";
}