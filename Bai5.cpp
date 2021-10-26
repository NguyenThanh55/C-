//chuong trinh tinh va in dien tich hinh tam giac
#include <iostream>
using namespace std;

int main()
{
	double a, b, c , p ,s;
	
	cout << "Nhap 3 canh tam giac ";
	cin >> a >> b >> c;
	if (a + b > c || a + c > b || b + c > a)
	{
		p = ((a + b + c) / 2);
		s = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "Chu vi hinh tam giac: " << p << endl;
		cout << "Dien tich hinh tam giac: " << s << endl;
	}
	else
		cout << "Nhap sai. Nhap lai: ";
	return 0;
}