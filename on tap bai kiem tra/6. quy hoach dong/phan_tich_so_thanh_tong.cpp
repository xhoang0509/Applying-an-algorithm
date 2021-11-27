#include <bits/stdc++.h>
using namespace std;

int f[6][6] = {
	{1, 0, 0, 0, 0},
};

int m = 5;
int n = 5;


// dung mang hai chieu
int analya01() {
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n ; j++) {
			if (j < i) {
				f[i][j] = f[i-1][j];
			} else {
				f[i][j] = f[i-1][j] + f[i][j-1];
			}
		}
	}
	return f[n][n];
}
//int next[5] = {0};
//int cur[5] = {0};
//// dung 2 mang mot chieu
//int analys02 {
//	for(int i = 1; i <= m; i++) {
//		for (int j = 0; j <= n; j++) {
//			if (j < i) {
//				next[j] = cur[j];
//			} else {
//				next[j] = cur[j] - next[j-1];
//			}
//		}	
//	}
//	return cur[n];
//	
//}

int f3[6] = {};
//Dùng 1 m?ng m?t chi?u
int analys03() { 
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= n; j++) {
			if (j < i) {
				f3[j] = f3[j] + f3[j-i];
			}
		}
	}
	return f3[n];
}


int f(int m, int n) { //Dùng k? thu?t d? quy (ch?m)
	if (m == 0){
		if (n == 0){
			return 1;
		}
			else return 0;
		}
		}
		else {
			if (m > n) return f(m – 1, n);
		else return f(m – 1, n) + f(m, n – m);
	}
}

int main() {
	
//	cout << "so cac phan tich so: " << n << " thanh so cach: " << analya01() << endl;
//	cout << "so cac phan tich so: " << n << " thanh so cach: " << analys02() << endl;
	cout << "so cac phan tich so: " << n << " thanh so cach: " << analys03() << endl;
	
	
	return 0;
}
