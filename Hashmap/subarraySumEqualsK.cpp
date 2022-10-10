class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum]=1;
        for(auto it:nums){//iterating on nums
            sum+=it;//adding the iterator element to sum
            int diff=sum-k;
            if(mp.find(diff)!=mp.end()) {//check diff is mapped or not
                ans+=mp[diff];//adding the frequency of that key
            }
            mp[sum]++;//mapping the sum
        }
        return ans;
    }
};
