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
        for(auto it:tree[vert]){
            if(it==par) continue;
            func(it,vert);
            v[vert] = max(v[vert],v[it]+1);
        }
    };
    for(int i=1;i<=n;i++){
        if(tree[i].size()==1){
            func(i,0);
            cout<<v[i]<<endl;
            return 0;
        }

    }
}