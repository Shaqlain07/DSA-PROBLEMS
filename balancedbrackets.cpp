// Balanced brackets
#include<iostream>
#include<stack>
using namespace std;

bool balancedbrackets(string str) {
    stack<char> st;

    for(int i=0;i<str.length();i++) {
        char ch=str[i];
        if(st.empty()) {
            st.push(ch);
        }
        else if((ch==')'&& st.top()=='(')||
                (ch=='}'&& st.top()=='{') ||
                (ch==']'&& st.top()=='[')) {
                    st.pop();
                }
        else{
            st.push(ch);
        }                
    }
    if(st.empty()) {
        return true;
    }
    return false;
}

int main() {
    string exp="{()}[]";
    if(balancedbrackets(exp)) {
        cout<<"Brackets are balanced!"<<endl;
    }
    else{
        cout<<"Brackets are not balanced!"<<endl;
    }
    return 0;
}