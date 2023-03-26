class Solution {
public:
    string convert(string s, int numRows) {
        //edge case
        if(numRows==1) return s;
        int n=int(s.size());
        
        int section=ceil(n/(2*numRows-2.0));
        int numCol=section*(numRows-1);
        //2d vector to put the char in zig-zag
        vector<vector<char>> v(numRows,vector<char>(numCol,' '));
        int row=0,col=0;
        int i=0;
        //put the char in zig-zag in vector
        while(i<n) {
            //Move to down
            while(row<numRows && i<n) {
                v[row][col]=s[i];
                row++;
                i++;
            }
            row-=2;
            col++;
            //moving up
            while(row>0 && col<numCol && i<n) {
                v[row][col]=s[i];
                row--;
                col++;
                i++;
            }
        }
        string res;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[0].size();j++) {
                if(v[i][j]!=' ') {
                    res+=v[i][j];
                }
                
            }
        }
        return res;
    }
};
