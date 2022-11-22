class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int s=0;
        int e=nums.size()-1;
        int first=-1;
        int last=-1;
        while(s<=e) {
            int mid=(s+e)/2;
            if(nums[mid]==target) {
                first=mid;
                e=mid-1;//if u got mid then find on left side to be the first
            }
            else if(nums[mid]<target) {
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        if(first==-1) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(first);
        }
         s=0;
         e=nums.size()-1;
        while(s<=e) {
            int mid=(s+e)/2;
            if(nums[mid]<=target) {class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int s=0;
        int e=nums.size()-1;
        int first=-1;
        int last=-1;
        while(s<=e) {
            int mid=(s+e)/2;
            if(nums[mid]==target) {
                first=mid;
                e=mid-1;//if u got mid then find on left side to be the first
            }
            else if(nums[mid]<target) {
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        if(first==-1) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(first);
        }
         s=0;
         e=nums.size()-1;
        while(s<=e) {
            int mid=(s+e)/2;
            if(nums[mid]<=target) {
                if(nums[mid]==target){
                    last=mid;
                }
                s=mid+1;//if u got mid then find on right side to be the last
            }
            else {
                e=mid-1;
            }
        }
        if(last==-1) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(last);
        }
        return ans;
    }
};
                if(nums[mid]==target){
                    last=mid;
                }
                s=mid+1;//if u got mid then find on right side to be the last
            }
            else {
                e=mid-1;
            }
        }
        if(last==-1) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(last);
        }
        return ans;
    }
};
