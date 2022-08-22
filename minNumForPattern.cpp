// print minimum no for pattern
#include<iostream>
#include<stack>
using namespace std;

void minNumForPattern(string s) {
    string ans; // for storing answer

    stack<int> st; 

    for(int i=1;i<=s.length()+1;i++) {
        st.push(i); // for D always push..and for I push then pop 

        while(i==s.length()+1 || i=='I') {
            ans+=to_string(st.top());
            ans+=" ";
            st.pop();
        }
    }
    cout<<ans<<endl;
}

int main() {
    minNumForPattern("DD");
    minNumForPattern("DIDI");
    minNumForPattern("IIDIDDID");
    minNumForPattern("DDIIDIDD");

    return 0;
}

