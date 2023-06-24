class Solution {
public:
  //tabulation
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=0;

        unordered_map<int,int> mp[n+1];

        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                int diff=nums[i]-nums[j];
                int cnt=1;//no of element in ap here 1 is for j

                //check for this j with that diff answer is present
                if(mp[j].count(diff)) {
                    cnt=mp[j][diff];
                }

                mp[i][diff]=1+cnt;
                ans=max(ans,mp[i][diff]);
            }
        }
        return ans;
    }
};
