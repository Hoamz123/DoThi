#include<bits/stdc++.h>
using namespace std;
//canh cau la nhung canh ma khi xoa canh do di (van giu hai dinh) thi lam tang so thanh phan lien thong
vector<int> ke[1001];//danh sach canh ke
vector<pair<int,int>> v;//luu danh sach canh
int vst[1001] = {0};
int n,m;
//O(E * (V + E))
void DFS(int u,int s,int t){
    vst[u] = 1;
    for(int i : ke[u]){
        if((i == s && u == t) || (i == t && u == s)) continue;
        else if(vst[i] == 0){
            vst[i] = 1;//danh dau
            DFS(i,s,t);
        }
    }
}

int tplt(int s,int t){
    int cnt = 0;//dem so thanh phan lien thong
    for(int i=1;i<=n;i++){
        if(vst[i] == 0){
            //chua duoc dueyt qua
            ++cnt;
            DFS(i,s,t);
        }
    }
    return cnt;
}
int ans = 0;//dem so canh cau
void solve(){
    int tmp = tplt(0,0);
    for(pair<int,int> p : v){
        memset(vst,0,sizeof(vst));
        int x = p.first;int y = p.second;
        if(tmp < tplt(x,y)){
            ans++;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        v.push_back({x,y});
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    solve();
    cout << ans;

}