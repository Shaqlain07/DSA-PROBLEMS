class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        vector<int> res(obstacles.size());
        lis.push_back(obstacles[0]);
        res[0]=1;
        for(int i=1;i<obstacles.size();i++) {
            if(obstacles[i]>=lis.back()) {
                lis.push_back(obstacles[i]);
                res[i]=lis.size();
            }
            else {
                int idx=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
                lis[idx]=obstacles[i];
                res[i]=idx+1;
            }
        }
        return res;
    }
};
