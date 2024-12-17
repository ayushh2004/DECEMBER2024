class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0,r=0,maxLength=0;
        vector<int> hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            maxLength=max(maxLength,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxLength;
    }
};
