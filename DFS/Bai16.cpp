#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int parent[1001];
int n,m,s,t;
void DFS(int u){
    vst[u] = 1;//danh dau la da di qua
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
        ke[x].push_back(y);//co huong
    }
    for(int i=0;i<n;i++){
        sort(ke[i].begin(),ke[i].end());
    }

    DFS(s);
    if(vst[t] == 0){
        cout << -1;
    }
    else{
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(),res.end());
        for(int i : res) cout << i << " ";
    }

}