class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                st.push("(");//not taking s[i]..it will take as char
            }
            else { // got a closing bracket
                if(st.top()=="(") {
                    st.pop();
                    st.push("1");
                }
                else {//got a integer
                   int temp=0;
                 
                    while(st.top()!="(" && !st.empty()) {
                        temp+=stoi(st.top());
                        st.pop();
                    }
                    st.pop();
                    st.push(to_string(2*temp));//got a ( or stack empty
                }
            }
        }
        int ans=0;
        while(!st.empty()) {
             ans+=stoi(st.top());
            st.pop();
        }
        return ans;
        
    }
};
