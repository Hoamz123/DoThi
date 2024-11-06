
/*
CHUA TOI UU
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
int f[1001][1001];
int vst[1001] = {0};

void DFS(int u){
    vst[u] = 1;//danh dau
    for(int i : ke[u]){
        if(vst[i] == 0){
            f[u][i] = 1;
            f[i][u] = 1;
            DFS(i);
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    int q;cin >> q;//so truy van
    for(int i=1;i<=n;i++){
        if(vst[i] == 0){
            DFS(i);
        }
    }
    while(q--){
        int x,y;cin >> x >> y;
        if(f[x][y] == 1) cout << 1 << endl;
        else cout << -1 << endl;
    }
}*/


//DA TOI UU (ton it bo nho hon)
#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int n,m;
int vst[1001] = {0};
int ID[1001];//luu thanh phan lien thong cua cac dinh
int dem = 0;
void DFS(int u){
    vst[u] = 1;//danh dau la da di qua
    ID[u] = dem;
    for(int i : ke[u]){
        if(vst[i]==0){
            DFS(i);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(vst[i]==0){
            //neu dinh i chua duoc duyet qua
            dem++;
            DFS(i);
        }
    }

    int q;cin >> q;//quy true van
    while(q--){
        int x,y;cin >> x >> y;//xem x co the di den y hay khong
        if(ID[x] == ID[y]){
            //x,y chung thanh phan lien thong thi chan chan co the di den nhau
            cout << "1" << endl;
        }
        else cout << "-1" << endl;
    }
}