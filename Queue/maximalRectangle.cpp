class Solution {
public:
    vector<int> smallerRight(vector<int> nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;

        st.push(n-1);
        ans[n-1]=n;

        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && nums[i]<=nums[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i]=n;
            }
            else {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> smallerLeft(vector<int> nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0;i<n;i++) {
            while(!st.empty() && nums[i]<=nums[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i]=-1;
            }
            else {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int histogram(vector<int> nums) {
        int n=nums.size();
        vector<int> smallL=smallerLeft(nums);
        vector<int> smallR=smallerRight(nums);
        //width & area
        vector<int> wd(n);
        vector<int> area(n);
        for(int i=0;i<n;i++) {
            wd[i]=abs(smallR[i]-smallL[i])-1;
            area[i]=wd[i]*nums[i];
        }
        int ans=*max_element(area.begin(),area.end());
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> nums(col,0);
        int ans=0,x;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j]=='0') {
                    nums[j]=0;
                }
                else {
                    nums[j]++;
                }
            }
            x=histogram(nums);
            if(x>ans) {
                ans=x;
            }
        }
        return ans;
        
    }
};
