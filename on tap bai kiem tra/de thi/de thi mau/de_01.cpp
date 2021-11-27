#include <bits/stdc++.h>
using namespace std;

const int n = 7;
int x[n], check[n] = {};

struct HocSinh {
	string ten;
	float diemTrungBinh;
	float tienHocThem;
	void HienThi() {
		cout << ten << " | " << diemTrungBinh << " | "  << tienHocThem << endl;
	}
};



HocSinh HS[n] = {
	{"Hoang", 5.5, 2500},
	{"Hung", 9, 6000},
	{"Tung", 8.5, 5000},
	{"Hieu", 7.5, 4500},
	{"Manh", 6.5, 8000},
	{"Tien", 7, 3500},
	{"Thang", 8 , 7000}	
};

void HienThiNguoc(HocSinh HS[], int n) {
	if (n == 1) {
		HS[n-1].HienThi();		
	} else {
		HS[n-1].HienThi();
		HienThiNguoc(HS, n-1);
	}
}

void SapXepTangDan(HocSinh HS[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (HS[i].tienHocThem > HS[j].tienHocThem) {
				swap(HS[i], HS[j]);
			}
		}
	}
}

int LayHocSinh (HocSinh HS[], int n, float p) {
	SapXepTangDan(HS, n);
	int i = 0;
	int dem = 0;
	while(p > 0 && i < n) {
		if(p >= HS[i].tienHocThem) {
			p = p - HS[i].tienHocThem;
			dem++;
			i++;
		} else{
			i++;
		}
	}
	return dem;
}

void HienThiTen() {
	for (int i = 1; i <= n; i++) {
		cout << HS[x[i]-1].ten << " ";
	}
	cout << endl;
}

void Try(int i)
{
    for(int j = 1;j<=n; j++)
        if(check[j] == 0)
        {
            check[j] = 1;
            x[i] = j;
            if(i == n)
                HienThiTen();
            else Try(i+1);
            check[j] = 0;
        }
}
int main() {
	for (int i = 0; i < n; i++) {
		HS[i].HienThi();
	}
	cout << "\nHIEN THI NGUOC:\n";
	HienThiNguoc(HS,n);
	cout << "\nLAY HOC SINH\n";
	
	HocSinh b[n];
    for(int i = 1; i<n; i++)
        b[i] = HS[i];
    float p = 15000;//So tien khong duoc vuot qua
    cout << "Co the lay duoc nhieu nhat " << LayHocSinh(b,n,p) << " de tong so tien hoc them nho hon " << p << endl;
    cout << "\nSEP VAO BAN\n";
    Try(1);
	return 0;
}
