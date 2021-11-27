#include <bits/stdc++.h>
using namespace std;

char t[100] = "abcdef";
char p[100] = "bc";

int indexOf(const char *p, const char *t) {
	int m = strlen(p);
	int n = strlen(t) -m;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while(j < m && t[i+j] == p[j]) {
			j++;
		}
		if(j == m) {
			return i;
		}
	}
	return -1;
}

int main() {
	int result = indexOf(p, t);
	if (result != -1) {
		cout << p << " co trong " << t << " | bat dau tu vi tri :" << result << endl;
	} else {
		cout << p << " khong co trong " << t;
	}
}
