class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        //It will store the quantity of Champagne 
        double mat[101][101]={0.0};
        //first glass we poured whole of Champagne
        mat[0][0]=poured;
        for(int i=0;i<100;i++) {
            for(int j=0;j<=i;j++) {
                if(mat[i][j]>=1) {
                    mat[i+1][j]+=(mat[i][j]-1)/2.0;
                    mat[i+1][j+1]+=(mat[i][j]-1)/2.0;
                    mat[i][j]=1;
                }
            }
        }
        return mat[query_row][query_glass];

    }
};
