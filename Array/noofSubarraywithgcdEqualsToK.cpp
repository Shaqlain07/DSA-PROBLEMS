class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++) {
            int gcd=nums[i];
            for(int j=i;j<nums.size();j++) {
                gcd=__gcd(gcd,nums[j]);
                
                if(gcd==k) {
                    count++;
                }
            }
        }
        return count;
    }
};
