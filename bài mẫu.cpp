//danh sách liên kết đơn 
//khai báo dslk đơn
//khoi tạo dslk đơn
//thêm pt vào đầu ds
//thêm pt vào cuối ds
//tìm kiếm
//xuất các pt
//thêm 1 node sau 1 node bất kì: 8 5 7 (thêm 10 sau 5)
// BT phải làm 
//thêm 1 node trước 1 node bất kì
//đếm có bn node
//đếm có bn node chứa giá trị số nghuyên tố
//huy toàn bộ ds khi kết thúc chương trình
#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node *first;
void init();
void insertFirst(int x);
void insertLast(int x);
Node* search(int x);
void processList();
int insert(int y,int x);

int main()
{
	int choose,x,y;
	bool in = false;
	do {
		system("cls");
		cout << "Menu\n1.Khoi tao danh sach\n2.Them vao dau danh sach\n3.Them vao cuoi danh sach\n4.Tim kiem\n5.Xuat cac phan tu\n6.Them pt bat ky\nBan chon:";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init();
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Please input the value = ";
				cin >> x;
				insertFirst(x);
				cout << "Success!\n";
			}
			else
				cout << "Please call the init function\n";
			break;
		case 3:
			if (in)
			{
				cout << "Please input the value = ";
				cin >> x;
				insertLast(x);
				cout << "Success!\n";
			}
			else
				cout << "Please call the init function\n";
			break;
		case 4:
			if (in)
			{
				cout << "Please input the value = ";
				cin >> x;
				if (search(x) != NULL)
					cout << x << " exists in list\n";
				else
					cout << x << " doesn't exists in list\n";
			}
			else
				cout << "Please call the init function\n";
			break;
		case 5:
			if (in)
			{
				cout << "List is : \n";
				processList();
			}
			else
				cout << "Please call the init function\n";
			break;
		case 6:
			if (in)
			{
				int y;
				cout << "Please input the value = ";
				cin >> x;
				cout << "Please input the value which seaches and inserts after: ";
				cin >> y;
				if (insert(y, x))
					cout << "Success!\n";
				else
					cout << "Failed\n";
			}
			break;
		default :
			cout << "Exit\n";
		}
		getch();
	} while (choose >= 1 && choose <= 6);
	return 0;
}
void init()
{
	first = NULL;
}
void insertFirst(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
void insertLast(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL) //ds rong thi p se tro thanh dau va cuoi ds
		first = p; 
	else
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
Node* search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
		p = p->link;
	return p;
}
void processList()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link; 
	}
}
int insert(int y,int x)
{
	//tìm node y trong ds
	Node* p1 = search(y);
	//nếu y có trong ds thi chen p chua info la x vao sau y
	//nếu y k có trong ds thi tra ve khong chen thanh cong
	if (p1 != NULL)
	{
		Node* p = new Node;
		p->info = x;
		p->link = p1->link;
		p1->link = p;
		return 1;
	}
	return 0;
}


int Delete()
{
	Node* q = new Node()
		q->previous = NULL;
		q->info = x;
		q->next = NULL;
		if (q->previous == first)
			DeleteFirst();
		else
			if (q->next == last)
				DeleteLast()
			else
			{
				p->next = q->previous;
			}
		}
}