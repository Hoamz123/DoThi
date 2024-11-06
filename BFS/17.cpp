#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
int vst[1001] = {0};
int cha[1001];
int n,m,s,t;
void BFS(int u){
    queue<int >q;
    q.push(u);
    vst[u] = 1;
    while(!q.empty()){
        int x = q.front();q.pop();
        for(int i : ke[x]){
            if(vst[i] == 0){
                vst[i] = 1;
                q.push(i);
                cha[i] = x;
            }
        }
    }
}
int main(){
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    BFS(s);
    if(vst[t] == 0){
        cout << -1;
    }
    else{
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = cha[t];
        }
        res.push_back(t);
        reverse(res.begin(),res.end());
        for(int i : res) cout << i << " ";
    }
}