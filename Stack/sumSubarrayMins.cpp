class Solution {
public:
    
    const int MOD=1e9+7;
    vector<int> previousSmallerOrEqualElement(vector<int>& arr){
        int n=arr.size();
        vector<int> psee(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            psee[i]=st.empty()? -1:st.top();
            st.push(i);
        }
        return psee;
    }
    vector<int> nextSmallerElement(vector<int>& arr){
        int n=arr.size();
        vector<int> nse(n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i]=st.empty()? n:st.top();
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long total=0;
        vector<int> nse(n), psee(n); //previous smaller or equal -> psse
        nse=nextSmallerElement(arr);
        psee=previousSmallerOrEqualElement(arr);
        for(int i=0;i<n;i++){
            int leftSubarray=i-psee[i];
            int rightSubarray=nse[i]-i;
            total=(total+(1LL*leftSubarray*rightSubarray%MOD)*arr[i]%MOD)%MOD;
        }
        return total;
    }
};
