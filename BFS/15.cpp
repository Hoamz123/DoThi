#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int parent[1001];
int n,m,s,t;
void BFS(int u){
    queue<int> q;
    vst[u] = 1;
    q.push(u);
    while(!q.empty()){
        int x = q.front();q.pop();
        for(int i : ke[x]){
            if(vst[i] == 0){
                vst[i] = 1;
                q.push(i);
                parent[i] = x;
            }
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
    for(int i=0;i<n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    BFS(s);
    if(vst[t] == 0){
        cout << -1;//khong co duong di
    }
    else{
        vector<int> res;//luu cac din hdi qua
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(t);
        reverse(res.begin(),res.end());
        for(int i : res) cout << i << " ";
    }
}