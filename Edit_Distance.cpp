#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;

// int t[5001][5001];
// int helper(int i,int j,string s1,string s2){
//     if(i==s1.size())
//         return s2.size()-j;
//     if(j==s2.size())
//         return s1.size()-i;
//     if(s1[i]==s2[j])
//         return helper(i+1,j+1,s1,s2);
//     if(t[i][j]!=-1)
//         return t[i][j];
//     int add=1+helper(i,j+1,s1,s2);
//     int remove=1+helper(i+1,j,s1,s2);
//     int replace=1+helper(i+1,j+1,s1,s2);
//     return t[i][j]=min({add,remove,replace});
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> t(n+1, vector<int>(m+1));
    for(int i=0;i<=n;i++)
        t[i][0]=i;
    for(int j=0;j<=m;j++)
        t[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                t[i][j]=t[i-1][j-1];
            else{
                t[i][j]=1+min({
                        t[i][j-1],
                        t[i-1][j],
                        t[i-1][j-1]
                });
            }
        }
    }
    cout<<t[n][m]<<endl;
    return 0;
}