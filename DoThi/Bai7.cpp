#include<bits/stdc++.h>
using namespace std;
int f[1001][1001] = {0};
int main(){
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin >> x >> y;
        f[x][y] = 1;
        f[y][x] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}