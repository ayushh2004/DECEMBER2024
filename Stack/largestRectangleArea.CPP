class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int maxArea=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int element=arr[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()? -1:st.top();
                maxArea=max(maxArea,element*(nse-pse-1));
            }
            st.push(i);
        }
        //leftover
        while(!st.empty()){
            int element=arr[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()? -1:st.top();
            maxArea=max(maxArea,element*(nse-pse-1));
        }
        return maxArea; //TC->O(2N)
    }
};
