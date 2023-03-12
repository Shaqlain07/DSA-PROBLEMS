class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> preSum(height.size(),0);
        vector<int> SufSum(height.size(),0);
        preSum[0]=height[0];
        //left most greatest element for every index
        for(int i=1;i<height.size();i++) {
            preSum[i]=max(height[i],preSum[i-1]);
        }
        SufSum[height.size()-1]=height[height.size()-1];
        //greatest element to right
        for(int i=height.size()-2;i>=0;i--) {
            SufSum[i]=max(height[i],SufSum[i+1]);
        }
        int res=0;
        for(int i=0;i<height.size();i++) {
            int unit=min(SufSum[i],preSum[i])-height[i];
            if(unit>0) res+=unit;
        }
        return res;
    }
};
