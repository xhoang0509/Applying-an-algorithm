#include <bits/stdc++.h>
using namespace std;

struct HocSinh {
	char hoTen[50];
	int tuoi;
	float diemTk;
};
const int n = 8;
HocSinh d[n] = {
	{"nguyen xuan hoang", 27, 8},
	{"the hung", 21, 5.5},
	{"tran tien", 20, 4},
	{"duc huong", 24, 9.8},
	{"van huong", 25, 7},
	{"khac hieu", 19, 7.5},
	{"khuong tran", 18, 6},
	{"nguyen xa la", 23, 9.5}
};

void DiemMax(HocSinh d[], int left, int right, float &diemMax, int &x){
   if (left == right) {
        diemMax = d[left].diemTk;
        x = left;
   }
   else {
       int mid = (left + right)/2;
       float diemMax_left; int vt_left;
       float diemMax_right; int vt_right;

       DiemMax(d,left,mid, diemMax_left, vt_left);
       DiemMax(d,mid+1,right, diemMax_right, vt_right);

       if (diemMax_left > diemMax_right) {
            diemMax = diemMax_left;
            x = vt_left;
       } else {
           diemMax = diemMax_right;
           x = vt_right;
       }
   }
}

//Cau 2
int L[30][30] ={0};
char *xc;
char A[30], B[30];
int lengthA, lengthB;
algorithm()
{
    for (int i = 0; i < lengthA; i++) L[i][0] = 0;
    for (int j = 0; j < lengthB; j++) L[0][j] = 0;
    for (int i = 1; i <= lengthA; i++)
        for (int j = 1; j <= lengthB; j++)
            if (A[i] == B[j])
                    L[i][j] = L[i-1][j-1] + 1;
                    else
                        L[i][j] = max(L[i-1][j], L[i][j-1]);
}
int xau_con() {
    int i = lengthA, j = lengthB, k = 0;
    while (L[i][j] != 0) {
        if(A[i-1] == B[j-1]) {
            xc[k] = A[i-1];
            k++;
            j--;
            i--;
        }
        else
            if(L[i-1][j] > L[i][j-1]) i--;
            else j--;
    }
    xc[k] = '\0';
    strrev(xc);
}
void xau_con_max() {
    strcpy(A, d[0].hoTen);
    strcpy(B, d[n-1].hoTen);
    lengthA = strlen(A);
    lengthB = strlen(B);
    xc = new char[lengthA];
    algorithm();
    xau_con();
}


// cau 3;
void z_algo(const char *s, int *z) {
    int n = strlen(s), l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r - l]== s[r])
				r++;
            z[i] = r - l;
            r --;
        }
        else if (z[i - l] < r - i + 1)
            z[i] = z[i-l];
        else {
            l = i;
            while (r < n && s[r - l] == s[r])
				r ++;
            z[i] = r - l;
            r --;
        }
    }
}
int CountTenHuong() {
	int count = 0;
	for(int i = 0; i < n; i++) {
		char s[50];
		strcpy(s, "");
		strcat(s, "huong$");
		strcat(s, d[i].hoTen);
		int z[strlen(s)] = {0};
		z_algo(s,z);
		if(z[strlen(s) -5] == 5 && s[strlen(s)-6] == ' ')
			count++;
	}
	return count;
}



int main() {
	float diemMax;
	int x;
	DiemMax(d, 0, n-1, diemMax, x);
	cout << "Hoc sinh co diem tk cao nhat" << endl; 
	cout << "Ten: " << d[x].hoTen << " | Diem: " << d[x].diemTk << endl;
	xau_con_max();
    cout << "Xau con chung cua hoc sinh dau tien va cuoi cung la: " << xc << endl;
	cout << "So hoc sinh ten huong la: " << CountTenHuong();
	
}
