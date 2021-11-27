// Bài 2: Liệt kê dãy nhị phân độ dài n.

#include<bits/stdc++.h>
using namespace std;

int *x;
int n;
void show(int x[]) {
    for(int i = 1; i<= n; i++)
        cout << x[i] << " " ;
    cout << endl;
}
void Try(int k) {
    for(int i = 0; i<= 1; i++)
    {
        x[k] = i;
        if(k == n){
            show(x);
        }
        else
            Try(k+1);
    }
}
int main()
{
    cout << "Nhap n: ";
    cin >> n;
    x = new int[n+1];
    Try(1);
}