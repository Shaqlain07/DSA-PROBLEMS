// score of parenthesis
/* ()=1
   ab=score of a+score of b
   (a)=score of a *2
*/
#include<bits/stdc++.h>
using namespace std;

int scoreParenthesis(string s) {
    stack<string> st; 
    int ans=0; // for final score

    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') {
            st.push("(");
        }
        else { //got closing bracket
            if(st.top()=="(") { //1 valid parenthesis
                st.pop();
                st.push("1");
            }
            else { //got score of inner parenthesis
                int innerscore=0;
                while(st.top()!="(") {
                    innerscore+=stoi(st.top());
                    st.pop();
                }
                st.pop();//pop inner bracket for outer bracket
                st.push(to_string(2*innerscore));
            }
        }
    }
    while(!st.empty()) {
        ans+=stoi(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    string s="(((()()())))";
    cout<<scoreParenthesis(s);

    return 0;
}
   