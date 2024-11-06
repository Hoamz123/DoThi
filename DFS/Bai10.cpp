#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int n,m,s;
int vst[1001] = {0};
void DFS(int u){
    cout << u << " ";
    vst[u] = 1;//danh dau la duyet qua roi

    for(int i : ke[u]){
        if(vst[i] == 0){
            DFS(i);
        }
    }

}
int main(){
    //co huong
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    DFS(s);
}