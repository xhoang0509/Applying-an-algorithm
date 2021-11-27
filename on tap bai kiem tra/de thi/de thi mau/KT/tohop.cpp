#include<bits/stdc++.h>

using namespace std;

int a[100]={}, n = 8, k =5;
void out()
{
    for(int i = 1; i<=k; i++)
        cout << a[i];
    cout << " ";
}
void Try(int i)
{
    for(int j = a[i-1]+1; j<= n-k+i; j++)
    {
        a[i] = j;
        if(i == k)
            out();
        else Try(i+1);
    }
}
int main()
{
    Try(1);
    return 0;
}
