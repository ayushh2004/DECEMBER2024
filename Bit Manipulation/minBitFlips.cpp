class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        //checking set bits in ans->flipped
        int cnt=0;
        for(int i=0;i<32;i++){
            if((1<<i)&ans) cnt++;
        }
        return cnt;
    }
};
