class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        bool flag=false;
        for(int i=0;i<nums1.size();i++) {
            bool flag=false;
            auto it=find(nums2.begin(),nums2.end(),nums1[i]);
            int j=it-nums2.begin();
            if(j==nums2.size()-1) {
                ans.push_back(-1);
                flag=true;
            }
            int k=j+1;
            while(k!=nums2.size()) {
                if(nums2[j] < nums2[k]) {
                    ans.push_back(nums2[k]);
                    flag=true;
                    break;
                }
                else {
                    k++;
                }
            }
            if(flag==false) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
