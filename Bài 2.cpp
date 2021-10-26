//Xuat lại gia tri m cua bài 1 và in ra man hinh
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	fstream file;
	const int max = 10;
	string m[max];
	int i = 1;
	file.open("C:\\Users\\Thanh\\OneDrive\\Documents\\Visual Studio 2019\\BT1.txt");
	cout << "Gia tri m:";
	while (!file.eof())
	{
		getline(file, m[i]);
		cout << m[i] << endl;
		i++;
	}
	file.close();
}