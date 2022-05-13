#include<bits/stdc++.h>
using namespace std;

void print(int **solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
}

void mazehelp(int maze[][20] , int**solution , int x, int y , int n){
    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        print(solution,n);
        return;
    }
    
    if(x<0 || x>=n || y<0 || y>=n || maze[x][y]==0 || solution[x][y] ==1 ){
        return;
    }
    solution[x][y]=1;
    mazehelp(maze,solution,x-1,y,n);
    mazehelp(maze,solution,x+1,y,n);
    mazehelp(maze,solution,x,y+1,n);
    mazehelp(maze,solution,x,y-1,n);
    solution[x][y]=0;
}

void Maze(int maze[][20],int n){
    int **solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n];
        for(int j=0;j<n;j++){
            solution[i][j]=0;
        }
    }
    
    mazehelp(maze,solution,0,0 , n);
    
}



int main() {
    int maze[20][20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            }
    }
    Maze(maze,n);
    
	return 0;
}