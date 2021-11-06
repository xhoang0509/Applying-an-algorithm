// de 03
#include <bits/stdc++.h>
using namespace std;


struct MayTinh{
	string nhanHieu;
	float tocDo;
	float dungLuong;
	void HienThi() {
		cout << nhanHieu << " | " << tocDo << " | " << dungLuong << endl;
	}
};

const int n = 7;
int s[n], kiemTra[n]={};
MayTinh m[n] = {
	{"dell", 3.6, 1.2},
	{"acer", 4.2, 1.8},
	{"asus", 1.6, 2.5},
	{"hp", 3, 5},
	{"lenovo", 1.4, 8},
	{"laptop", 2.4, 7},
	{"pc", 1.8, 5.5}
};

void HienThiDaoNguoc(MayTinh m[], int n) {
	if (n == 1) {
		m[n-1].HienThi();
	} else {
		m[n-1].HienThi();
		HienThiDaoNguoc(m, n-1);		
	}
}

void SepXepDungLuongTangDan(MayTinh m[], int n) {
	for (int i = 0; i <= n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if(m[i].dungLuong > m[j].dungLuong) {
				swap(m[i], m[j]);
			}
		}
	}
}

int ChonMayTinh(MayTinh m[], int n, float q) {
	SepXepDungLuongTangDan(m, n);
	int count = 0;
	int i = 0;
	while(i < n && q > 0) {
		if(q >= m[i].dungLuong) {
			q = q - m[i].dungLuong;
			count++;
			i++;
		} else {
			i++;
		}
	}
	return count;
}

void HienThiNhanHieu() {
	for(int i = 1; i <= n; i++) {
		cout << m[s[i]-1].nhanHieu << " ";
	}        
    cout << endl;
}

void Try(int k)
{
    for(int i = 1; i <= n; i++)
        if(kiemTra[i] == 0)
        {
            kiemTra[i] = 1;
            s[k] = i;
            if(k == n) {
            	HienThiNhanHieu();
			}				
            else {
            	Try(k+1);
			}				
            kiemTra[i] = 0;
        }
}

int main() {
	cout << "HIEN THI DANH SACH DAO NGUOC: \n";
	HienThiDaoNguoc(m,n);
	float q = 0.9;
	int soMayTinh = ChonMayTinh(m, n, q);
	cout << "CHON DUOC SO MAY TINH CO TONG DUNG LUONG NHO HON: " << q << " | LA: " << soMayTinh << endl;
	
	cout << "CACH XEP CAC MAY TINH VAO 1 BAN THEO NHAN DAN: \n";
	Try(1);	
}
