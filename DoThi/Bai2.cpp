#include<bits/stdc++.h>
using namespace std;
int f[1001][1001];
int main(){
    int n;cin >> n;
    cin.ignore();
    vector<int> v[n+1];
    v[0].push_back(0);
    for(int i=1;i<=n;i++){
        string s;getline(cin,s);
        for(char x : s){
            if(isdigit(x)) v[i].push_back(x - '0');
        }
    }
    cout << endl;
    memset(f,1,sizeof(f));
    for(int i=1;i<=n;i++){
        if(!v[i].empty()){
            for(int it : v[i]){
                if(f[i][it]){
                    f[it][i] = 0;//danh dau de khong in ra nhung o doi xung
                    cout << i << " " << it << endl;
                }
            }
        }
    }
}