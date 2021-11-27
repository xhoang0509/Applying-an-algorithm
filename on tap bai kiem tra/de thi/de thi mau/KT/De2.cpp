#include<bits/stdc++.h>
using namespace std;

struct CongViec
{
    int MaCV;
    float start;
    float stop;
    float tinhtg(){
        return  stop - start;
    }
};
const int n = 6;
CongViec a[n] =
{
    {1,9, 10},
    {2,5, 8},
    {3,8, 20},
    {4,7, 9},
    {5,10, 17},
    {6,9, 15},
};
int x[n], k = 5;
float tinhtongtg(int n)
{
    if(n == 1)
        return a[n-1].tinhtg();
    else
    {
        return a[n-1].tinhtg() + tinhtongtg(n-1);
    }
}
void sapxep(CongViec a[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i].stop > a[j].stop)
            {
                CongViec tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
}
int nhanviec(CongViec a[], int n){
    int dem = 0;
    float last_finish = 0;
    for(int i = 0; i< n; i++)
        if(a[i].start >= last_finish)
        {
            dem++;
            last_finish = a[i].stop;
        }
    return dem;
}
void out()
{
    for(int i = 1; i<=k; i++)
        cout << a[x[i]-1].MaCV << " ";
    cout << endl;
}
void Try(int i)
{
    for(int j = x[i-1]+1; j<= n-k+i; j++)
    {
        x[i] = j;
        if(i == k)
            out();
        else Try(i+1);
    }
}
int main()
{
    tinhtongtg(n);
    cout << "Tong thoi gian cua tat ca cac cong viec la: " << tinhtongtg(n) << endl;
    CongViec b[n];
    for(int i = 0; i< n; i++)
        b[i] = a[i];
    sapxep(b,n);
    cout << "Nguoi do co the lam nhieu nhat " << nhanviec(b,n) << " cong viec" << endl;
    Try(1);
    return 0;
}
