#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int n,m,s;
int vst[1001] = {0};
void DFS(int u){
    cout << u << " ";
    vst[u] = 1;//xet qua roi thi danh la 1
    for(int x : ke[u]){
        if(vst[x] == 0){
            DFS(x);
        }
    }
}
int main(){
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    DFS(s);
}