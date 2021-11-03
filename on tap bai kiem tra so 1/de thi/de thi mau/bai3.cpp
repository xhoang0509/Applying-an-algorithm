#include <bits/stdc++.h>
using namespace std;

string names[6] =  {"Tam", "Toan", "Trang", "Cong", "Trung", "Tu"};

void next_config(int x[], int n, int i) {
	// tim x[k] be nhat trong doan cuoi lon hon x[i]
	int k = n;
	while(x[k] < x[i]) 
		k--;
	
	// dao gia tri x[i] va x[k]
	swap(x[i], x[k]);
	
	// dao nguoc doan cuoi
	int j = n;
	i++;
	while(i < j) {
		swap(x[i], x[j]);
		i++;
		j--;
	}
}

// hien thi mot cau hinh
void view_config(int x[], int n) {
	for (int i = 1; i <= n; i++) {
		cout << names[x[i] - 1] << " ";
	}
	cout << endl;
}

void listing_configs(int n) {
	int i, x[n+i] = {0};
	
	// cau hinh dau tien {1, 2, ..., n}
	for(int i = 1; i <= n; i++) {
		x[i] = i;
	}
	do {
		// in mot cau hinh
		view_config(x, n);
		
		// tim phan tu lien truoc doan cuoi giam dan
		i = n - 1;
		while(i > 0 && x[i] > x[i+1])
			i--;
		if(i > 0)
			// chua phai cau hinh cuoi
			next_config(x, n , i);
	} while(i > 0);
}

int main() {
	listing_configs(6);
	return 0;
}
