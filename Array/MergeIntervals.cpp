class Solution {
public:
    //fn for putting stack into vector from bottom
    void helper(stack<pair<int,int>> st, vector<vector<int>> &ans) {
        if(st.empty()) {
            return;
        }
        int first=st.top().first;
        int second=st.top().second;
        
        st.pop();
        helper(st,ans);//recursive calling
        
        ans.push_back({first,second});//pushing into ans while backtracking
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>> st;
        vector<vector<int>> ans;
        
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] <= st.top().second) {
                if(intervals[i][0] > st.top().first) {
                    if(intervals[i][1] > st.top().second) {
                        int front=st.top().first;
                        st.pop();
                        st.push({front,intervals[i][1]});
                    }
                }
                else {
                    if(intervals[i][1] > st.top().second) {
                    st.pop();
                    st.push({intervals[i][0],intervals[i][1]});
                    }
                    else {
                        int second=st.top().second;
                        st.pop();
                        st.push({intervals[i][0],second});
                    }
                }
            }
            else {
                st.push({intervals[i][0],intervals[i][1]});
            }
        }
        helper(st,ans);
        return ans;
    }
};
