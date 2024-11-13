#include<bits/stdc++.h>

#define inf INT_MAX

using namespace std;


/*De bai: Viet chuong trinh tim duong di nho nhat toi tat ca cac dinh con lai su dung bellman-ford
	Ma tran ke: 
		0 1 0 0 0 0
		0 0 5 2 0 7
		0 0 0 0 2 1
		2 0 1 0 4 0
		0 0 0 3 0 0
		0 0 0 0 10 0
*/

// Ham Bellman-Ford
void Bellmanford(int V, vector<vector<int>> &G, int n) {
    vector<int> d(V, inf);  // Mang khoang cach, khoi tao la inf
    vector<int> p(V, -1);   // Mang luu dinh truoc do
    d[n] = 0;  // Khoang cach toi dinh nguon khoi tao = 0
    p[n] = n;  // Dinh truoc cua nguon la chinh no
    bool ok = false;

// Relaxation tat ca cac canh toi da V-2 lan
    for (int i = 1; i <= V - 2; i++) {
        ok = true;
        for (int v = 0; v < V; v++) {
            for (int u = 0; u < V; u++) {
                if (G[u][v] != inf && d[u] != inf && d[v] > d[u] + G[u][v]) {
                    d[v] = d[u] + G[u][v];
                    p[v] = u;
                    ok = false;
                }
            }
        }
        if (ok) break;  // Neu data ko doi, thoat vong lap
    }

//Kiem tra chu trinh am
    if (!ok) {
        cout << "Do thi thi chua chu trinh am";
        return;
    }


    cout << "Khoang cach ngan nhat tu dinh " << n + 1 << " den cac dinh khac:\n";
    for (int i = 0; i < V; i++) {
        if (d[i] == inf)
            cout << i + 1 << ": inf\n";
        else {
            cout << i+1 << " -> " << d[i] << "\n";
        }
    }
}

int main(){
// Tao 1 ma tran ke 
    cout << "Nhap so dinh cua do thi: ";
    int V;  cin >> V;
    vector< vector<int> > G( V, vector<int>(V, 0) ); 
    
// Nhap ma tran ke, neu 2 dinh khong ke nhau, in ra inf
    cout << "Nhap ma tran ke:\n";
    for(int i=0; i< V; i++){ 
        for(int j=0 ;j< V; j++){
            cin >> G[i][j];
            if(G[i][j] == 0 && i != j)	G[i][j] = inf;
        }
    }
    
// In ra ma tran ke
    cout << "Ma tran ke:\n";
    for( int i=0; i< V; i++){ 
        for(int j=0; j< V; j++){
            if(G[i][j] == inf)	cout << "inf ";
            else	cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
// Nhap dinh nguon
    cout << "Nhap dinh nguon: ";
    int n; cin >> n;
    n--; 
    cout << endl;
    
// Bellmanford
    Bellmanford(V, G, n);
    
    return 0;
}
