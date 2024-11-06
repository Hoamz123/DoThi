#include<bits/stdc++.h>
using namespace std;
bool cmd(pair<int,int> a,pair<int,int> b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}
int main(){
    vector<pair<int,int>> v;
    int n,m;cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmd);
    vector<int> ve[n+1];
    ve[0].push_back(0);

    for(pair<int,int> it : v){
        ve[it.first].push_back(it.second);
    }
    cout << endl;
    for(int i=1;i<=n;i++){
        cout << i << " : ";
        for(int x : ve[i]) cout << x << " ";
        cout << endl;
    }
}