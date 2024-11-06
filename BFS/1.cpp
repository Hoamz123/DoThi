#include<bits/stdc++.h>
using namespace std;
//tim kiem theo chieu rong

vector<int> ke[1001];
int vst[1001] = {0};
int n,m,s;

void BFS(int u){
    queue<int> q;
    vst[u] = 1;//danh dau la da di qua
    q.push(u);
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

    BFS(s);

    return 0;
}