vector<int> productExceptSelf(vector<int>& nums) {
        //most optimal sol.T.C-O(N),S.C-O(1)
        vector<int> res(nums.size());
        //make prefix array
        res[0]=nums[0];
        for(int i=1;i<nums.size();i++) {
            res[i]=res[i-1]*nums[i];
        }
        int prd=nums[nums.size()-1];
        res[nums.size()-1]=res[nums.size()-2];
        for(int i=nums.size()-2;i>0;i--) {
            res[i]=res[i-1]*prd;
            prd*=nums[i];
        }
        res[0]=prd;
        return res;
    }
