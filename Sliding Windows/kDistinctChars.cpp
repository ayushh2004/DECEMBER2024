int kDistinctChars(int k, string &str)
{
    int l=0,r=0,maxLength=0;
    unordered_map<char,int> mp;
    while(r<str.length()){
        mp[str[r]]++;
        while(mp.size()>k){
            mp[str[l]]--;
            if(mp[str[l]]==0) mp.erase(str[l]);
            l++;
        }
        maxLength=max(maxLength,r-l+1);
        r++;
    }
    return maxLength;
} TC->O(2N)

optimized further
int kDistinctChars(int k, string &str)
{
    int l=0,r=0,maxLength=0;
    unordered_map<char,int> mp;
    while(r<str.length()){
        mp[str[r]]++;
        if(mp.size()>k){
            mp[str[l]]--;
            if(mp[str[l]]==0) mp.erase(str[l]);
            l++;
        }
        maxLength=max(maxLength,r-l+1);
        r++;
    }
    return maxLength;
} TC->O(N)
