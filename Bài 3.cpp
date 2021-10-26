#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	fstream file;
	const int max = 100;
	int i = 1;
	double a, b, c, d, e, f,kq;
	file.open("C:\\Users\\Thanh\\OneDrive\\Documents\\Visual Studio 2019\\BT3.txt", ios::app);
	//cout << "Ghi file thanh cong" << endl;
	if (file.is_open())
	{
		do {
			cin >> a >> b >> c;
			file << a << "#" << b << "#" << c << endl;
			if (a == 0 && b == 0 && c == 0)
				break;
			cout << "GTTB cua 3 so nguyen thu " << i << ": " << (a+b+c) / 3 << endl; 
		} while (true);
	}

	file.close();
}