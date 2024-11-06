#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
int vst[1001] = {0};
void DFS(int u){
    vst[u] = 1;//danh dau la da duyet qua
    for(int i : ke[u]){
        if(vst[i] == 0){
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
    int cnt = 0;//dem so thanh phan lien thong
    for(int i=1;i<=n;i++){
        if(vst[i] == 0){
            DFS(i);
            cnt++;
        }
    }
    cout << cnt;
}