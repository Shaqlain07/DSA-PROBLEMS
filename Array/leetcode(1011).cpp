class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);

        while(l<r) {
            int mid=l+(r-l)/2;
            //now,estimulate on vector to check for mid as weight of container
            int currD=1;
            int sum=0;
            for(int i=0;i<weights.size();i++) {
                sum+=weights[i];
                if(sum>mid) {
                    currD++;
                    sum=weights[i];
                }
                if(currD>days) break;
            }
            if(currD>days) {
                l=mid+1;
            }
            else {
                r=mid;
            }
        }
        return r;
    }
};
