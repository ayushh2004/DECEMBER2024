class Solution {
    private:
    bool hasDuplicate(string &s1, string &s2) {
        vector<int> hash(26, 0);
        for (char &ch : s1) {
            if (hash[ch - 'a'] > 0) return true;
            hash[ch - 'a']++;
        }
        for (char &ch : s2) {
            if (hash[ch - 'a'] > 0) return true;
        }

        return false;
    }
    int solve(int idx,string temp,vector<string> &arr,int n){
        if(idx>=n){
            return temp.length();
        }
        int exclude=0, include=0;
        if(hasDuplicate(arr[idx],temp)){
            exclude=solve(idx+1,temp,arr,n);
        }else{
            exclude=solve(idx+1,temp,arr,n);
            include=solve(idx+1,temp+arr[idx],arr,n);
        }
        return max(exclude,include);
    }
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        return solve(0,temp,arr,n);
    }
};
