// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Input
// The only input line has an integer n.
// Output
// Print one integer: the minimum number of steps.
// Constraints
// 1<n<10^6
// Example
// Input:
// 27
// Output:
// 5

#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int t[1000001];
int helper(int n){
    if(n==0)
        return 0;
    if(t[n]!=-1)
        return t[n];
    int minSteps=INT_MAX;
    int temp=n;
    while(temp>0){
        int digit=temp%10;
        if(digit!=0)
            minSteps=min(minSteps,1+helper(n-digit));
        temp/=10;
    }
    t[n]=minSteps;
    return minSteps;
}

int main(){
    int n;
    cin>>n;
    int temp=n;
    memset(t,-1,sizeof(t));
    int ans=helper(n);
    cout<<ans<<endl;
    return 0;
}
