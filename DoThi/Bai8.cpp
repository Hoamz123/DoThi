#include<bits/stdc++.h>
using namespace std;
int f[1001][1001] = {0};
int dx[1000001];//danh dau de luu mot cacnh mot lan
int main(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> f[i][j];
        }
    }
    memset(dx,1,sizeof(dx));
    vector<vector<int>> v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vector<int> tmp;
            if(f[i][j] != 0 && dx[f[i][j]]){
                dx[f[i][j]] = 0;//danh dau la da duyet roi
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(f[i][j]);
            }
            if(!tmp.empty()) v.push_back(tmp);
        }
    }
    for(vector<int> x : v){
        for(int i : x) cout << i << " ";
        cout << endl;
    }
}