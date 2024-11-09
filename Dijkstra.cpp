#include<bits/stdc++.h>

#define inf INT_MAX

using namespace std;

/* Viet chuong trinh duong di nho nhat 
tu 1 dinh den tat ca cac dinh con lai su dung thuat toan Dijkstra */

// Ham Dijkstra
void Dijkstra(int V, vector<vector<int>> &G, int n){
    // Mang khoang cach, khoi tao la inf
    vector<int> d(V, inf);  
    d[n] = 0;	// Khoang cách toi dinh nguon khoi tao = 0
    
    vector<bool> Visited(V, false);  // Mang check xem dinh da co dinh chua
    
    // Hang doi uu tien gia tri nho nhat(first), pair first luu khoang cach d, pair second luu dinh gan nhat
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;  
    q.push({0, n});  // Day dinh nguon vao hang doi

    while (!q.empty()) {
        int u = q.top().second;  // Lay dinh co khoang cach nho nhat
        q.pop();
        if (Visited[u]) continue;  // Bo qua neu dinh nay da co dinh
        Visited[u] = true;  // Danh dau dinh da duoc co dinh
        
        // Duyet qua tat ca cac dinh ke voi u
        for (int v = 0; v < V; v++) {
            if (G[u][v] != inf && !Visited[v]) {  // Neu co canh noi va chua co dinh
                int w = G[u][v];
                if (d[v] > d[u] + w) {	// Neu tim duoc duong di ngan hon
                    d[v] = d[u] + w;
                    q.push({d[v], v});  // Day dinh ke vao hang doi
                }
            }
        }
	}
    
    cout << "Khoang cach tu dinh " << n+1 << " den cac dinh khac:\n";
    for (int i = 1; i < V; i++) { 
        if (d[i] == inf) 
            cout << i+1 << ": inf\n";  
        else
            cout << i+1 << " -> " << d[i] << "\n"; 
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
            if(G[i][j]==0 && i != j)	G[i][j] = inf;
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
    
    // Dijkstra
    Dijkstra(V, G, n);
    
    return 0;
}
