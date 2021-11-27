#include<bits/stdc++.h>
using namespace std;

char *T = {"Nguyen Khac Hieu"};
char *P = {"Khac"};
int char_in_string(char T,char P[])
{
    int n = strlen(P);
    for(int i = 0; i< n; i++)
        if(P[i] == T)
            return i;
    return -1;
}
int Boyer_Moore_Horspool()
{
    int dem = 0, i = strlen(P), v = strlen(P);
    while (i < strlen(T))
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
    if (Boyer_Moore_Horspool())
        cout << "Xau P co là con cua xau T";
    else
        cout << "Xau T khong chua xau P";
    return 0;
}

