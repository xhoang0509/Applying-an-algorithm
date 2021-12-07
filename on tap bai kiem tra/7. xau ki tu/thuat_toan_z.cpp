#include <bits/stdc++.h>
using namespace std;

char T[100] = "Ban Viet o Viet Nam";
char P[100] = "Viet";
char s[100] = "Viet$Ban Viet o Viet Nam";
int z[100];

void z_algo(const char *s, int *z) {
	int n = strlen(s), left = 0, right = 0;
	for (int i = 1; i < n; i++) {
		if (i > right) {
			left = right = i;
			while(right < n && s[right-left] == s[right]) 
				right++;
			z[i] = right - left;
			right --;
		} else if (z[i - left] < right - i + 1) {
			z[i] = z[i-left];
		} else {
			left = i;
			while (right < n && s[right - left] == s[right])
				right ++;
			z[i] = right - left;
			right--;
		}
	}
}

int main () {
	int n = strlen(s);
	z_algo(s, z);
	
	
	for (int i = 0; i < n; i++) {
		cout << z[i] << " ";
//		if (z[i] == strlen(P)) {
//			cout << "chuoi con bat dau tu: " <<  i - strlen(P) -1 << endl;
//		}
	}
}
