//Nhap 2 số nguyên và tính tổng in ra file
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	fstream file;
	long a, b;
	string m;
	file.open("C:\\Users\\Thanh\\OneDrive\\Documents\\Visual Studio 2019\\BT1.txt", ios::app);
	cout << "Nhap 2 so nguyen a va b: ";
	cin >> a >> b;
	file << a + b << endl;
	cout << "Ghi file thanh cong" << endl;
	file.close();
}