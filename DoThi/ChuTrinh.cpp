#include<bits/stdc++.h>
using namespace std;
//chu trinh la tu dinh s co the di den dinh t va co duong tu dinh t ve dinh s
vector<int> ke[1001];
int vst[1001] = {0};
int n,m;
int p[1001];//luu cha cua dinh i
int ok = 0;//check xem co chu trinh hay khong
void DFS(int u){
    vst[u] = 1;//danh dau la da di qua dinh u
    for(int i : ke[u]){
        if(vst[i] == 0){
            p[i] = u;
            DFS(i);
        }
        else if(p[u] != i){
            ok = 1;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    DFS(1);
    if(ok) cout << "YES";
    else cout << "NO";
}