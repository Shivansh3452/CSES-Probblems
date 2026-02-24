#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct project{
    int start;
    int end;
    int val;

    bool operator<(const project& other)const{
        return end<other.end;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<project>projects(n);
    for(int i=0;i<n;i++){
        cin>>projects[i].start>>projects[i].end>>projects[i].val;
    }
    sort(projects.begin(),projects.end());
    set<pair<int,ll>>ends;
    ends.insert({0,0});
    ll ans=0;
    for(int i=0;i<n;i++){
        auto t=ends.lower_bound({projects[i].start,-1}); 
        //performs binary search on a sorted range and 
        // returns an iterator pointing to first element that a>=target
        t--;
        ans=max(ans,projects[i].val+t->second);
        ends.insert({projects[i].end,ans});
    }
    cout<<ans<<endl;
    return 0;
}

