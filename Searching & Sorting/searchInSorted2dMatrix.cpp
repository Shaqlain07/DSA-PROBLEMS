class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0;
        int j=n-1;
        
        while(i<m && j>=0) {
            int check=matrix[i][j];
            if(check==target) {
                return true;
            }
            else if(target<check) {
                j--;//col decrement
            }
            else {
                i++;//row increment
            }
        }
        return false;
    }
};
