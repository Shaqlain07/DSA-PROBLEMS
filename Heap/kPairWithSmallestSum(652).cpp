class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        typedef pair<int,pair<int,int>> pi;
        priority_queue<pi> mnpq;//heap for min element
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                int sum=nums1[i]+nums2[j];
                if(mnpq.size()<k) {
                    mnpq.push({sum,{nums1[i],nums2[j]}});
                }
                else {
                    if(sum<mnpq.top().first) {
                        mnpq.pop();
                        mnpq.push({sum,{nums1[i],nums2[j]}});
                    }
                    else {
                        break;
                    }
                }
            }
        }
        while(!mnpq.empty()) {
            res.push_back({mnpq.top().second.first,mnpq.top().second.second});
            mnpq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
