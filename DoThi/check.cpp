//dinh tru
#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int vst[1001] = {0};
int n,m;
vector<pair<int,int>> v;//luu danh sach canh
int p[1001];//luu cha cua dinh i
int flag = 0;

void DFS(int u){
    vst[u] = 1;
    for(int i : ke[u]){
        if(vst[i] == 0){
            p[i] = u;
            DFS(i);
        }
        //neu dinh i da dc duyet qua
        else if(p[u] != i){
            flag = 1;
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
    DFS(1);
    if(flag) cout << "YES";
    else cout << "NO";
}