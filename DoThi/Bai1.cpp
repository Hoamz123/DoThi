#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin >> n >> m;
    vector<int> v[n+1];
    v[0].push_back(0);
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        cout << i << " : ";
        sort(v[i].begin(),v[i].end());
        for(int it : v[i]) cout << it << " ";
        cout << endl;
    }
}