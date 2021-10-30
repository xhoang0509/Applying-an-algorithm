//Bài 1: Sinh các chuỗi ký tự khác nhau chỉ chứa 2 ký tự 'a', 'b’.
// De bai: sinh cac chuoi ky tu chua 2 ky tu 'a' = 0, 'b' = 1
#include <bits/stdc++.h>
using namespace std;

// sinh cau hinh tu mot cau hinh dang co
void next_config(int x[], int n, int i) {
    x[i] = 1;
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

// lien ke cac cau hinh
void listing_configs(int n) {
    int i;
    int x[n+1] = {0};
    do {
        view_config(x, n);
        i = n;
        while (i > 0 && x[i] == 1) {
            i--;
        }
        if (i > 0) {
            next_config(x, n, i);
        }
    } while(i > 0);

}
int main() {
	int n;
	cout << "nhap do dai chuoi nhi phan: "; cin >> n;
	listing_configs(n);
	return 0;
}
