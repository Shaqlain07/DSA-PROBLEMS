class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        stack<int> st;
        for(int i=0;i<pattern.size()+1;i++) {
            st.push(i+1);
            //if u got increasing
            if(i==pattern.size()||pattern[i]=='I') {
                //pop until stack is empty
                while(!st.empty()) {
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};
