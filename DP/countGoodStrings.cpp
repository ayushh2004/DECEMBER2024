class Solution {
public:
    const int M=1e9+7;
    int solve(int l,vector<int> &t,int low, int high, int zero, int one){
        if(l>high) return 0;
        if(t[l]!=-1) return t[l];
        bool addone=false;
        if(l>=low) addone=true;
        int addOne=solve(l+one,t,low,high,zero,one);
        int notAddOne=solve(l+zero,t,low,high,zero,one);
        return t[l]=(addone+addOne+notAddOne)%M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> t(high+1,-1);
        return solve(0,t,low,high,zero,one);
    }
};
