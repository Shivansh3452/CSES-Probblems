#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// long long helper(int i,int n,int x,vector<int> &price,vector<int> &pages,vector<vector<long long>>& t){
//     if(x==0||i>=n)
//         return 0;
//     if(t[i][x]!=-1)
//         return t[i][x];
//     long long take=0;
//     if(price[i]<=x)
//         take=pages[i]+helper(i+1,n,x-price[i],price,pages,t);
//     long long skip=helper(i+1,n,x,price,pages,t);

//     t[i][x]=max(take,skip);
//     return t[i][x];
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int> price(n);
//     vector<int> pages(n);
//     for(int i=0;i<n;i++){
//         cin>>price[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>pages[i];
//     }
//     vector<vector<long long>>t(n+1,vector<long long>(x+1,-1));
//     long long ans=helper(0,n,x,price,pages,t);
//     cout<<ans<<endl;
//     return 0;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int> price(n);
    vector<int> pages(n);
    for(int &i:price)   cin>>i;
    for(int &i:pages)   cin>>i;
    vector<int>t(x+1,0);
    for(int i=0;i<n;++i){   // For each book
        for(int j=x;j>=price[i];--j){   // Iterate budget from high to low
            t[j]=max(t[j],t[j-price[i]]+pages[i]);
        }
    }
    cout<<t[x]<<endl;
    return 0;
}
/*
t[j] represents: maximum pages achievable with budget exactly j
Index j from 0 to x represents different budget amounts

we iterated j form x down to price[i] bcz descending order ensures each book is used at most once
if we went ascending we might use the same book multiple times
Example: If j goes up, t[j-price[i]] might already include the current book

t[j] = max(t[j], t[j-price[i]] + pages[i]) means:

Either skip the current book: keep t[j] as is

Or take the current book: add its pages to the best solution with budget j-price[i]
*/