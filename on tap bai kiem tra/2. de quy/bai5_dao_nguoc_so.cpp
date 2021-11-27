// Bài 5: Cài đặt chương trình tìm số m là số đảo ngược của số nguyên dương n theo
// phương pháp đệ quy.

#include<bits/stdc++.h>
using namespace std;

int DaoNguoc(int n, int sdn)
{
	if (n == 0)
		return sdn;
	else {
		sdn = sdn*10 + n%10;
		return DaoNguoc(n/10, sdn);
	}
}
int main()
{
    int n;
    cout << "Nhap so muon dao nguoc: "; cin >> n;
    cout << DaoNguoc(n,0);
    return 0;
}