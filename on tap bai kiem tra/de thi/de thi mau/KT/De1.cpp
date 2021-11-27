#include<bits/stdc++.h>
using namespace std;

struct Student
{
    char name[10];
    float diemtb;
    float tienht;
    void showStudent(){
        cout << name << " " << diemtb << " " << tienht;
    }
};
const int n = 8;
Student a[n] =
    {{"Hieu", 9.5, 20},
     {"Hung", 8.5, 15.5},
     {"Hong", 9, 25.5},
     {"Duc", 9.5, 20.5},
     {"Lam", 9.5, 20.5},
     {"Toan", 7, 20},
     {"Hoa", 7.5, 19.5},
     {"Hien", 6.5, 15}};
int x[n], check[n]={};
void daonguoc(Student a[],int n)
{
    if(n == 1)
    {
        a[n-1].showStudent();
        cout << endl;
    }
    else
    {
        a[n-1].showStudent();
        cout << endl;
        daonguoc(a,n-1);
    }
}
void sapxep(Student a[], int n)
{
    for(int i = 0; i< n-1; i++)
        for(int j = i+1; j< n; j++)
        {
            if(a[i].tienht > a[j].tienht)
            {
                Student tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
}
int layHocSinh(Student a[], int n, float p)
{
    sapxep(a,n);
    int i = 0;
    int dem = 0;
    while(p>0 && i < n){
        if(p >= a[i].tienht)
        {
            p = p - a[i].tienht;
            dem++;
            i++;
        }
        else
            i++;
    }
    return dem;
}
void out()
{
    for(int i= 1; i<=n; i++)
        cout << a[x[i]-1].name << " ";
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
int main()
{
    daonguoc(a,n);
    Student b[n];
    for(int i = 1; i<n; i++)
        b[i] = a[i];
    float p = 110;//So tien khong duoc vuot qua
    cout << "Co the lay duoc nhieu nhat " << layHocSinh(b,n,p) << " de tong so tien hoc them nho hon " << p << endl;
    Try(1);
    return 0;
}
