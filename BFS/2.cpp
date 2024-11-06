//tim duong di tren do thi vo huong su dung BFS
#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int n,m,s,t;
int parent[1001];

void BFS(int u){
    queue<int> q;
    vst[u] = 1;//danh dau la da di qua
    q.push(u);
    while(!q.empty()){
        int x = q.front();q.pop();
        for(int i : ke[x]){
            if(vst[i] == 0){
                vst[i] = 1;//danh dau
                parent[i] = x;//tu dinh x co the di xuong dinh i
                q.push(i);
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
    BFS(s);
    if(vst[t] == 0){
        //ko di dc
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
    return 0;//neu do thi khong co trong so thi su dung BFS() se cho duong di ngan nhat
}