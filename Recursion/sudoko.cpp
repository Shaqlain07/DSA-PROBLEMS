// solve a sudoko
#include<iostream>
using namespace std;

// utilaty function to print grid
void print(int grid[9][9]) {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

bool issafe(int grid[9][9],int x,int y,int z) {
    for (int i = 0; i < 9; i++)
    {
        // row check
        if (grid[x][i]==z)
        {
            return false;
        }
        // colomn check
        if (grid[i][y]==z)
        {
            return false;
        }
    }    
        // Matrix check
        int row_start=x-x%3;
        int col_start=y-y%3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               if(grid[i+row_start][j+col_start]=z) {
                   return false;
               }
            }
            
        }    
    return true;
}

bool sudoko(int grid[9][9],int row,int col) {
    if (row==8 && col==9) // base case
    {
        return true;
    }
    // col completes
    if (col==9)
    {
        row++;
        col=0;
    }
    // if grid >0
    if (grid[row][col]>0)
    {
        return sudoko(grid,row,col+1);
    }
    //if grid=0
    for (int i = 1; i <= 9; i++)
    {
        
        if (issafe(grid,row,col,i)) // recursion
        {
            grid[row][col]=i;

            if (sudoko(grid,row,col+1))
            {
                return true;
            }
        }
        grid[row][col]=0;
    }
    return false;           
}

int main() {
    int grid[9][9]={ {3, 1, 6, 5, 7, 8, 4, 9, 2},
                    {5, 2, 9, 1, 3, 4, 7, 6, 8},
                    {4, 8, 7, 6, 2, 9, 5, 3, 1},
                    {2, 6, 3, 0, 1, 5, 9, 8, 7},
                    {9, 7, 4, 8, 6, 0, 1, 2, 5},
                    {8, 5, 1, 7, 9, 2, 6, 4, 3},
                    {1, 3, 8, 0, 4, 7, 2, 0, 6},
                    {6, 9, 2, 3, 5, 1, 8, 7, 4},
                    {7, 4, 5, 0, 8, 6, 3, 1, 0} };

    if(sudoko(grid,0,0)){
        print(grid);
    } 
    else {
        cout<<"No result found!";
    }

    return 0;
}