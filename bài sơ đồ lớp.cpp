#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
string tenhs(string sv[6][6], int k)
{
	for (int j = 0; j < 6; j++)
		cout << sv[k][j] << endl;
}

int main()
{
	int chon;
	string sv[6][6];
	string bo1, bo2;
	ifstream sodo("C:\\Users\\Thanh\\OneDrive\\Documents\\Visual Studio 2019\\SoDoLop.txt");
	while (!sodo.eof())
	{
		getline(sodo, bo1);
		getline(sodo, bo2);
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
				getline(sodo, sv[i][j], ',');
			int j = 5;
			getline(sodo, sv[i][j]);
		}
	}
	do {
		system("pause");
		cout << "Menu\n1.In ra ten hs ngoi day k\n.2Co bao nhieu cho trong\n3.In ra ten va vi tri cua cac hs k ngoi canh ai\n4.In ra ten cac hs k cos ai ngoi truoc hoac sau em do\nBan muon chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			int k;
			cout << "Nhap day ban muon in: ";
			cin >> k;
			cout << "Ten cac ban day " << k << " la: " << tenhs(sv[6][6], k);

		}
	} while (chon >= 1 && chon <= 5);
	

		sodo.close();

}