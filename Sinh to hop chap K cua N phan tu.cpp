#include<iostream>

using namespace std;
int n, k, a[1000]; bool final = false;
// Cấu hình ban đầu
void ban_dau(){
    for(int i=1; i<=n; i++)
        a[i]=i;
}
// Thuật toán sinh
void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n-k+i){
        	i--;
    }
    if(i == 0) 
        final = true;
    else{
    	a[i]++;
        for(int j = i + 1; j <= k; j++)
            a[j] = a[i] + j - i; 
	} 
}

int main(){
    cin >> n >> k;
    ban_dau();
    // in ra từng cấu hình cho đến cấu hình cuối cùng
    while(!final){
        for(int j = 1; j <= k; j++)
            cout << a[j];
        cout << endl;
        sinh();
    }
    return 0;
}
