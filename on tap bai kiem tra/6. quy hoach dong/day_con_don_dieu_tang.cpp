#include <bits/stdc++.h>
using namespace std;

const int n = 10;
int a[n] = {5, 2, 3, 4, 9, 10, 5, 6, 7, 8};
int L[n+2] = {};
int T[n+1] = {};
int jmax = 0;

void algorithm() {
	a[0] = -2147483648;
	a[n+1] = 2147483648;
	L[n+1] = 1;
	for (int i = n; i >= 0; i--) {
		jmax = n + 1;
		for (int j = i + 1; j <= n + 1; j++) {
			if (a[j] > a[i] && L[j] > L[jmax])
				jmax = j;
			L[i] = L[jmax] + 1;
			T[i] = jmax;
		}
	}
}

void result() {
	int k = T[0];
	cout << "Day con: ";
	while(k != n+1) {
		cout << "a[" << k << "]: " << a[k] << " ";
		k = T[k];
	}
}

int main() {
	algorithm();
	result();
}
