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
    vector<int> v(n+1);
    function<void(int,int)> func;
    func = [&](int vert, int par){
        v[vert] = v[par]+1;
        for(auto it:tree[vert]){
            if(it==par) continue;
            func(it,vert);
        }
    };
    func(1,0);
    int root = 0,maxht=0;
    for(int i=1;i<=n;i++){
        if(maxht<v[i]){
            maxht=v[i];
            root=i;
        }
        v[i]=0;
    }
    func = [&](int vert, int par){
        
        for(auto it:tree[vert]){
            if(it==par) continue;
            func(it,vert);
            v[vert] = max(v[vert],v[it]+1);
        }
    };
    func(root,0);
    int ans=0;
    for(auto it:v){
        ans=max(ans,it);
    }
    cout<<ans<<endl;
}