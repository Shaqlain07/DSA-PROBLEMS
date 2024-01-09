class Solution {
public:
    bool check(vector<int> &nums,int mid, int p) {
        int cnt=0;
        int i=0;
        while(i<nums.size()-1) {
            if(abs(nums[i]-nums[i+1])<=mid) {
                cnt++;
                i+=2;
            }
            else {
                i++;
            }
        }
        if(cnt>=p) return true;
        return false;
            
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        //we r sorting since min diff will be adjacent element
        sort(nums.begin(),nums.end());
        // we are doing bs on all min diff
        int l=0;
        int r=nums[n-1]-nums[0];
        int result=0;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(check(nums,mid,p)) {
                result=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return result;
    }
};
