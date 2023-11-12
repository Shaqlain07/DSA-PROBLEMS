class Solution {
public:
    string removeKdigits(string num, int k) {
        //Intitution
        //we have to remove first element which is diping(greatest no)
        //we can use stack to store it
        stack<char> st;
        for(int i=0;i<num.size();i++) {
            if(st.empty()) st.push(num[i]);
            else {
                while(k!=0 && !st.empty() && st.top()>num[i]) {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        } 
        while(k!=0 && !st.empty()) {
            st.pop();
            k--;
        }
        //if(st.empty()) return "0";
        string ans="";
        while(!st.empty()) {
            int top=st.top();
            st.pop();
            ans+=top;
        }
        
        reverse(ans.begin(),ans.end());
        while(ans[0]=='0') {
            ans.erase(ans.begin()+0);
        }
        if(ans=="") return "0";
        return ans;

    }
};
