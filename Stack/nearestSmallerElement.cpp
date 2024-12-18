#include <bits/stdc++.h>
using namespace std;

void nearestSmallerElement(vector<int> &nums){
    int n=nums.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=nums[i]){
            st.pop();
        }
        nse[i]=st.empty()? -1:st.top();
        st.push(nums[i]);
    }
    for(int i=0;i<n;i++) cout<<nse[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nearestSmallerElement(arr);
    return 0;
}
