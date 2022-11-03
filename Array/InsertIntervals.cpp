class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++) {
            if(newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                while(i!=intervals.size()) {
                        ans.push_back(intervals[i]);
                        i++;
                    }
                return ans;
            }
            else if(newInterval[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
            }
            else {//overlapping with ith index
                newInterval={min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])};
                
            }
                                     
        
    }
        ans.push_back(newInterval);
        return ans;
                                     }
};
