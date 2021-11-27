// Bài 1: Cài đặt bài toán liệt kê hoán vị.

#include <bits/stdc++.h>
using namespace std;

// dao gia tri hai phan tu
void swap(int &a, int &b) {
	int tg = a;
	a = b;
	b = tg;
}

// hien ti mot cau hinh
void view_config(int a[], int n) {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

// sinh cau hinh moi tu cau hinh dang co
void next_config(int a[], int n, int i) {
	// tim a[k] be nhat trong dong cuoi lon hon a[i]
	int k = n;
	while (a[k] < a[i]) {
		k--;
	}
	// dao gia tri a[i] va a[k]
	swap(a[i], a[k]);
	// dao nguoc doan cuoi
	int j = n;
	i++;
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

// liet ket cac cau hinh
void listing_configs(int n) {
	int i, a[n + 1] = {0};
	// cau hinh dau tien {1 2 ... n}
	for (i = 1; i <= n; i++) {
		a[i] = i;
	}
	do {
		view_config(a, n); //In mot cau hinh
		//Tim phan tu lien truoc doan cuoi giam dan
		i = n - 1;
		while (i > 0 && a[i] > a[i+1])
			i --;
		if (i > 0) { //Chua phai cau hinh cuoi
			next_config(a, n, i);
		}
	} while (i > 0);
}

int main() {
	int n;
	cout << "nhap vao do dai phan tu: ";
	cin >> n;	
	listing_configs(n);
	return 0;
}
