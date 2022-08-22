//count no of required parenthesis to make string valid
#include<bits/stdc++.h>
using namespace std;

int countParenthesis(string s) {
    stack<char> st;
    int count=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') {
            st.push(s[i]);
        }
        else {
            if(st.empty()) {
                count++;
            }
            else { //stack is not empty and it has ( bracket
                st.pop();
            }
        }
    }
    return count+st.size();
}

int main() {
    string s="(())))((";
    cout<<countParenthesis(s);

}