// Bài 3: Cài đặt chương trình tính tổng các chữ số của một số nguyên dương theo phương
// pháp đệ quy.

#include <bits/stdc++.h>
using namespace std;

int TinhTong(int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + TinhTong(n / 10);
    }
}

int main() {
    int n;
    cout << "nhap so nguyen duong n: "; cin >> n;
    int result = TinhTong(n);
    cout << "tong: " << result;

    return 0;
}