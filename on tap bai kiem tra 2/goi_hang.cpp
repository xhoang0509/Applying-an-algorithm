#include <bits/stdc++.h>
using namespace std;

struct GoiHang {
	string maHang;
	int khoiLuong;
	int giaTien;
};

const int n = 5;
GoiHang d[n] = {
	{"GH001", 10, 10},
	{"GH002", 35, 8},
	{"GH003", 20, 30},
	{"GH004", 17, 25},
	{"GH005", 55, 18}
};

int timHang(GoiHang d[], int left, int right, string maHang) {
	if(left > right) 
		return -1;
		
	int mid = (left + right) / 2;
	
	if(maHang == d[mid].maHang) 
		return mid;
	
	if(maHang < d[mid].maHang)
		return timHang(d, left, right, maHang);
		
	if(maHang > d[mid].maHang) 
		return timHang(d, mid+1, right, maHang);
}

const int m = 100;
float F[n+1][m+1] = {0};
int i, j;
float temp;

void quyHoachDong() {
	for(j = 0; j <= m; j++) {
		F[0][j] = 0;
	}
	for (i = 1; i <= n; i++) {
		for(j = 0; j <= m; j++) {
			F[i][j] = F[i-1][j]; // khong lay goi thi i
			temp = F[i-1][j-d[i].khoiLuong] + d[i].giaTien;
			if(d[i].khoiLuong <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
}

// truy viet ket qua
void chonGoiHang() {
	cout << "max value: " <<  F[n][m] << endl;
	i = n; 
	i = m;
	cout << "lay goi hang: ";
	while(i != 0) {
		if (F[i][j] != F[i-1][j]) {
			cout << i << " ";
			j  = j - d[i].khoiLuong;
		}
		i--;
	}
}

int main() {
	string maHangCanTim = "GH005";
	int result = timHang(d, 0, n-1, maHangCanTim);
	cout << "ma hang: " << maHangCanTim << " o vi tri: " << result + 1;
	
	cout << "\n==============" << endl;
	quyHoachDong();
	chonGoiHang();
}
