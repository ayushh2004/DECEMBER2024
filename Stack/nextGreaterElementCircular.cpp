#include <bits/stdc++.h>
using namespace std;

void nextGreaterElementCircular(vector<int> &nums){
    int n=nums.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i=(2*n)-1;i>=0;i--){ //O(2N)
        while(!st.empty() && st.top()<=nums[i%n]){ //O(2N)
            st.pop();
        }
        if(i<n){
            nge[i]=st.empty()? -1:st.top();
        }
        st.push(nums[i%n]);
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
    nextGreaterElementCircular(arr);
    return 0;
}
