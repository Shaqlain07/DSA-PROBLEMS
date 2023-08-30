class Solution {
public:
	string decodeString(string s) {
		// Your code goes here
        stack<string> st;
        int currN=0;
        string currS="";
        for(int i=0;i<s.length();i++) {
            if(s[i]>='0' && s[i]<='9') {
                currN=currN*10+(s[i]-48);
            }
            else if(s[i]>='a' && s[i]<='z') {
                currS+=s[i];
            }
            else if(s[i]=='[') {
                //push string
                st.push(currS);
                //push int
                st.push(to_string(currN));
                currN=0;
                currS="";
            }
            else {
                int prevN=stoi(st.top());
                st.pop();
                string prevS=st.top();
                st.pop();
                string temp="";
                
                while(prevN) {
                    temp+=currS;
                    prevN--;
                }
                currS=prevS+temp;
            }
        }
        return currS;
	}
};
