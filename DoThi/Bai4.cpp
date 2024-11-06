#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<int> v[n+1];
    vector<pair<int,int>> ve;
    v[0].push_back(0);
    for(int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        for(char x : s) {
            if (isdigit(x)) {
                v[i].push_back(x - '0');
            }
        }
        sort(v[i].begin(),v[i].end());
    }
    
    for(int i=1;i<=n;i++){
        for(int x : v[i]){
            ve.push_back({i,x});
        }
    }
    cout << endl;
    for(pair<int,int> it : ve){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
