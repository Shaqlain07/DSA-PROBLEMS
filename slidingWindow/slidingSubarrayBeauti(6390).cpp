class Solution {
public:
    int helper(vector<int>& freq,int x) {
        int cnt=0;
        for(int i=0;i<freq.size();i++) {
            if(freq[i]!=0) {
                cnt+=freq[i];
                if(cnt>=x) {
                    return (i-50);
                }
            }
        }
        return -1;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int> freq(101,0);
        int n=nums.size();
        for(int i=0;i<k;i++) {
            int t=nums[i];
            freq[t+50]++;
        }
        for(int i=k;i<n;i++) {
            int t=nums[i];
            int idx=helper(freq,x);
            if(idx>=0) {
                ans.push_back(0);
                freq[nums[i-k]+50]--;
                freq[t+50]++;
                continue;
            }
            ans.push_back(idx);
            freq[nums[i-k]+50]--;
            freq[t+50]++;    
        }
        int idx=helper(freq,x);
        if(idx>=0) {
            ans.push_back(0);
        }
        else {
            ans.push_back(idx);
        }
        return ans;
    }
};
