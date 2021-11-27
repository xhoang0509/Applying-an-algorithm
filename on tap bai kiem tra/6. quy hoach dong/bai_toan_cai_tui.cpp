#include <bits/stdc++.h>
using namespace std;

const int n = 7;
const int m = 14;
int v[n] = {3, 1, 9, 4, 2, 5, 6};
int w[n] = {6, 2, 7, 5, 3, 4, 8};
int F[n+1][m+1] = {0};

int i, j, temp;

// thuat toan
void algorithm(){
	for (i = 0; i <= m; i++) { 
		F[0][j] = 0; 
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			F[i][j] = F[i - 1][j]; //Khong lay goi thu i
			temp = F[i - 1][j - w[i]] + v[i];
			if (w[i] <= j && F[i][j] < temp) //Lay goi thu i
				F[i][j] = temp;
		}
	}
}

void result(){
	cout << "Max value: " << F[n][m] << endl;
	i = n;
	j = m;
	
	while (i != 0) {
		if (F[i][j] != F[i - 1][j]) {
			cout << i + 1 << " ";
			j = j - w[i]; //Lay goi thu i
		}
		i--;
	}
}

int main() {
	algorithm();
	result();
}
