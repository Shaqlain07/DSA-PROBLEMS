class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int steps=1; // no of boxes in 1 iteration
        int dir=0; // tells about the direction
        int vis=1; // no of boxes visited
        int total=rows*cols; // total no of boxes to visit
        res.push_back({rStart, cStart});
        while(vis<total) {
            if(dir==0) { // left to right
                // iterate it on this direction
                for(int i=0;i<steps && vis<total;i++) {
                    cStart+=1;
                    // make sure cStart is in boundary
                    if(cStart>=0 && cStart<cols && rStart>=0 && rStart<rows) {
                        res.push_back({rStart,cStart});
                        vis++;
                    } 
                }
            }
            else if(dir==1) { // top to bottom
                for(int i=0;i<steps && vis<total;i++) {
                    rStart+=1;
                    if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) {
                        res.push_back({rStart,cStart});
                        vis++;
                    }
                }
            }
            else if(dir==2) { // right to left
                for(int i=0;i<steps && vis<total;i++) {
                    cStart-=1;
                    if(cStart>=0 && cStart<cols && rStart>=0 && rStart<rows) {
                        res.push_back({rStart,cStart});
                        vis++;
                    }
                }
            }
            else { // bottom to top
                for(int i=0;i<steps && vis<total;i++) {
                    //rStart+=1;
                    
                        rStart-=1;
                        if(cStart>=0 && cStart<cols && rStart>=0 && rStart<rows) {
                            res.push_back({rStart, cStart});
                            vis++;
                        }
                    
                }
            }
            if(dir==1 || dir==3) steps++;
            dir=(dir+1)%4;
        }
        return res;
    }
};
