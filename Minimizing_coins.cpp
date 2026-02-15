#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;

int t[100][1000001];

int helper(int i,int n,vector<int> nums,int target){
    if(target==0)
        return 0;
    if(t[i][target]!=-1)
        return t[i][target];
    if(target<0||i>=n)
        return INT_MAX-1;
    int take=1+helper(i,n,nums,target-nums[i]);
    int skip=helper(i+1,n,nums,target );

    return t[i][target]=min(take,skip);
}

int main(){
    int n,x;        //no of coins and target
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    memset(t,-1,sizeof(t));
    int ans=helper(0,n,nums,x);
    cout<<ans<<endl;
    return 0;
}