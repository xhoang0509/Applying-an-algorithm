#include<bits/stdc++.h>
using namespace std;

struct mayTinh
{
    int nhanhieu;
    float gianhap;
    float giaban;

    void Show()
    {
        cout << nhanhieu<< " " << gianhap << " " << giaban;
    }
};
const int n = 8;
mayTinh m[n] =
{
    {1, 50, 55},
    {2, 40, 43},
    {3, 50, 52},
    {4, 20, 25},
    {5, 30, 34},
    {6, 15, 17},
    {7, 17, 20},
    {8, 19, 22},
};
int x[n], check[n]={};

void hienthi(int n)
{
    if(n == 1)
    {
        m[n-1].Show();
        cout << endl;
    }
    else
    {
       hienthi(n-1);
       m[n-1].Show();
       cout << endl;
    }
}
void sapxep(mayTinh a[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i].giaban < a[j].giaban)
            {
                mayTinh tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
}
//55 52 43 34 25 20 20 17
int banMT(mayTinh *a, int n, float p)
{
    int i = 0, dem = 0;
    while(p > 0 && i < n)
    {
        if(p>=a[i].giaban)
        {
            p = p - a[i].giaban;
            dem++;
            i++;
        }
        else
            i++;
    }
    if(p == 0)
        return dem;
    else
        return -1;
}
void out()
{
    for(int i= 1; i<=n; i++)
        cout << m[x[i]-1].nhanhieu << " ";
    cout << endl;
}
void Try(int i)
{
    for(int j = 1;j<=n; j++)
        if(check[j] == 0)
        {
            check[j] = 1;
            x[i] = j;
            if(i == n)
                out();
            else Try(i+1);
            check[j] = 0;
        }
}
// Cau 4
void swap(int &a, int &b)
{
    int tg = a;
    a = b;
    b = tg;
}

void view_config(int x[], int n)
{
    for (int i = 1; i <= n; i++)
        cout<<m[x[i]-1].nhanhieu << " ";
    cout<<endl;
}

void next_config(int x[], int n, int i)
{
    int k = n;
    while (x[k] < x[i])
    {
        k--;
    }
    swap(x[i], x[k]);
    int j = n;
    i++;
    while (i < j)
    {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}

void listing_configs(int n)
{
    int dem = 0;
    int i, x[n + 1] = {0};
    for (i = 1; i <= n; i++)
    {
        x[i] = i;
    }
    do
    {
        view_config(x, n);
        i = n - 1;
        while (i > 0 && x[i] > x[i + 1]) i --;
        if (i > 0)
        {
            next_config(x, n, i);
        }
    }
    while (i > 0);
}
int main()
{
    float p = 175;
    hienthi(n);
    mayTinh mt[n];
    for(int i = 0; i< n; i++)
        mt[i] = m[i];
    sapxep(mt,n);
    if(banMT(mt,n,p) == -1)
        cout << "Khong the ban it may tinh nhat de so tien bang" << p << endl;
    else
        cout << "Co the ban duoc it nhat " << banMT(mt, n, p) << " may tinh de tong so tien ban duoc bang " << p << endl;
    cout << endl << "các phuong an sap xep cac may tinh vao mot day ban:" << endl;
    listing_configs(8);
    return 0;
}
