#include <bits/stdc++.h>
using namespace std;

// sinh cau hinh tu mot cau hinh da cho
void next_config(int x[], int n, int i) {
	x[i] += 1;
	i++;
	while(i <= n) {
		x[i] = 0;
		i++;
	}
}

// hien thi mot cau hinh
void view_config(int x[], int n) {
	for (int i = 1; i <= n; i++) {
		cout << char(x[i] + 97);
	}
	cout << endl;
}

void listing_configs(int n) {
	int i;
	int x[n+1] = {0};
	do {
		view_config(x, n);
		i = n;
		while(i > 0 && x[i] == 1) {
			i--;
		}
		if (i > 0) {
			next_config(x, n, i);
		}
	} while(i > 0);
}


int main() {
	int n = 4;
	cout << "chuoi ki tu do dai " << n << " chi chua 'a', 'b' la: " << endl;
	listing_configs(n);
	return 0;
}
