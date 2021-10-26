#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#define MAX 20
using namespace std;

int a[MAX][MAX];
int n = 0;
int b[MAX][MAX];

int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;

int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

// Danh sach ham
void khoiTaoMaTranRong();
void input();
void inputByFile();
void outputMaTranKe();
void saoChepMangPhu();
void swap(int& a, int& b);
int TonTai(int d, int D[], int nD);
void taoE();
void SapXepE();
void kruskal();
void output();
void resetE();
void resetT();

// Chuong trinh chinh
int main()
{
	char choose;
	bool in = false;

	do {
		system("cls");
		cout << "Menu\n"
			<< "1. Nhap ma tran ke (thu cong)\n"
			<< "2. Nhap ma tran ke (bang file)\n"
			<< "3. Xuat ma tran ke\n"
			<< "4. Tim cay khung toi thieu\n"
			<< "5. Thoat\n"
			<< "-> Ban chon: ";
		cin >> choose;

		switch (choose)
		{
		case '1':
			if (in)
			{
				khoiTaoMaTranRong();
				n = 0;

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
			}
			else
			{
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
			}
			break;
		case '2':
			if (in)
			{
				khoiTaoMaTranRong();
				n = 0;

				inputByFile();
			}
			else
			{
				inputByFile();
				in = true;
			}
			break;
		case '3':
			if (in)
			{
				outputMaTranKe();
			}
			else
				cout << "*Du lieu khong ton tai. Vui long nhap du lieu\n";
			break;
		case '4':
			if (in)
			{
				// Truong hop da goi ham it nhat 1 lan
				resetE();
				resetT();
				nE = 0;
				nT = 0;

				saoChepMangPhu();
				taoE();
				SapXepE();
				kruskal();

				cout << "Ket qua cay khung toi thieu:\n";
				output();
			}
			else
				cout << "*Du lieu khong ton tai. Vui long nhap du lieu\n";
			break;
		default:
			cout << "---Ket thuc chuong trinh---\n";
		}
		_getch();
	} while (choose >= '1' && choose <= '4');

	return 0;
}

// Dinh nghia ham
void khoiTaoMaTranRong()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
}
void input()
{
	cout << "*Lien ket : nhap Trong So w\n*Khong lien ket : 0\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap trong so cho dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	cout << "Luu do thi thanh cong. Chon xuat de kiem tra\n";
}
void inputByFile()
{
	ifstream dataFile;
	string nameFile;

	cin.ignore();
	cout << "\t*Luu y: file.text phai nam cung thu muc voi file.cpp\n";
	cout << "Nhap ten file (bao gom duoi .txt): ";
	getline(cin, nameFile);

	dataFile.open(nameFile, ios::in);

	if (dataFile.is_open())
	{
		dataFile >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dataFile >> a[i][j];

		cout << "*Luu do thi thanh cong. Chon xuat de kiem tra\n";
		dataFile.close();
	}
	else
		cout << "*Khong the mo file. Vui long kiem tra\n";
}
void outputMaTranKe()
{
	cout << "Do thi dang luu tru:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
void saoChepMangPhu()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[i][j] = a[i][j];
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void taoE()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (b[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = b[i][j];
				b[i][j] = 0;
				b[j][i] = 0;
				nE++;
			}
}
void SapXepE()
{
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}
int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void kruskal()
{
	int i = 0;
	bool flag = false;

	while (i < nE && !flag)
	{
		if (TonTai(E1[i], T1, nT) == 0 || TonTai(E2[i], T1, nT) == 0)
		{
			if (TonTai(E2[i], T2, nT) == 0 || TonTai(E1[i], T2, nT) == 0)
			{
				T1[nT] = E1[i];
				T2[nT] = E2[i];
				wT[nT] = wE[i];
				nT++;

				if (nT == n - 1)
					flag = true;
			}
		}
		wE[i] = 0;
		i++;
	}
}
void output()
{
	int tong = 0;

	for (int i = 0; i < nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong = " << tong << endl;
}
void resetE()
{
	for (int i = 0; i < nE; i++)
	{
		E1[i] = 0;
		E2[i] = 0;
		wE[i] = 0;
	}
}
void resetT()
{
	for (int i = 0; i < nT; i++)
	{
		T1[i] = 0;
		T2[i] = 0;
		wT[i] = 0;
	}
}