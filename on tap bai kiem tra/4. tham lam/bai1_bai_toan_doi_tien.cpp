// Bài 1: Cài đặt chương trình cho bài toán đổi tiền

#include <bits/stdc++.h>
using namespace std;

void Xuat(int *c, int m) {
	for (int i = 0; i < m; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
}

bool cashiers_alg(int *c, int m, long n, int *&s) {
	// khoi tao s
	s = new int[m];
	for (int i = 0; i< m; i++) {
		s[i] = 0;
	}
	
	// tim nghiem
	int i = 0;
	while (n > 0 && i < m) {
		s[i] = n / c[i];
		n %= c[i];
		i++;
	}
	if (n > 0) {
		return false;
	}
	return true;
}

int main() {
	int *c;
	int *s;
	int m = 5;
	int n = 34;	
	c = new int[m]{100, 25, 10, 5, 1};
	
	if (cashiers_alg(c, m, n, s)) {
		int tong = 0;
		cout << "s[]: ";
		Xuat(s,m);
		cout << "Can so: " << endl;
		for (int i = 0; i < m; i++) {
			if (s[i] > 0) {
				cout << s[i] << " to | dong tien menh gia: " << c[i] << endl;
				tong += s[i];
			}
		}
		cout << "Can so to it nhat la: " << tong;
	}else {
		cout << "Khong lay dc so dong nao !";
	}
}











