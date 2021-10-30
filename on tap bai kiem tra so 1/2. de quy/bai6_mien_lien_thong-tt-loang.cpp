// Bài 6: Cài đặt bài toán tìm miền liên thông – Thuật toán loang

#include <bits/stdc++.h>
using namespace std;

int so_mien = 0;

int O[5][6] = {
    {1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 1, 1}
};

bool flag[5][6];
void loang(int i, int j) {
    flag[i][j] = true;
    if ((O[i-1][j] == O[i][j]) && (!flag[i-1][j]) && i > 0) {
        loang(i-1, j);
    }
    if ((O[i+1][j] == O[i][j]) && (!flag[i+1][j]) && i < 4) {
        loang(i+1, j);
    }
    if ((O[i][j-1] == O[i][j]) && (!flag[i][j-1]) && j > 0) {
        loang(i, j-1);
    }
    if ((O[i][j+1] == O[i][j]) && (!flag[i][j+1]) && j < 5) {
        loang(i, j+1);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            flag[i][j] = false;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (!flag[i][j]) {
                so_mien++;
                loang(i, j);
            }
        }
    }
    cout << "So mien lien thong: " << so_mien << endl;
    return 0;
}