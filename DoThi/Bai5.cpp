#include<bits/stdc++.h>
using namespace std;
int f[1001][1001];
int main(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> f[i][j];
        }
    }
    vector<int> v[n];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f[i][j] && j >= i){
                cout << j << " " << i << endl;
            }
            if(f[i][j]) v[i].push_back(j);
        }
    }
    cout << endl;
    
    for(int i=1;i<=n;i++){
        cout << i << " : ";
        for(int x : v[i]) cout << x << " ";
        cout << endl;
    }
}