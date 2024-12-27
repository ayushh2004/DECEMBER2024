class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> greatest(n,0);
        greatest[0]=values[0];
        for(int i=1;i<n;i++){
            greatest[i]=max(greatest[i-1],values[i]+i);
        }
        int maxi=INT_MIN;
        for(int j=1;j<n;j++){
            maxi=max(maxi,greatest[j-1]+(values[j]-j));
        }
        return maxi;
    }
};
