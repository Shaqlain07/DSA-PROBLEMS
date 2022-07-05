// spiral matrix
#include<iostream>
using namespace std;
int main(){
    int arr[5][6]={{1,2,3,4,5,6},
                    {18,19,20,21,22,7},
                    {17,28,29,30,23,8},
                    {16,27,26,25,24,9},
                    {15,14,13,12,11,10}};

    int row_start=0;
    int col_start=0;
    int row_end=4;
    int col_end=5;

    while(row_start<row_end && col_start<col_end){
        // row start
        for(int i=col_start;i<=col_end;i++){
            cout<<arr[i]<<" ";
        }
        row_start--;
        //col end
        for(int i=row_start;i<=row_end;i++){
            cout<<arr[i]<<" ";
        }
        col_end--;
        // row end
        if(row_start<row_end){
            for(int i=col_end;i>=col_start;i--){
                cout<<arr[i]<<" ";
            }
            row_end--;
        }
        // col start
        if(col_start<col_end){
            for(int i=row_end;i>=row_start;i--){
                cout<<arr[i]<<" ";
            }
            col_start++;
        }
    }                
}