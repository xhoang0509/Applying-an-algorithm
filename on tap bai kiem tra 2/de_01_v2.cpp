#include <iostream>

using namespace std;

const int n = 5;
struct goihang
{
    string magoi;
    int kl;
    float giatien;
};

goihang gh[5] = {
    {"A01H00", 30, 300},
    {"B02H00", 25, 250},
    {"C03H00", 50, 400},
    {"D04H00", 10, 350},
    {"E05H00", 20, 420}
};

// Cau 2
int binarySearch(string c, int l, int r) {
    int m;
    if (l <= r) {
        m = (l + r) / 2;
        if (c.compare(gh[m].magoi) > 0) {
            return binarySearch(c, m + 1, r);
        } else if (c.compare(gh[m].magoi) < 0) {
            return binarySearch(c, l, m - 1);
        }
        else {
            return m;
        }
    }
    return -1;
}

// Cau 3
const int m = 100;
int temp = 0;
int F[n+1][m+1] = {0};
int algorithm()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<= m; j++)
        {
            F[i][j] = F[i - 1][j];
            temp = F[i - 1][j - gh[i-1].kl] + gh[i-1].giatien;
            if (gh[i-1].kl <= j && F[i][j] < temp)
                F[i][j] = temp;
        }
    }
    return F[n][m];
}

// Cau 4
int char_in_string(char T,string P)
{
    int n = P.length();
    for(int i = 0; i< n; i++)
        if(P[i] == T)
            return i;
    return -1;
}

string P = "H00";
int Boyer_Moore_Horspool(string T)
{
    int dem = 0; int i = P.length();int v = P.length();
    while (i < T.length()+1)
    {
        int x = v - 1, j = i - 1;
        while (T[j] == P[x] && x > -1)
        {
            j--;
            x--;
        }
        if (x < 0)
        {
            dem++;
            i = i + v;
        }
        else
        {
            x = char_in_string(T[j], P);
            if (x < 0) i = i + v;
            else i = i + v - x - 1;
        }
    }
    return dem;
}
int main()
{
    // Cau 2
    string h = "B02H00";
    cout << binarySearch(h, 0, n - 1);

    // Cau 3
    cout << "\nResult: " << algorithm() << endl;

    // Cau 4
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (Boyer_Moore_Horspool(gh[i].magoi) != 0) {
            dem++;
        }
        else break;
    }
    
    if (dem == n) {
        cout << "\"H00\" CO trong tat ca ca goi hang: ";
    }
    else {
        cout << "\"H00\" KHONG trong tat ca ca goi hang: ";
    }
    return 0;
}

