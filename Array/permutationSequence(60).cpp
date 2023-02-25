class Solution {
public:
    string getPermutation(int n, int k) {
        string nums="";
        for(int i=1;i<=n;i++) {
            nums+=to_string(i);
        }
        while(k>1) {
        //find an element which is smaller than its next element from behind
        int idx;
        for(int i=nums.size()-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                idx=i;
                break;
            }
        }
        if(idx<0) {
            reverse(nums.begin(),nums.end());
        }
        else {
            int idx2;
            for(int i=nums.size()-1;i>=0;i--) {
                if(nums[idx]<nums[i]) {
                    idx2=i;
                    break;
                }
            }
            swap(nums[idx],nums[idx2]);
            sort(nums.begin()+idx+1,nums.end());
        k--;
        }
        }
        return nums;
    }
};
