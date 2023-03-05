class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> temp;
        for(int i=0;i<profits.size();i++) {
            int j=i;
            temp.push_back({capital[i],profits[i]});
        }
        sort(temp.begin(),temp.end());
        priority_queue<int> mxpq;
        int i=0;
        while(k) {
            while(i<temp.size() && temp[i].first<=w) {
                mxpq.push(temp[i].second);
                i++;
            }
            if(!mxpq.empty()) {
                w+=mxpq.top();
                mxpq.pop();
            }
            k--;
        }
        return w;
    }
};
