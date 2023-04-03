class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        priority_queue<int> pq;//the difference will come at the top
        long long int ans=0;
        for(int i=0;i<r1.size();i++) {
            pq.push(r1[i]-r2[i]);
            ans+=r2[i];//this will give constant r2 all point
        }
        while(k--) {
            ans+=pq.top();
            pq.pop();
        }
        return ans;

    }
};
