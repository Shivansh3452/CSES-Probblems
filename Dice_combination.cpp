#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define mod 1000000007
using namespace std;

int dfs(int n,vector<int> &dp){
    if(n==0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    long long count=0;
    for(int i=1;i<=6;++i){
        if(n-i>=0)
            count=(count+dfs(n-i,dp))% mod;
    }
    dp[n]=count;
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    int res=dfs(n,dp);
    cout<<res<<endl;

    return 0;
}