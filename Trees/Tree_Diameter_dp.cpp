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
    vector<int> maxdim(n+1),maxht(n+1);
    function<void(int,int)> func;
    func = [&](int vert, int par){
        for(auto it :tree[vert]){
            if(it==par) continue;
            func(it,vert);
            maxht[vert] =max(maxht[vert],maxht[it]+1);
        }
        if(tree[vert].size() - (par!=0)==0) maxdim[vert]=0;
        else if(tree[vert].size() - (par!=0)==1) maxdim[vert]=maxht[vert];
        else{
            int a=0,b=0;
            for(auto it:tree[vert]){
                if(it==par) continue;
                if(a<maxht[it]){
                    b=a;
                    a=maxht[it];
                }
                else if(b<maxht[it]){
                    b = maxht[it];
                }
            }
            maxdim[vert] = a+b+2;
        }
    };
    func(1,0);
    int ans=0;
    for(auto it:maxdim) ans = max(ans,it);
    // for(auto it:maxht) cout<<it<<' ';
    // cout<<endl;
    // for(auto it:maxdim) cout<<it<<' ';
    // cout<<endl;
    cout<<ans<<endl;

}