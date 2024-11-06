//[Graph]. Bài 11. BFS trên đồ thị vô hướng.
#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int n,m,s;
void BFS(int u){
    queue<int> q;
    q.push(u);
    vst[u] = 1;//danh dau
    while(!q.empty()){
        int x = q.front();q.pop();
        cout << x << " ";
        for(int i : ke[x]){
            if(vst[i] == 0){
                q.push(i);
                vst[i] = 1;
            }
        }
    }
    
}
int main(){
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    BFS(s);

}
/*
5 7 5
4 1
5 3
4 3
5 1
3 2
4 2
2 1

*/