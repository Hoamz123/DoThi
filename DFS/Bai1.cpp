#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visited[1001];
int a[1001][1001];
vector<pair<int,int>> c;
//tim kiem theo chieu sau
int n,m;
void DFS(int u){
    //hay dung
    cout << u << " ";
    visited[u] = true;
    //duyet qua ds ke cua dinh u
    for(int x : v[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

void DFS2(int u){
    cout << u << " ";
    visited[u] = true;
    //duyet ds ke cua dinh u  ;duyet cai dong thu u trong ma tran ke
    for(int i=1;i<=n;i++){
        if(a[u][i] == 1){
            if(!visited[i]){
                DFS2(i);
            }
        }
    }
}

void DFS3(int u){
    cout << u << " ";
    visited[u] = true;

    //duyet danh sach canh
    for(auto it : c){
        if(it.first == u){
            if(!visited[it.second]){
                DFS3(it.second);
            }
        }
        if(it.second == u){
            if(!visited[it.first]){
                DFS3(it.first);
            }
        }
    }

}
int main(){
    int n,m;cin >> n >> m;
    for(int i =1;i<=m;i++){
        int x,y;cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
}