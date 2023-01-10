class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique( nums.begin(), nums.end() ), nums.end());
        int cnt=1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) {
                if(nums[i]==cnt) {
                    
                    cnt++;
                }
                else {
                    break;
                }
            }
        }
        return cnt;
    }
};
