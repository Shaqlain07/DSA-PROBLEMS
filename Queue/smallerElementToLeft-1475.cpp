class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n=prices.size();
        st.push(prices[n-1]);
        vector<int> ans(n);//for putting ans
        ans[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--) {
            while(st.size()>0 && prices[i]<st.top()){//pop until u find smallest element to right
                st.pop();
            }
            if(st.empty()) {//stack is empty means no element is smaller to right
                ans[i]=prices[i];
            }
            else {//u find smaller to right
                ans[i]=prices[i]-st.top();
            }
            st.push(prices[i]);
        }
        return ans;
    }
};
