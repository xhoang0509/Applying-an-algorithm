#include <bits/stdc++.h>
using namespace std;

char s[100] = "abccaba";
const int k = 3;
char xc[k];


bool comat(char s, char tam[100] ) {
	for (int i = 0; i< strlen(tam); i++) {
		if(tam[i] == s) {
			return true;
		}
	}
	return false;
}

void them(char *xc, char s) {
	int n = strlen(xc);
	xc[n] = s;
	xc[n+1] = '\0';
//	strcat(xc, s);
}

void xoa(char *xc) {
	int n = strlen(xc);
	xc[n-1] = '\0';
//	xc.length() - 1;
}

int dem = 0;
void ThucHien(int i) {
	char tam[100]; // tui de "soi" cac ky tu o vi tri i
	tam[0] = '\0';
	if(strlen(xc) == k) {
		cout << xc << endl;
		dem++;
	} else {
		for (int j = i; j < k; j++) {
			if(comat(s[i], tam) == false) {
				them(tam, s[j]); // them s[j] vao "tui" tam
				them(xc, s[j]); // them s[j] vao xau con xc
				ThucHien(j+1); // thuc hien tiep |xc| = j+1
				xoa(xc); // xoa ky tu cuoi cung cua xau xc
			}
		}
	}
}

int main() {
	ThucHien(1);
	
}
