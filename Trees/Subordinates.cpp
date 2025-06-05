#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        tree[x].push_back(i);
    }
    vector<int> dp(n+1);
    function<void(int)> func;
    func = [&](int i){
        for(auto it:tree[i]){
            func(it);
            dp[i]+=dp[it];
        }
        dp[i]+=tree[i].size();
    };
    func(1);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<' ';
    }
    cout<<endl;
}