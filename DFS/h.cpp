#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int parent[1001];
int n,m,s,t;
void DFS(int u){
    vst[u] = 1;//danh dau la da duyet qua
    for(int i : ke[u]){
        if(vst[i] == 0){
            parent[i] = u;
            DFS(i);
        }
    }
}

int main(){
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    DFS(s);
    if(vst[t] == 0){
        cout << -1;
    }
    else{
        vector<int> res;//luu duong di
        while(t != s){
            //den khi nao 2 dinh trung nhua thi dung
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(),res.end());
        for(int i : res) cout << i << " ";
    }
}