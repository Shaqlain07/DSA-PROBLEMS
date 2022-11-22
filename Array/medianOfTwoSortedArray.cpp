class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        double ans=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int> v;
        while(i!=nums1.size() && j!=nums2.size()) {
            if(nums1[i]<=nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            }
            else {
                v.push_back(nums2[j]);
                j++;
            }
        }
        if(i==nums1.size()) {//1st vector is over
            while(j!=nums2.size()) {
                v.push_back(nums2[j]);
                j++;
            }
        }
        else {
            while(i!=nums1.size()) {
                v.push_back(nums1[i]);
                i++;
            }
        }
        //Now,we merge the sorted array..we have to find the median
        if((m+n)%2 != 0) ans = v[(m+n)/2];
        else ans = (v[(m+n)/2] + v[(m+n)/2-1])/2.0;
        return ans;
            
        
    }
};
