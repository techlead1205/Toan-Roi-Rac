#include<iostream>
using namespace std;
int n, a[1000]; bool final = false;

// Cấu hình ban đầu
void ban_dau(){
    for(int i=1; i<=n; i++)
        a[i]=0;
}

// Thuật toán sinh
void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) 
        final = true;
    else 
        a[i] = 1;
}

int main(){
    cin >> n;
    ban_dau();
    // in ra từng cấu hình cho đến cấu hình cuối cùng
    while(!final){ 
        for(int j = 1; j <= n; j++)
            cout << a[j];
        cout << endl;
        sinh();
    }
    return 0;
}
