#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;

vector<vector<long long>> t;
int target;
int helper(int i,int n,int sum){
    if(sum>target)
        return 0;
    if(i==n+1)
        return sum==target?1:0;
    if(t[i][sum]!=-1)
        return t[i][sum];
    long long addtoA=helper(i+1,n,sum+i);
    long long addtoB=helper(i+1,n,sum);

    return t[i][sum]=(addtoA+addtoB)%mod;
}

int main(){
    int n;
    cin>>n;
    int total=n*(n+1)/2;
    if(total%2!=0){
        cout<<0<<endl;
        return 0;
    }
    target=total/2;
    t.assign(n+2,vector<long long>(target+1,-1));
    long long ans=helper(1,n,0)*500000004LL%mod;
    cout<<ans<<endl;
    return 0;
}