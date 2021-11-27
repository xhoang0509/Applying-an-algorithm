int f(int m, int n) { //Dùng k? thu?t d? quy có nh?
if (m == 0){
if (n == 0){
a[m][n] = 1;
}
else a[m][n] = 0;
}
}
else {
if (m > n) a[m][n] = f(m – 1, n);
else a[m][n] = f(m – 1, n) + f(m, n – m);
}
return a[m][n];
}
