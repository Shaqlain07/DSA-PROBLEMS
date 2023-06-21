class Solution {
public:
    long long minimumCost(string s) {
        long long cost=0;
        int n=s.size();
        for(int i=0;i<n-1;i++) {
            if(s[i]!=s[i+1]) {
                cost+=min(i+1,n-i-1);
            }
        }
        return cost;
    }
};
