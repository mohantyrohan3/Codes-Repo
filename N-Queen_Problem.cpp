#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool ispossible(int row,int col,int n){
    
    //checking straight up
    for(int i=row-1;i>=0;i--){
        if(board[i][col]){
            return false;
        }
    }
     // checking upper left diagonal
    for(int i=row-1 ,j=col-1 ; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]){
            return false;
        }
    }
     // checking upper right diagonal
    for(int i=row-1 ,j=col+1 ; i>=0 && j<n ; i--,j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
    
}


void nqueenhelper(int row,int n){
    if(row==n){
        // we have reched the solution print it nad return 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
            return;
    }
    
    for(int j=0;j<n;j++){
        
        if(ispossible(row,j,n)){
            board[row][j]=1;
            nqueenhelper(row+1,n);
            board[row][j]=0; // backtrack the solution
        }
    }
    return;
}




void nqueen(int n){
    memset(board,0,11*11*sizeof(int));
    nqueenhelper(0,n);
}
int main(){
    // write your code here
    int n;
    cin>>n;
    nqueen(n);
    return 0;
}
