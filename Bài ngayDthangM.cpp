#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct sinhvien
{
	string mssv, ho, ten, nghanh, que;
	int ngay, thang, nam;
};
int main()
{
	ifstream ds;
	ofstream file;
	int i = 1;
	const int max = 4000;
	sinhvien sv[max];
	ds.open("C:\\Users\\Thanh\\OneDrive\\Documents\\Visual Studio 2019\\SinhVien.txt");
	file.open("C:\\Users\\Thanh\\OneDrive\\Documents\\Visual Studio 2019\\ngayDthangM.txt", ios::app);
	if (ds.is_open())
	{
		cout << "Mo file thanh cong!!\n";
		while (!ds.eof())
		{
			getline(ds, sv[i].mssv, ',');
			getline(ds, sv[i].ho, ',');
			getline(ds, sv[i].ten, ',');
			ds >> sv[i].ngay;
			ds.ignore(1);
			ds >> sv[i].thang;
			ds.ignore(1);
			ds >> sv[i].nam;
			ds.ignore(1);
			getline(ds, sv[i].nghanh, ',');
			getline(ds, sv[i].que);
			i++;
		}//while
		int D, M;
		cout << "Nhap ngay va thang: ";
		cin >> D >> M;
		while (D > 31 || D < 1 || M > 12 || M < 1)
		{
			cout << "Nhap sai!! nhap lai: ";
			cin >> D >> M;
		}//while
		for (int j = 1; j <= i; j++)
		{
			if (sv[j].ngay == D && sv[j].thang == M)
				file << sv[j].ho << "," << sv[j].ten << "," << sv[j].que << "," << sv[j].nghanh << "." << endl;
		}//for
		cout << "Da luu thanh cong!!";
		ds.close();
		file.close();
	}//if
	else
		cout << "Khong mo duoc file!!\n";
}