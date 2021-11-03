#include <bits/stdc++.h>
using namespace std;

string names[6] = {"Tam", "Toan", "Trang", "Cong", "Trung", "Tu"};

// sinh mot cau hinh tu mot cau hinh dang co
void next_config(int x[], int k, int i) {
	x[i] += 1;
	i++;
	while(i <= k) {
		x[i] = x[i-1] + 1;
		i++;
	}
}

// hien thi mot cau hinh
void view_config(int x[], int k) {
	for (int i = 1; i <= k; i++) {
		cout << names[x[i] - 1] << " ";
	}
	cout << endl;
}

// liet kie cac cau hinh
void listing_config(int k, int n) {
	int i;
	int x[k+1] = {0};
	// cau hinh dau tien {1, 2, ..., k}
	for (int i = 1; i <= k; i++) {
		x[i] = i;
	}
	do {
		view_config(x, k);
		// tim phan tu dau tien chua dat gioi han
		i = k;
		while(i > 0 && x[i] == n - k + i) {
			i--;
		}
		if (i > 0) {
			next_config(x, k, i);
		}
	} while(i > 0);
}
int main() {
	listing_config(4, 6);
	return 0;
	
}
