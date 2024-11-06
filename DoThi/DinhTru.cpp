#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int n,m;
//dinh tru la khi xoa dinh do va cac canh tu dinh do den cac dinh khac thi lm cho thanh phan lien thong tang nen
void DFS(int u){
    vst[u] = 1;///danh dau la da di qua
    for(int i : ke[u]){
        if(vst[i] == 0){
            vst[i] = 1;
            DFS(i);
        }
    }
}
int tplt(){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(vst[i] == 0){
            ++cnt;
            DFS(i);
        }
    }
    return cnt;
}
int dem =0 ;//dem so dinh tru
void solve(){
    int cnt = tplt();
    for(int i=1;i<=n;i++){
        memset(vst,0,sizeof(vst));
        vst[i] = 1;//danh dau la da di qua
        if(cnt < tplt()){
            dem++;
        }
    }
}
//do phuc tap O(V * (E + V))
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    solve();
    cout << dem;
}