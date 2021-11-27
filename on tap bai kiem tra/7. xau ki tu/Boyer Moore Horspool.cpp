#include <bits/stdc++.h>
using namespace std;

char T[100] = "mothaibabonnamsaubay";
char P[100] = "mothai";

int char_in_string(char T, char P[]) {
	for(int i = 0; i < strlen(P); i++) {
		if (T == P[i]) {
			return i;
		}
	}
	return -1;
}

int Boyer_Moore_Horspool() {
	int dem = 0, v = strlen(P), i  = strlen(P);
	while(i < strlen(T)) {
		int x = v - 1;
		int j = i - 1;
		while(T[j] == P[x] && x > -1) {
			j--; x--;
		}
		if(x < 0) {
			dem++;
			i = i + v;
		} else {
			x = char_in_string(T[j], P);
			if(x < 0) {
				i = i + v;
			} else {
				i = i + v - x - 1;
			}
		}		
	}
	return dem;
}

int main() {
	int result = Boyer_Moore_Horspool();
	result ? cout <<  "P la con cua T" : cout << "T khong phai con cua P";
}
