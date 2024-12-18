class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1,leftMax=0,rightMax=0,total=0;
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(leftMax>arr[l]) total+=(leftMax-arr[l]);
                else leftMax=arr[l];
                l++;
            }else{
                if(rightMax>arr[r]) total+=(rightMax-arr[r]);
                else rightMax=arr[r];
                r--;
            }
        }
        return total;
    }
};
