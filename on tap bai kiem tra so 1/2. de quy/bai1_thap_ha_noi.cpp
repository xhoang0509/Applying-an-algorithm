// Bài 1: Cài đặt bài toán Tháp Hà Nội theo phương pháp đệ quy.

#include <bits/stdc++.h>
using namespace std;

void Chuyen(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "\t" << A << " -----> " << C << endl;
        return;
    }else {
        Chuyen(n-1, A, C, B);
        Chuyen(1, A, B, C);
        Chuyen(n-1, B, A, C);
    }
}

int main() {
    Chuyen(3, 'A', 'B', 'C');
    return 0;
}