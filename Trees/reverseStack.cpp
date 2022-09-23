class Solution{
public:
    void insertAtBottom(stack<int> &st,int ele) {
        //base case
        if(st.empty()) {
            st.push(ele);
            return;
        }
        int temp=st.top();
        st.pop();
        insertAtBottom(st,ele);
        st.push(temp);
    }
    void reverse(stack<int> &st) {
        //base case
        if(st.size()==1) {
            return;
        }
        int temp=st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st,temp);
        
        return;
    }
    
    stack<int> Reverse(stack<int> St){
        reverse(St);
        return St;
    }
};
