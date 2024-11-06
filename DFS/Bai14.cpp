#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
int vst[1001] = {0};
int pr[1001];
void DFS(int u){
    vst[u] = 1;
    for(int y : ke[u]){
        if(vst[y] == 0){
            DFS(y);
            pr[y] = u;
        }
    }
}

int main(){
    int n,m,s,t;cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    DFS(s);
    //BFS(s) : Lm tuong tu -> duong di ngan nhat
    if(vst[t] == 0){
        cout << -1;
    }
    else{
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t  = pr[t];
        }
        res.push_back(s);
        reverse(res.begin(),res.end());
        for(int i : res) cout << i << " ";
        
    }
}