#include <bits/stdc++.h>
using namespace std;

void resultingArray(vector<int> &nums,vector<vector<int>> &queries){
    int n=nums.size();
    for(int i=0;i<queries.size();i++){
        int l=queries[i][0];
        int r=queries[i][1];
        int x=queries[i][2];
        nums[l]+=x;
        nums[r+1]=-x;
    }
    vector<int> prefixSum(n,0);
    prefixSum[0]=nums[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    for(int i=0;i<n;i++){
        cout<<prefixSum[i]<<" ";
    }
}

int main() {
    int n,q;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>q;
    vector<vector<int>> queries(q,vector<int>(3));
    for(int i=0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1]>>queries[i][2];
    }
    resultingArray(arr,queries);
	return 0;
}
