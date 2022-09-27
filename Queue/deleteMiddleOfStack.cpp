class Solution
{
    public:
    void helper(stack<int>&st,int mid,int len) {
        //base case
        if(mid==len) {
            st.pop();
            return;
        }
        int temp=st.top();
        st.pop();
        helper(st,mid,len+1);
        st.push(temp);//backtrack
        return;
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        
        helper(s,sizeOfStack/2,0);
        
    }
};
