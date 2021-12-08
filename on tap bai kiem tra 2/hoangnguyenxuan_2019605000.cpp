#include <bits/stdc++.h>
using namespace std;

struct CongTy {
	string tenCty;
	int soHangHoa;
	int doanhThu;
	int soNhanVien;
};

const int n = 8;
CongTy d[n] = {
	{"FPT", 20, 10000, 120},
	{"Viettel", 10, 15000, 200},
	{"Sam sungTNHH", 15, 20000, 520},
	{"Apple", 23, 40000, 700},
	{"VinfastTNHH", 13, 33000, 900},
	{"Oppo", 17, 50000, 300},
	{"BKAVTNHH", 22, 30000, 140},
	{"Vinaphone", 29, 20000, 550}
};

void HangHoaMin(CongTy d[], int left, int right, int &hangHoaMin, int &x){
   if (left == right) {
        hangHoaMin = d[left].soHangHoa;
        x = left;
   }
   else {
       int mid = (left + right)/2;
       int hangHoaMin_l; int vt_left;
       int hangHoaMin_r; int vt_right;

       HangHoaMin(d,left,mid, hangHoaMin_l, vt_left);
       HangHoaMin(d,mid+1,right, hangHoaMin_r, vt_right);

       if (hangHoaMin_l < hangHoaMin_r) {
            hangHoaMin = hangHoaMin_l;
            x = vt_left;
       } else {
           hangHoaMin = hangHoaMin_r;
           x = vt_right;
       }
   }
}

int N = 2000;
int temp = 0;
int F[n+1][2001] = {0};
int i, j;
int algorithm() {
	for(int i = 0; i <= N; i++) F[0][j] = 0;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= N; j++) {
            F[i][j] = F[i - 1][j];
            temp = F[i - 1][j - d[i].soNhanVien] + d[i].doanhThu;
            if (d[i].soNhanVien <= j && F[i][j] < temp)
                F[i][j] = temp;
        }
    }
    return F[n][N];
}
void TruyViet(){
	cout << "Tong doanh thu lon nhat la: " << F[n][N] << endl;
	i = n; j = N;
	cout << "Cua cac cong ty: ";
	while (i != 0) {
		if (F[i][j] != F[i - 1][j]) {
			cout << d[i].tenCty << " | ";
			j = j - d[i].soNhanVien;
		} 
		i--;
	}
	cout << " <===> Co so nhan vien nho hon " << N << endl;
}

string P = "TNHH";
int KyTuTrongChuoi(char T,string P) {
    int n = P.length();
    for(int i = 0; i< n; i++) {
    	if(P[i] == T) {
    		return i;
		}            
	}        
    return -1;
}
int BoyerMooreHorspool(string T) {
    int count = 0;
	int i = P.length();
	int v = P.length();
    while (i < T.length() + 1) {
        int x = v - 1, j = i - 1;
        while (T[j] == P[x] && x > -1) {
            j--;
            x--;
        }
        if (x < 0) {
            count++;
            i = i + v;
        }
        else {
            x = KyTuTrongChuoi(T[j], P);
            if (x < 0) 
				i = i + v;
            else 
				i = i + v - x - 1;
        }
    }
    return count;
}

int main() {
	
	int hangHoaMin;
	int x;
	HangHoaMin(d, 0, n-1, hangHoaMin, x);
	cout << "Cong ty co hang hoa it nhat: " << d[x].tenCty << " voi so hang hoa la: " << d[x].soHangHoa << endl;
	
	
	algorithm();
	TruyViet();
	
	int count = 0;
    for (int i = 0; i < n; i++) {
        if (BoyerMooreHorspool(d[i].tenCty) != 0) {
            count++;
        }
    }
    cout << "So cong ty TNHH la: " << count;
}
