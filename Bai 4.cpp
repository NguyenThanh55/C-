//chuong trinh tính S va P hinh tron
#include <iostream> 
using namespace std;

int main()
{
	double PI = 3.14, r, s, p;
	cout << "Nhap ban kinh hinh tron ";
	cin >> r;
	s = PI * r * r;
	p = s * PI * r;
	cout << "Dien tich hinh tron " << s << endl;
	cout << "Chu vi hinh tron " << p << endl;
	return 0;
}