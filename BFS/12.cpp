//[Graph].Bài 12. BFS trên đồ thị có hướng
#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int n,m,s;
void BFS(int u){
    queue<int> q;
    q.push(u);
    vst[u] = 1;
    while(!q.empty()){
        int x = q.front();q.pop();
        cout << x << " ";
        for(int i : ke[x]){
            if(vst[i] == 0){
                vst[i] = 1;
                q.push(i);
            }
        }
    }
}
int main(){
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    BFS(s);
}