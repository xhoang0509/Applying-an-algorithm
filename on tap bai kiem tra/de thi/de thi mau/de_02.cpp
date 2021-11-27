#include <bits/stdc++.h>
using namespace std;

const int n = 7;
int x[n] = {}, k = 5;

struct CongViec{
	int maCv;
	float tgBatDau;
	float tgKetThuc;
};

CongViec CV[n] = {
	{1, 1, 2},
	{2, 1.5, 2.5},
	{3, 2.5, 3},
	{4, 3, 3.5},
	{5, 3, 4},
	{6, 4, 7},
	{7, 7, 8.5}
};

float TongThoiGian(CongViec CV[], int n) {
	if (n == 1) {
		return CV[n].tgKetThuc - CV[n].tgBatDau;
	} else {
		return CV[n].tgKetThuc - CV[n].tgBatDau + TongThoiGian(CV, n-1);
	}
}

// cho biet mot nguoi thuc hien duoc nhieu nhat bao nhieu cong viec
// trong danh sach CV (mot nguoi khong the lam 2 viec cung luc)

void SapXepThoiGianKetThuc(CongViec CV[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if(CV[i].tgKetThuc > CV[j].tgKetThuc) {
				swap(CV[i], CV[j]);
			}
		}
	}
}

int ChonViec(CongViec CV[], int n) {
	int count = 0;
	float last_finish = 0;
	for (int i = 0; i < n; i++) {
		if(CV[i].tgBatDau >= last_finish) {
			count ++;
//			cout << "ma cong viec: " << CV[i].maCv << endl;
			last_finish = CV[i].tgKetThuc;
		}
	}
	return count;
}

void HienThiMACV() {
	for (int i = 1; i <= n; i++)
		cout << CV[x[i] - 1].maCv << " ";
	cout << endl;
}

void Try(int i) {
	for (int j = x[i-1]+1; j <= n-k+i; j++) {
		x[i] = j;
		if(i == k)
			HienThiMACV();
		else
			Try(i+1);
	}
}

int main() {
	cout << "TONG THOI GIAN CAC CONG VIEC: " << TongThoiGian(CV,n) << endl;
	
	SapXepThoiGianKetThuc(CV,n);
	cout << "CHON SO VIEC TOI DA LA: " << ChonViec(CV, n) << endl;
	Try(1);
}
