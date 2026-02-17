/*
You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
Input
The first input line has two integers n and m: the array size and the upper bound for each value.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the array. Value 0 denotes an unknown value.
Output
Print one integer: the number of arrays modulo 10^9+7.
*/

#include<iostream>
#include<vector>
#include<cstring>
#define mod 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    // dp[i][v] = ways to fill first i+1 positions ending with value v
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    // Base case: first element
    if(nums[0]==0){
        for(int v=1;v<=m;v++)
            dp[0][v]=1;
        
    }
    else
        dp[0][nums[0]]=1;
    
    // Fill DP table
    for(int i=1;i<n;i++) {
        for(int v=1;v<=m;v++) {
            if(nums[i]==0||nums[i]==v){
                // Can come from v-1, v, or v+1
                dp[i][v]=(dp[i][v]+dp[i-1][v])%mod;  // same value
                if(v-1>=1)
                    dp[i][v]=(dp[i][v]+dp[i-1][v-1])%mod;  // previous smaller
                
                if(v+1<=m)
                    dp[i][v]=(dp[i][v]+dp[i-1][v+1])%mod;  // previous larger
                
            }
        }
    }
    // Calculate answer
    int ans=0;
    if(nums[n-1]==0) {
        for(int v=1;v<=m;v++)
            ans=(ans+dp[n-1][v])%mod;
    }
    else
        ans=dp[n-1][nums[n-1]];
    cout<<ans<<endl;
    return 0;
}