#include <bits/stdc++.h>
using namespace std;

char *A = "aybq04";
char *B = "sagbcxdt";

int lenA = strlen(A);
int lenB = strlen(B);
int **L;
char *xc;

int max(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int algorithm() {
	for (int i = 0; i <= lenA; i++) {
		L[i][0] = 0;
	}
	for (int j = 0; j <= lenB; j++) {
		L[0][j] = 0;
	}
	for (int i = 0; i < lenA; i++) {
		for (int j = 0; j < lenB; j++) {
			if(A[i-1] == B[i-1])
				L[i][j] = L[i-1][j-1] + 1;
			else {
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	return L[lenA][lenB];
}


void xau_con() {
	int i = lenA, j = lenB, k = 0;
	while(L[i][j] != 0) {
		if(A[i-1] == B[j-1]) {
			xc[k] = A[i-1];
			k++;i--;j--;
		} else {
			if(L[i-1][j] > L[i][j-1]) {
				i--;
			} else {
				j--;
			}
		}
	}
	xc[k] = '\0';
	strrev(xc);
}



int main() {
	xc = new char[lenA];
	L = new int *[lenA + 1];
	for (int i = 0; i < lenA+1; i++) {
		L[i] = new int[lenB +1];
	}
	cout << "chieu dai cua xau con: " << algorithm() << endl;
	xau_con();	
			
	cout << "xau  con chung dai nhat: " << xc;
}
