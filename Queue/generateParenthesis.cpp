class Solution {
public:
    bool valid(vector<char> curr) {
        stack<char> st;
        for(int i=0;i<curr.size();i++) {
            if(curr[i]=='(') {
                st.push('(');
            }
            else {
                if(st.empty()) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
    void solve(int i,vector<string> &res,vector<char> curr) {
        if(i==curr.size()) {
            if(valid(curr)){
                string s(curr.begin(),curr.end());
                res.push_back(s);
            }
            return;
        }
        curr[i]='(';
        solve(i+1,res,curr);
        curr[i]=')';
        solve(i+1,res,curr);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> curr(2*n);
        solve(0,res,curr);
        return res;
    }
};
