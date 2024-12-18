#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(vector<int> &nums){
    int n=nums.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i]=-1;
        }else{
            nge[i]=st.top();
        }
        st.push(nums[i]);
    }
    for(int i=0;i<n;i++) cout<<nge[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextGreaterElement(arr);
    return 0;
}
