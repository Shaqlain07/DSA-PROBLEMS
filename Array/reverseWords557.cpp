class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++) {
            if(s[i]!=' ') {
                
                st.push(s[i]);
            }
            else {//got space
                while(!st.empty()) {
                    ans+=st.top();
                    st.pop();
                }
                ans+=" ";
            }
        }
        //for last word since we will not get space for that
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
