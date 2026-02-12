#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(),pairs.end(),
    [&](vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    });
    int count=1;
    int n=pairs.size();
    int lst_end=pairs[0][1];
    for(int i=1;i<n;i++){
        if(pairs[i][0]>lst_end){
            count++;
            lst_end=pairs[i][1];
        } 
    }
    return count;
}

/*
int t[1001][1001];
    int lis(vector<vector<int>> &pairs,int prev,int curr){
        if(curr==pairs.size())
            return 0;
        if(t[prev+1][curr]!=-1)
            return t[prev+1][curr];
        int taken=0;
        if(prev==-1 ||pairs[curr][0]>pairs[prev][1]){
            taken=1+lis(pairs,curr,curr+1);
        }
        int not_taken=lis(pairs,prev,curr+1);
        return t[prev+1][curr]=max(taken,not_taken);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        memset(t,-1,sizeof(t));
        sort(begin(pairs),end(pairs));
        return lis(pairs,-1,0);
        }
*/

int main(){
    int n;
    cin>>n;     //pairs.size() is taken as input here
    vector<vector<int>> pairs(n,vector<int>(2));
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a;
        cin>>b;
        pairs[i][0]=a;
        pairs[i][1]=b;
    }
    int ans=findLongestChain(pairs);
    cout<<ans<<endl;

    return 0;

}
