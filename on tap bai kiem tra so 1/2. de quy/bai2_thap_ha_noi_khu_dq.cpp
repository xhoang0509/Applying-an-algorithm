#include<bits/stdc++.h>
#include <stack>
using namespace std;

struct Call{
    int n;
    char a;
    char b;
    char c;
};
//Cau truc du lieu ngan xep
struct Stack{
    int top;
    Call *e;
};
//Cac phep toan ngan xep
void init(Stack &s)// Khoi tao ngan xep rong
{
    s.top == -1;
    s.e = NULL;
}
bool empty(Stack s)//Kiem tra ngan xep rong
{
    return s.top ==-1;
}
void push(Stack &s, Call call_in) { // Day la mot phan tu (loi goi) vao ngan xep
	// Cap phat bo nho cho mang e
	if (empty(s)) {
		s.e = new Call[1]; // cap phat moi
	}
	else {
		// cap phat them mot phan tu, cho mot loi goi
		s.e = (Call*)realloc(s.e, (s.top +2) * sizeof(Call)); // top + 2= n +1
	}
	s.top++;
	s.e[s.top] = call_in;
}
void Pop(Stack &s, Call &call_out)
{
    if(empty(s)) return;

    call_out = s.e[s.top];//
    if(s.top == 0){//Lay ra het khoi tao ngan xep rong
        delete []s.e;
        init(s);
    }
    else //Van con, cap phat giam 1 phan tu
    {
        s.e = (Call*) realloc(s.e,s.top * sizeof(Call)); // top = n - 1
        s.top --;
    }
}

//Ham khu de quy cho bai toan thap ha Noi
void thapHaNoi(Call first_call){
    Call call_in, call_out;
    Stack s;
    //Day loi goidau tien vao ngan xep
    init(s);
    call_in = first_call;
    push(s,call_in);
    while (!empty(s)) {
        //Lay mot loi goi tu ngan xep de xy ly
        Pop(s,call_out);
        if(call_out.n == 1)
            cout << "Chuyen 1 dia tu coc: " << call_out.a << " sang coc: " << call_out.c << endl;
            else { // n> 1 co 3 loi goi day vao ngan xep
                //Chuyen n-1 dia tu coc b sang coc c - chuyen(n-1,b,a,c)
                call_in.n = call_out.n-1;
                call_in.a = call_out.b;
                call_in.b = call_out.a;
                call_in.c = call_out.c;
                push(s,call_in);

                //
                call_in = call_out;
                call_in.n  = 1;
                push(s,call_in);

                //
                call_in.n = call_out.n-1;
                call_in.a = call_out.a;
                call_in.b = call_out.c;
                call_in.c = call_out.b;
                push(s,call_in);
            }
    }
}
int main() {
  Call first_call  = {4,'A','B','C'};
  thapHaNoi(first_call);
  return 0;
}