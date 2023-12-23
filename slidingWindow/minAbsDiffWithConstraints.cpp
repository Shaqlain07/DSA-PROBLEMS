class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        // iterate from x to n 
        int res=INT_MAX;
        for(int i=x;i<nums.size();i++) {
            // have a set and store i-x(last) value of nums 
            // for finding difference
            s.insert(nums[i-x]);
            // from the set find min difference
            // for that use lower bound
            auto it=s.lower_bound(nums[i]);
            // we got no lower bound
            if(it==s.end()) {
                if(it!=s.begin()) {// make sure its not the first value
                    // that's why we can go back
                    --it;
                    res=min(res,abs(nums[i]-(*it)));
                }
            }
            else {
                //we got lower bound
                res=min(res,abs((*it)-nums[i]));
                
                // we need to check the previous iterator for minimum
                // 1,4,5 low(3) will be give 4 but ans is 1
                if(it!=s.begin()) {
                    it--;
                    res=min(res,abs((*it)-nums[i]));
                }
                
            }
        }
        return res;
    }
};
