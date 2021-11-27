#include <bits/stdc++.h>
using namespace std;

const int n = 7;
struct MayTinh {
	string nhanHieu;
	float giaNhap;
	float giaBan;
	void HienThi() {
		cout << nhanHieu << " | " << giaNhap << " | " << giaBan << endl;
	}
};

MayTinh m[n] = {
	{"dell xps", 1000, 2000},
	{"asus rog", 1500, 2900},
	{"acer nitro 5", 900, 1800},
	{"hp gaming", 1100, 2600},
	{"dell latitue", 1400, 1900},
	{"levolo", 800, 2800},
	{"msi", 1600, 3000}
};

void HienThiDanhSach(MayTinh m[], int n) {
	if(n == 1) {
		m[n-1].HienThi();
	} else {
		HienThiDanhSach(m,n-1);
		m[n-1].HienThi();
	}	
}

void SapXepGiaTangDan(MayTinh m[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if(m[i].giaBan < m[j].giaBan) {
				swap(m[i], m[j]);
			}
		}
	}
}

int SoMayTinhBan(MayTinh m[], int n, float q) {
	SapXepGiaTangDan(m, n);
	int i = 0, count = 0;
	while(q > 0 && i < n) {
		if(q >= m[i].giaBan) {
			q = q - m[i].giaBan;
			count++;
			i++;
		} else {
			i++;
		}
	}
	if (q == 0) {
		return count;
	} else {
		return -1;
	}
}

int main() {
	HienThiDanhSach(m, n);
	int q = 5000;
	int soMayTinh = SoMayTinhBan(m, n, q);
	soMayTinh == -1 ? 
	cout << "KHONG CHON DUOC MAY NAO BAN BAN  GIA: " << q :
	cout << "SO MAY TINH BAN DUNG BANG: " << q << " la: " << soMayTinh << endl;
		
	
}
