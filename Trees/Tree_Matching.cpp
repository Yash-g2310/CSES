#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    int ans=0;
    vector<bool> mark(n+1,false);
    function<void(int,int)> func;
    func = [&](int vert, int par){
        for(auto it:tree[vert]){
            if(it==par) continue;
            func(it,vert);
            
            if((!mark[it]) && (!mark[vert])){
                ans++;
                mark[it] = true;
                mark[vert] = true;    
            }
        }
    };    
    func(1,0);
    cout<<ans<<endl;
}