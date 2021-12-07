#include <bits/stdc++.h>
using namespace std;

struct GoiHang {
	string maGoi;
	int khoiLuong;
	float giaTien;
};

const int n = 5;
GoiHang d[n] = {
	{"GH001", 30, 9000},
	{"GH002", 50, 250000},
	{"GH003", 43, 30000},
	{"GH004", 25, 15000},
	{"GH005", 76, 20000}
};

int TimViTri(GoiHang d[], int l, int r, string maGoiCanTim) {
	if(l > r) return -1;
	int mid = (l+r) /2;
	
	if(maGoiCanTim == d[mid].maGoi)
		return mid;
		
	if (maGoiCanTim < d[mid].maGoi)
		return TimViTri(d,l, mid-1, maGoiCanTim);
	else
		return TimViTri(d,mid+1, r, maGoiCanTim);
}


int m = 100;
int i, j, temp, F[6][101] = {0};
algorithm() {
	for(int i = 0; i <= m; i++) F[0][j] = 0;
	cout << "a";
	for(i = 1; i <= n; i++) {
		for(j = 0; j <= m; j++) {
			F[i][j] = F[i-1][j];
			temp = F[i-1][j-d[i].khoiLuong] + d[i].giaTien;
			if(d[i].khoiLuong <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
}
void TruyVet() {
	cout << "Gia tri lon nhat la: " << F[n][m] << endl;
	i = n;
	j = m;
	while(i != 0) {
		if(F[i][j] != F[i-1][j]) {
			cout << i << " ";
			j = j - d[i].khoiLuong;
		}
		i--;
	}
}

int main() {
	string maGoiCanTim = "GH005";
	int result = TimViTri(d, 0, n-1, maGoiCanTim);
	cout << "ma: " << maGoiCanTim << " o vi tri: " << result + 1 << endl;
	cout << "danh sach tui co khoi luong < " << m << " co gia tri lon nhat la: " << endl;
	algorithm();
	TruyVet();
}
